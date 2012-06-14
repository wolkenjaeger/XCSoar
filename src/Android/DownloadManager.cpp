/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2012 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include "DownloadManager.hpp"
#include "Net/DownloadManager.hpp"
#include "Context.hpp"
#include "Java/Class.hpp"
#include "Java/String.hpp"
#include "LocalPath.hpp"
#include "OS/FileUtil.hpp"
#include "Util/Macros.hpp"
#include "org_xcsoar_DownloadUtil.h"

#include <algorithm>

#include <windef.h> /* for MAX_PATH */

static AndroidDownloadManager *instance;

static Java::TrivialClass util_class;

static jmethodID enqueue_method;

bool
AndroidDownloadManager::Initialise(JNIEnv *env)
{
  assert(util_class == NULL);
  assert(env != NULL);

  if (!util_class.FindOptional(env, "org/xcsoar/DownloadUtil"))
    return false;

  enqueue_method = env->GetStaticMethodID(util_class, "enqueue",
                                          "(Landroid/app/DownloadManager;"
                                          "Ljava/lang/String;Ljava/lang/String;)J");
  return true;
}

bool
AndroidDownloadManager::IsAvailable()
{
  return util_class.Get() != NULL;
}

AndroidDownloadManager *
AndroidDownloadManager::Create(JNIEnv *env, Context &context)
{
  jobject obj = context.GetSystemService(env, "download");
  if (obj == NULL)
    return NULL;

  instance = new AndroidDownloadManager(env, obj);
  env->DeleteLocalRef(obj);
  return instance;
}

void
AndroidDownloadManager::AddListener(Net::DownloadListener &listener)
{
  ScopeLock protect(mutex);

  assert(std::find(listeners.begin(), listeners.end(),
                   &listener) == listeners.end());

  listeners.push_back(&listener);
}

void
AndroidDownloadManager::RemoveListener(Net::DownloadListener &listener)
{
  ScopeLock protect(mutex);

  auto i = std::find(listeners.begin(), listeners.end(), &listener);
  assert(i != listeners.end());
  listeners.erase(i);
}

void
AndroidDownloadManager::OnDownloadComplete(const char *path_relative,
                                           bool success)
{
  ScopeLock protect(mutex);
  for (auto i = listeners.begin(), end = listeners.end(); i != end; ++i)
    (*i)->OnDownloadComplete(path_relative, success);
}

static bool
EraseSuffix(char *p, const char *suffix)
{
  assert(p != NULL);
  assert(suffix != NULL);

  size_t length = strlen(p);
  size_t suffix_length = strlen(suffix);

  if (length <= suffix_length ||
      memcmp(p + length - suffix_length, suffix, suffix_length) != 0)
    return false;

  p[length - suffix_length] = 0;
  return true;
}

JNIEXPORT void JNICALL
Java_org_xcsoar_DownloadUtil_onDownloadComplete(JNIEnv *env, jclass cls,
                                                jstring j_path,
                                                jboolean success)
{
  if (instance == NULL)
    return;

  char tmp_path[MAX_PATH];
  Java::String::CopyTo(env, j_path, tmp_path, ARRAY_SIZE(tmp_path));

  char final_path[MAX_PATH];
  strcpy(final_path, tmp_path);
  if (!EraseSuffix(final_path, ".tmp"))
    return;

  const char *relative = RelativePath(final_path);
  if (relative == NULL)
    return;

  success = success && File::Replace(tmp_path, final_path);

  instance->OnDownloadComplete(relative, success);
}

void
AndroidDownloadManager::Enqueue(JNIEnv *env, const char *uri,
                                const char *path_relative)
{
  assert(env != NULL);
  assert(uri != NULL);
  assert(path_relative != NULL);

  char tmp_relative[MAX_PATH];
  strcpy(tmp_relative, path_relative);
  strcat(tmp_relative, ".tmp");

  {
    char tmp_absolute[MAX_PATH];
    LocalPath(tmp_absolute, tmp_relative);
    File::Delete(tmp_absolute);
  }

  Java::String j_uri(env, uri);
  Java::String j_path(env, tmp_relative);

  env->CallStaticLongMethod(util_class, enqueue_method,
                            object.Get(), j_uri.Get(),
                            j_path.Get());
}
