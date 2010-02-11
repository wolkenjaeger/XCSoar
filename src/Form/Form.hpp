/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009

	M Roberts (original release)
	Robin Birch <robinb@ruffnready.co.uk>
	Samuel Gisiger <samuel.gisiger@triadis.ch>
	Jeff Goodenough <jeff@enborne.f2s.com>
	Alastair Harrison <aharrison@magic.force9.co.uk>
	Scott Penrose <scottp@dd.com.au>
	John Wharington <jwharington@gmail.com>
	Lars H <lars_hn@hotmail.com>
	Rob Dunning <rob@raspberryridgesheepfarm.com>
	Russell King <rmk@arm.linux.org.uk>
	Paolo Ventafridda <coolwind@email.it>
	Tobias Lohner <tobias@lohner-net.de>
	Mirek Jezek <mjezek@ipplc.cz>
	Max Kellermann <max@duempel.org>
	Tobias Bieniek <tobias.bieniek@gmx.de>

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

#ifndef XCSOAR_FORM_FORM_HPP
#define XCSOAR_FORM_FORM_HPP

#include "Form/Container.hpp"
#include "Dialogs.h"
#include "Util/tstring.hpp"

#include <map>

class SingleWindow;
class PeriodClock;

/**
 * A WndForm represents a Window with a titlebar.
 * It is used to display the XML dialogs and MessageBoxes.
 */
class WndForm: public ContainerControl
{
  struct tstring_less_than {
    bool operator()(const tstring &a, const tstring &b) const
    {
      return a.compare(b) < 0;
    }
  };

  typedef std::map<tstring, Window *, tstring_less_than> name_to_window_t;

public:
  typedef int (*TimerNotifyCallback_t)(WindowControl *Sender);
  typedef bool (*KeyDownNotifyCallback_t)(WindowControl *Sender,
      unsigned key_code);

private:
  /**
   * Mapping of control names to #Window objects.
   */
  name_to_window_t name_to_window;

protected:
  SingleWindow &main_window;
  int mModalResult;
  /** Background color of the titlebar */
  Color mColorTitle;
  /** Font of the titlebar */
  const Font *mhTitleFont;
  /** The ClientWindow */
  ContainerControl *mClientWindow;
  /** Coordinates of the ClientWindow */
  RECT mClientRect;
  /** Coordinates of the titlebar */
  RECT mTitleRect;

  TimerNotifyCallback_t mOnTimerNotify;
  KeyDownNotifyCallback_t mOnKeyDownNotify;

  /**
   * The on_paint event is called when the button needs to be drawn
   * (derived from PaintWindow)
   */
  virtual void on_paint(Canvas &canvas);

  timer_t cbTimerID;

public:
  /**
   * Constructor of the WndForm class
   * @param _main_window
   * @param Caption Titlebar text of the Window
   * @param X x-Coordinate of the Window
   * @param Y y-Coordinate of the Window
   * @param Width Width of the Window
   * @param Height Height of the Window
   */
  WndForm(SingleWindow &_main_window, const TCHAR *Caption,
          int X, int Y, int Width, int Height,
          const WindowStyle style);

  /** Destructor */
  virtual ~WndForm();

  ContainerWindow &GetClientAreaWindow(void);

  /**
   * Adds a #Window to the name-to-window map.
   */
  void AddNamed(const TCHAR *name, Window *window) {
    name_to_window[name] = window;
  }

  /**
   * Finds the ancestor window with the specified name.
   *
   * @param name the name of the #Window that is searched
   * @return the Window, or NULL if not found
   */
  Window *FindByName(const TCHAR *name) {
    return name_to_window[name];
  }

  /**
   * Finds the ancestor window with the specified name.
   *
   * @param name the name of the #Window that is searched
   * @return the Window, or NULL if not found
   */
  virtual const Window *FindByName(const TCHAR *name) const {
    name_to_window_t::const_iterator i = name_to_window.find(name);
    if (i == name_to_window.end())
      return NULL;

    return i->second;
  }

  int GetModalResult(void) { return mModalResult; }
  int SetModalResult(int Value) {
    mModalResult = Value;
    return Value;
  }

  /** Set the font of the titlebar */
  const Font *SetTitleFont(const Font &font);

  int ShowModal(bool bEnableMap);
  int ShowModal(void);

  /** Set the titlebar text */
  void SetCaption(const TCHAR *Value);

  virtual bool on_unhandled_key(unsigned key_code);

  /** from class Window */
  virtual bool on_destroy();
  virtual bool on_timer(timer_t id);

  /** Set the foreground color of the window */
  Color SetForeColor(Color Value);
  /** Set the background color of the window */
  Color SetBackColor(Color Value);
  /** Set the font of the window (not titlebar) */
  const Font *SetFont(const Font &Value);

  void SetKeyDownNotify(KeyDownNotifyCallback_t KeyDownNotify);
  void SetTimerNotify(TimerNotifyCallback_t OnTimerNotify);

private:
  static PeriodClock timeAnyOpenClose; // when any dlg opens or child closes
};

#endif
