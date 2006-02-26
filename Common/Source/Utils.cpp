/*
Copyright_License {

  XCSoar Glide Computer - http://xcsoar.sourceforge.net/
  Copyright (C) 2000 - 2005

  	M Roberts (original release)
	Robin Birch <robinb@ruffnready.co.uk>
	Samuel Gisiger <samuel.gisiger@triadis.ch>
	Jeff Goodenough <jeff@enborne.f2s.com>
	Alastair Harrison <aharrison@magic.force9.co.uk>
	Scott Penrose <scottp@dd.com.au>
	John Wharington <jwharington@bigfoot.com>

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

#include "stdafx.h"

#include "Utils.h"

#include "resource.h"
#include "externs.h"
#include "device.h"
#include "uniqueid.h"
#include "XCSoar.h"
#include "Topology.h"
#include "Units.h"

TCHAR szRegistryKey[] =                TEXT("Software\\MPSR\\XCSoar");
TCHAR *szRegistryDisplayType[] =     { TEXT("Info0"),
				       TEXT("Info1"),
				       TEXT("Info2"),
				       TEXT("Info3"),
				       TEXT("Info4"),
				       TEXT("Info5"),
				       TEXT("Info6"),
				       TEXT("Info7"),
				       TEXT("Info8"),
				       TEXT("Info9")
}; // pL

TCHAR *szRegistryColour[] =     { TEXT("Colour0"),
				  TEXT("Colour1"),
				  TEXT("Colour2"),
				  TEXT("Colour3"),
				  TEXT("Colour4"),
				  TEXT("Colour5"),
				  TEXT("Colour6"),
				  TEXT("Colour7"),
				  TEXT("Colour8"),
				  TEXT("Colour9"),
				  TEXT("Colour10"),
				  TEXT("Colour11"),
				  TEXT("Colour12"),
				  TEXT("Colour13"),
				  TEXT("Colour14")
}; // pL


TCHAR *szRegistryBrush[] =     {  TEXT("Brush0"),
				  TEXT("Brush1"),
				  TEXT("Brush2"),
				  TEXT("Brush3"),
				  TEXT("Brush4"),
				  TEXT("Brush5"),
				  TEXT("Brush6"),
				  TEXT("Brush7"),
				  TEXT("Brush8"),
				  TEXT("Brush9"),
				  TEXT("Brush10"),
				  TEXT("Brush11"),
				  TEXT("Brush12"),
				  TEXT("Brush13"),
				  TEXT("Brush14")
}; // pL


TCHAR szRegistryAirspaceWarning[]= TEXT("AirspaceWarn");
TCHAR szRegistryAirspaceBlackOutline[]= TEXT("AirspaceBlackOutline");
TCHAR szRegistryAltMargin[]=	   TEXT("AltMargin");
TCHAR szRegistryAltMode[]=  TEXT("AltitudeMode");
TCHAR szRegistryAltitudeUnitsValue[] = TEXT("Altitude");
TCHAR szRegistryCircleZoom[]= TEXT("CircleZoom");
TCHAR szRegistryClipAlt[]= TEXT("ClipAlt");
TCHAR szRegistryDisplayText[] = TEXT("DisplayText");
TCHAR szRegistryDisplayUpValue[] = TEXT("DisplayUp");
TCHAR szRegistryDistanceUnitsValue[] = TEXT("Distance");
TCHAR szRegistryDrawTerrain[]= TEXT("DrawTerrain");
TCHAR szRegistryDrawTopology[]= TEXT("DrawTopology");
TCHAR szRegistryFAISector[] = TEXT("FAISector");
TCHAR szRegistryFinalGlideTerrain[]= TEXT("FinalGlideTerrain");
TCHAR szRegistryHomeWaypoint[]= TEXT("HomeWaypoint");
TCHAR szRegistryLiftUnitsValue[] = TEXT("Lift");
TCHAR szRegistryPolarID[] = TEXT("Polar"); // pL
TCHAR szRegistryPort1Index[]= TEXT("PortIndex");
TCHAR szRegistryPort2Index[]= TEXT("Port2Index");
TCHAR szRegistryRegKey[]=				 TEXT("RegKey");
TCHAR szRegistrySafetyAltitudeArrival[] =     TEXT("SafetyAltitudeArrival");
TCHAR szRegistrySafetyAltitudeBreakOff[] =     TEXT("SafetyAltitudeBreakOff");
TCHAR szRegistrySafetyAltitudeTerrain[] =     TEXT("SafetyAltitudeTerrain");
TCHAR szRegistrySafteySpeed[] =          TEXT("SafteySpeed");
TCHAR szRegistrySectorRadius[]=          TEXT("Radius");
TCHAR szRegistrySnailTrail[]=		 TEXT("SnailTrail");
TCHAR szRegistrySpeed1Index[]=		 TEXT("SpeedIndex");
TCHAR szRegistrySpeed2Index[]=		 TEXT("Speed2Index");
TCHAR szRegistrySpeedUnitsValue[] =      TEXT("Speed");
TCHAR szRegistryStartLine[]=		 TEXT("StartLine");
TCHAR szRegistryStartRadius[]=		 TEXT("StartRadius");
TCHAR szRegistryWarningTime[]=		 TEXT("WarnTime");
TCHAR szRegistryAcknowledgementTime[]=	 TEXT("AcknowledgementTime");
TCHAR szRegistryWindUpdateMode[] =       TEXT("WindUpdateMode");
TCHAR szRegistryWindSpeed[] =            TEXT("WindSpeed");
TCHAR szRegistryWindBearing[] =          TEXT("WindBearing");

TCHAR szRegistryAirfieldFile[]=  TEXT("AirfieldFile"); // pL
TCHAR szRegistryAirspaceFile[]=  TEXT("AirspaceFile"); // pL
TCHAR szRegistryAdditionalAirspaceFile[]=  TEXT("AdditionalAirspaceFile"); // pL
TCHAR szRegistryPolarFile[] = TEXT("PolarFile"); // pL
TCHAR szRegistryTerrainFile[]=	 TEXT("TerrainFile"); // pL
TCHAR szRegistryTopologyFile[]=  TEXT("TopologyFile"); // pL
TCHAR szRegistryWayPointFile[]=  TEXT("WPFile"); // pL
TCHAR szRegistryAdditionalWayPointFile[]=  TEXT("AdditionalWPFile"); // pL

TCHAR szRegistryLanguageFile[]=  TEXT("LanguageFile"); // pL
TCHAR szRegistryStatusFile[]=  TEXT("StatusFile"); // pL
TCHAR szRegistryInputFile[]=  TEXT("InputFile"); // pL

TCHAR szRegistryPilotName[]=  TEXT("PilotName");
TCHAR szRegistryAircraftType[]=  TEXT("AircraftType");
TCHAR szRegistryAircraftRego[]=  TEXT("AircraftRego");

TCHAR szRegistrySoundVolume[]=  TEXT("SoundVolume");
TCHAR szRegistrySoundDeadband[]=  TEXT("SoundDeadband");
TCHAR szRegistrySoundAudioVario[]=  TEXT("AudioVario");
TCHAR szRegistrySoundTask[]=  TEXT("SoundTask");
TCHAR szRegistrySoundModes[]=  TEXT("SoundModes");
TCHAR szRegistryNettoSpeed[]= TEXT("NettoSpeed");
TCHAR szRegistryAccelerometerZero[]= TEXT("AccelerometerZero");

TCHAR szRegistryCDICruise[]= TEXT("CDICruise");
TCHAR szRegistryCDICircling[]= TEXT("CDICircling");

TCHAR szRegistryDeviceA[]= TEXT("DeviceA");
TCHAR szRegistryDeviceB[]= TEXT("DeviceB");

TCHAR szRegistryAutoBlank[]= TEXT("AutoBlank");
TCHAR szRegistryVarioGauge[]= TEXT("VarioGauge");

TCHAR szRegistryDebounceTimeout[]= TEXT("DebounceTimeout");

TCHAR szRegistryAppIndFinalGlide[] = TEXT("AppIndFinalGlide");
TCHAR szRegistryAppIndLandable[] = TEXT("AppIndLandable");
TCHAR szRegistryAppInverseInfoBox[] = TEXT("AppInverseInfoBox");
TCHAR szRegistryAppGaugeVarioSpeedToFly[] = TEXT("AppGaugeVarioSpeedToFly");
TCHAR szRegistryAppGaugeVarioAvgText[] = TEXT("AppGaugeVarioAvgText");
TCHAR szRegistryAppGaugeVarioMc[] = TEXT("AppGaugeVarioMc");
TCHAR szRegistryAppGaugeVarioBugs[] = TEXT("AppGaugeVarioBugs");
TCHAR szRegistryAppGaugeVarioBallast[] = TEXT("AppGaugeVarioBallast");

TCHAR szRegistryAutoAdvance[] = TEXT("AutoAdvance");
TCHAR szRegistryUTCOffset[] = TEXT("UTCOffset");

int UTCOffset = 0; // used for Altair

static double SINETABLE[910];
static float FSINETABLE[910];

void StoreType(int Index,int InfoType)
{
  SetToRegistry(szRegistryDisplayType[Index],(DWORD)InfoType);
}




// This function checks to see if Final Glide mode infoboxes have been
// initialised.  If all are zero, then the current configuration was
// using XCSoarV3 infoboxes, so copy settings from cruise mode.
void CheckInfoTypes() {
  int i;
  char iszero=0;
  for (i=0; i<MAXINFOWINDOWS; i++) {
    iszero |= (InfoType[i] >> 16) & 0xff;
  }
  if (iszero==0) {
    for (i=0; i<MAXINFOWINDOWS; i++) {
      InfoType[i] += (InfoType[i] & 0xff)<<16;
      StoreType(i,InfoType[i]);
    }
  }
}


void ResetInfoBoxes(void) {
  InfoType[0] = 921102;
  InfoType[1] = 725525;
  InfoType[2] = 262144;
  InfoType[3] = 74518;
  InfoType[4] = 657930;
  InfoType[5] = 2236963;
  InfoType[6] = 394758;
  InfoType[7] = 1644825;
}

void ReadRegistrySettings(void)
{
  DWORD Speed = 0;
  DWORD Distance = 0;
  DWORD Lift = 0;
  DWORD Altitude = 0;
  DWORD DisplayUp = 0;
  DWORD Temp = 0;
  int i;

  GetFromRegistry(szRegistrySpeedUnitsValue,&Speed);
  switch(Speed)
    {
    case 0 :
      SPEEDMODIFY = TOMPH;
      break;
    case 1 :
      SPEEDMODIFY = TOKNOTS;
      break;
    case 2 :
      SPEEDMODIFY = TOKPH;
      break;
    }

  GetFromRegistry(szRegistryDistanceUnitsValue,&Distance);
  switch(Distance)
    {
    case 0 : DISTANCEMODIFY = TOMILES; break;
    case 1 : DISTANCEMODIFY = TONAUTICALMILES; break;
    case 2 : DISTANCEMODIFY = TOKILOMETER; break;
    }

  GetFromRegistry(szRegistryAltitudeUnitsValue,&Altitude);
  switch(Altitude)
    {
    case 0 : ALTITUDEMODIFY = TOFEET; break;
    case 1 : ALTITUDEMODIFY = TOMETER; break;
    }

  GetFromRegistry(szRegistryLiftUnitsValue,&Lift);
  switch(Lift)
    {
    case 0 : LIFTMODIFY = TOKNOTS; break;
    case 1 : LIFTMODIFY = TOMETER; break;
    }

  Units::NotifyUnitChanged();

  for (i=0;i<MAXINFOWINDOWS;i++)
    {
      if(GetFromRegistry(szRegistryDisplayType[i],&Altitude) == ERROR_SUCCESS )
	InfoType[i] = Altitude;
    }

  // check against V3 infotypes
  CheckInfoTypes();

  GetFromRegistry(szRegistryDisplayUpValue,&Temp);
  switch(Temp)
    {
    case TRACKUP : DisplayOrientation = TRACKUP; break;
    case NORTHUP : DisplayOrientation = NORTHUP;break;
    case NORTHCIRCLE : DisplayOrientation = NORTHCIRCLE;break;
    case TRACKCIRCLE : DisplayOrientation = TRACKCIRCLE;break;
    }

  GetFromRegistry(szRegistryDisplayText,&Temp);
  switch(Temp)
    {
    case 0 : DisplayTextType = DISPLAYNAME; break;
    case 1 : DisplayTextType = DISPLAYNUMBER;break;
    case 2 : DisplayTextType = DISPLAYFIRSTFIVE; break;
    case 3 : DisplayTextType = DISPLAYNONE;break;
    case 4 : DisplayTextType = DISPLAYFIRSTTHREE; break;
    case 5 : DisplayTextType = DISPLAYNAMEIFINTASK; break;
    }

  if(GetFromRegistry(szRegistryAltMode,&Temp)==ERROR_SUCCESS)
    AltitudeMode = Temp;

  if(GetFromRegistry(szRegistryClipAlt,&Temp)==ERROR_SUCCESS)
    ClipAltitude = Temp;

  if(GetFromRegistry(szRegistryAltMargin,&Temp)==ERROR_SUCCESS)
    AltWarningMargin = Temp;


  GetFromRegistry(szRegistrySafetyAltitudeArrival,&Temp);
  if(Temp != 0)
    SAFETYALTITUDEARRIVAL = (double)Temp;

  GetFromRegistry(szRegistrySafetyAltitudeBreakOff,&Temp);
  if(Temp != 0)
    SAFETYALTITUDEBREAKOFF = (double)Temp;

  GetFromRegistry(szRegistrySafetyAltitudeTerrain,&Temp);
  if(Temp != 0)
    SAFETYALTITUDETERRAIN = (double)Temp;

  GetFromRegistry(szRegistrySafteySpeed,&Temp);
  if(Temp != 0)
    SAFTEYSPEED = (double)Temp;

  Temp = 0;
  GetFromRegistry(szRegistryFAISector,&Temp);
  FAISector = Temp;

  GetFromRegistry(szRegistrySectorRadius,&SectorRadius);

  GetFromRegistry(szRegistryPolarID,&Temp); POLARID = (int)Temp;

  GetRegistryString(szRegistryRegKey, strRegKey, 65);

  for(i=0;i<AIRSPACECLASSCOUNT;i++)
    {
      if(GetFromRegistry(szRegistryBrush[i],&Temp)==ERROR_SUCCESS)
        MapWindow::iAirspaceBrush[i] =			(int)Temp;
      else
        MapWindow::iAirspaceBrush[i] =			0;

      if(GetFromRegistry(szRegistryColour[i],&Temp)==ERROR_SUCCESS)
        MapWindow::iAirspaceColour[i] =			(int)Temp;
      else
        MapWindow::iAirspaceColour[i] =			0;

      if (MapWindow::iAirspaceColour[i]>= NUMAIRSPACECOLORS) {
        MapWindow::iAirspaceColour[i]= 0;
      }

      if (MapWindow::iAirspaceBrush[i]>= NUMAIRSPACEBRUSHES) {
        MapWindow::iAirspaceBrush[i]= 0;
      }

    }

  GetFromRegistry(szRegistryAirspaceBlackOutline,&Temp);
  MapWindow::bAirspaceBlackOutline = (Temp == 1);

  GetFromRegistry(szRegistrySnailTrail,&Temp);
  TrailActive = Temp;

  GetFromRegistry(szRegistryDrawTopology,&Temp);
  EnableTopology = (Temp == 1);

  GetFromRegistry(szRegistryDrawTerrain,&Temp);
  EnableTerrain = (Temp == 1);

  GetFromRegistry(szRegistryFinalGlideTerrain,&Temp);
  FinalGlideTerrain = (Temp == 1);

  GetFromRegistry(szRegistryCircleZoom,&Temp);
  CircleZoom = (Temp == 1);

  GetFromRegistry(szRegistryWindUpdateMode,&Temp);
  WindUpdateMode = Temp;

  GetFromRegistry(szRegistryHomeWaypoint,&Temp);
  HomeWaypoint = Temp;

  Temp = 1;
  GetFromRegistry(szRegistryStartLine,&Temp);
  StartLine = Temp;

  Temp = 1000;
  GetFromRegistry(szRegistryStartRadius,&Temp);
  StartRadius = Temp;

  Temp = 0;
  GetFromRegistry(szRegistryAirspaceWarning,&Temp);
  AIRSPACEWARNINGS = Temp;

  Temp = 30;
  GetFromRegistry(szRegistryWarningTime,&Temp);
  WarningTime = Temp;

  Temp = 30;
  GetFromRegistry(szRegistryAcknowledgementTime,&Temp);
  AcknowledgementTime = Temp;

  Temp = 80;
  GetFromRegistry(szRegistrySoundVolume,&Temp);
  SoundVolume = Temp;

  Temp = 4;
  GetFromRegistry(szRegistrySoundDeadband,&Temp);
  SoundDeadband = Temp;

  Temp = 1;
  GetFromRegistry(szRegistrySoundAudioVario,&Temp);
  EnableSoundVario = (Temp == 1);

  Temp = 1;
  GetFromRegistry(szRegistrySoundTask,&Temp);
  EnableSoundTask = (Temp == 1);

  Temp = 1;
  GetFromRegistry(szRegistrySoundModes,&Temp);
  EnableSoundModes = (Temp == 1);

  Temp = 500;
  GetFromRegistry(szRegistryNettoSpeed,&Temp);
  NettoSpeed = Temp;

  Temp = 0;
  GetFromRegistry(szRegistryCDICruise,&Temp);
  EnableCDICruise = (Temp == 1);

  Temp = 0;
  GetFromRegistry(szRegistryCDICircling,&Temp);
  EnableCDICircling = (Temp == 1);

  Temp = 0;
  GetFromRegistry(szRegistryAutoBlank,&Temp);
  EnableAutoBlank = (Temp == 1);

  Temp = 0;
  GetFromRegistry(szRegistryVarioGauge,&Temp);
  EnableVarioGauge = (Temp == 1);

  Temp = 0;
  GetFromRegistry(szRegistryDebounceTimeout, &Temp);
  debounceTimeout = Temp;
  if (debounceTimeout==0) {
    // reasonable default for debounce
    debounceTimeout = 250;
    SetToRegistry(szRegistryDebounceTimeout, debounceTimeout);
  }

  Temp = 100;
  GetFromRegistry(szRegistryAccelerometerZero,&Temp);
  AccelerometerZero = Temp;
  if (AccelerometerZero==0.0) {
    AccelerometerZero= 100.0;
    Temp = 100;
    SetToRegistry(szRegistryAccelerometerZero,Temp);
  }

  // new appearance variables

  Temp = Appearance.IndFinalGlide;
  GetFromRegistry(szRegistryAppIndFinalGlide, &Temp);
  Appearance.IndFinalGlide = (IndFinalGlide_t)Temp;

  Temp = Appearance.IndLandable;
  GetFromRegistry(szRegistryAppIndLandable, &Temp);
  Appearance.IndLandable = (IndLandable_t)Temp;

  Temp = Appearance.InverseInfoBox;
  GetFromRegistry(szRegistryAppInverseInfoBox, &Temp);
  Appearance.InverseInfoBox = (Temp != 0);

  Temp = Appearance.GaugeVarioSpeedToFly;
  GetFromRegistry(szRegistryAppGaugeVarioSpeedToFly, &Temp);
  Appearance.GaugeVarioSpeedToFly = (Temp != 0);

  Temp = Appearance.GaugeVarioAvgText;
  GetFromRegistry(szRegistryAppGaugeVarioAvgText, &Temp);
  Appearance.GaugeVarioAvgText = (Temp != 0);

  Temp = Appearance.GaugeVarioMc;
  GetFromRegistry(szRegistryAppGaugeVarioMc, &Temp);
  Appearance.GaugeVarioMc = (Temp != 0);

  Temp = Appearance.GaugeVarioBugs;
  GetFromRegistry(szRegistryAppGaugeVarioBugs, &Temp);
  Appearance.GaugeVarioBugs = (Temp != 0);

  Temp = Appearance.GaugeVarioBallast;
  GetFromRegistry(szRegistryAppGaugeVarioBallast, &Temp);
  Appearance.GaugeVarioBallast = (Temp != 0);

  Temp = 1;
  GetFromRegistry(szRegistryAutoAdvance,&Temp);
  AutoAdvance = (Temp == 1);

  Temp = 0;
  GetFromRegistry(szRegistryUTCOffset,&Temp);
  UTCOffset = Temp;
  if (UTCOffset>12) {
    UTCOffset-= 24;
  }

}


// NOTE: all registry variables are unsigned!
//
BOOL GetFromRegistry(const TCHAR *szRegValue, DWORD *pPos)
{
  HKEY    hKey;
  DWORD    dwSize, dwType;
  long    hRes;
  DWORD defaultVal;

  *pPos= 0;
  hRes = RegOpenKeyEx(HKEY_CURRENT_USER, szRegistryKey, 0, KEY_ALL_ACCESS, &hKey);
  if (hRes != ERROR_SUCCESS)
    {
      RegCloseKey(hKey);
      return hRes;
    }

  defaultVal = *pPos;
  dwSize = sizeof(DWORD);
  hRes = RegQueryValueEx(hKey, szRegValue, 0, &dwType, (LPBYTE)pPos, &dwSize);
  if (hRes != ERROR_SUCCESS) {
    *pPos = defaultVal;
  }

  RegCloseKey(hKey);
  return hRes;
}


// Implement your code to save value to the registry

HRESULT SetToRegistry(const TCHAR *szRegValue, DWORD Pos)
{
  HKEY    hKey;
  DWORD    Disp;
  HRESULT hRes;

  hRes = RegCreateKeyEx(HKEY_CURRENT_USER, szRegistryKey, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, &Disp);
  if (hRes != ERROR_SUCCESS)
    {
      return FALSE;
    }

  hRes = RegSetValueEx(hKey, szRegValue,0,REG_DWORD, (LPBYTE)&Pos, sizeof(DWORD));
  RegCloseKey(hKey);

  return hRes;
}

// Set bool value to registry as 1 or 0 - JG
HRESULT SetToRegistry(const TCHAR *szRegValue, bool bVal)
{
	return SetToRegistry(szRegValue, bVal ? DWORD(1) : DWORD(0));
}

// Set int value to registry - JG
HRESULT SetToRegistry(const TCHAR *szRegValue, int nVal)
{
	return SetToRegistry(szRegValue, DWORD(nVal));
}

BOOL GetRegistryString(const TCHAR *szRegValue, TCHAR *pPos, DWORD dwSize)
{
  HKEY    hKey;
  DWORD   dwType = REG_SZ;
  long    hRes;
  unsigned int i;
  for (i=0; i<dwSize; i++) {
    pPos[i]=0;
  }

  pPos[0]= '\0';
  hRes = RegOpenKeyEx(HKEY_CURRENT_USER, szRegistryKey, 0, KEY_ALL_ACCESS, &hKey);
  if (hRes != ERROR_SUCCESS)
    {
      RegCloseKey(hKey);
      return FALSE;
    }

  hRes = RegQueryValueEx(hKey, szRegValue, 0, &dwType, (LPBYTE)pPos, &dwSize);
  RegCloseKey(hKey);
  return hRes;
}

HRESULT SetRegistryString(const TCHAR *szRegValue, TCHAR *Pos)
{
  HKEY    hKey;
  DWORD    Disp;
  HRESULT hRes;

  hRes = RegCreateKeyEx(HKEY_CURRENT_USER, szRegistryKey, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, &Disp);
  if (hRes != ERROR_SUCCESS)
    {
      return FALSE;
    }

  hRes = RegSetValueEx(hKey, szRegValue,0,REG_SZ, (LPBYTE)Pos, _tcslen(Pos)*sizeof(TCHAR));
  RegCloseKey(hKey);

  return hRes;
}

void ReadPort1Settings(DWORD *PortIndex, DWORD *SpeedIndex)
{
  DWORD Temp;

  if(GetFromRegistry(szRegistryPort1Index,&Temp)==ERROR_SUCCESS)
    (*PortIndex) = Temp;

  if(GetFromRegistry(szRegistrySpeed1Index,&Temp)==ERROR_SUCCESS)
    (*SpeedIndex) = Temp;
}


void WritePort1Settings(DWORD PortIndex, DWORD SpeedIndex)
{
  SetToRegistry(szRegistryPort1Index, PortIndex);
  SetToRegistry(szRegistrySpeed1Index, SpeedIndex);
}

void ReadPort2Settings(DWORD *PortIndex, DWORD *SpeedIndex)
{
  DWORD Temp;

  if(GetFromRegistry(szRegistryPort2Index,&Temp)==ERROR_SUCCESS)
    (*PortIndex) = Temp;

  if(GetFromRegistry(szRegistrySpeed2Index,&Temp)==ERROR_SUCCESS)
    (*SpeedIndex) = Temp;
}


void WritePort2Settings(DWORD PortIndex, DWORD SpeedIndex)
{
  SetToRegistry(szRegistryPort2Index, PortIndex);
  SetToRegistry(szRegistrySpeed2Index, SpeedIndex);
}

void rotate(double *xin, double *yin, double angle)
{
  static double x,y;
  static double xout, yout;
  static double lastangle = 0;
  static double cost=1,sint=0;

  if(angle != lastangle)
    {
      lastangle = angle;
      cost = (double)fastcosine(angle);
      sint = (double)fastsine(angle);
    }

  x = *xin; y = *yin;
  xout = x*cost - y*sint;
  yout = y*cost + x*sint;
  *xin = xout;
  *yin = yout;
}


void frotate(float *xin, float *yin, float angle)
{
  static float x,y;
  static float xout, yout;
  static float lastangle = 0;
  static float cost=1,sint=0;

  if(angle != lastangle)
    {
      lastangle = angle;
      cost = (float)fastcosine(angle);
      sint = (float)fastsine(angle);
    }

  x = *xin; y = *yin;
  xout = x*cost - y*sint;
  yout = y*cost + x*sint;
  *xin = xout;
  *yin = yout;
}


double Distance(double lat1, double lon1, double lat2, double lon2)
{
  double distance, dTmp;

  lat1 *= DEG_TO_RAD;
  lat2 *= DEG_TO_RAD;
  lon1 *= DEG_TO_RAD;
  lon2 *= DEG_TO_RAD;

  dTmp =  sin(lat1)*sin(lat2) +
			cos(lat1)*cos(lat2) * cos(lon1-lon2);

  if (dTmp > 1.0)                                   // be shure we dont call acos with
    distance = 0;                                   // values greater than 1 (like 1.0000000000001)
  else
    distance = (double)acos(dTmp) * (double)(RAD_TO_DEG * 111194.9267);

  return (double)(distance);
}


double Bearing(double lat1, double lon1, double lat2, double lon2)
{
  double angle;
  double d;

  lat1 *= DEG_TO_RAD;
  lat2 *= DEG_TO_RAD;
  lon1 *= DEG_TO_RAD;
  lon2 *= DEG_TO_RAD;

  double clat1 = cos(lat1);
  double clat2 = cos(lat2);
  double slat1 = sin(lat1);
  double slat2 = sin(lat2);


  d = (slat1*slat2 +  clat1*clat2 * cos(lon1-lon2) );
  if(d>1) d = 0.99999999999999;
  if(d<-1) d = -0.99999999999999;
  d = acos(d);

  if(sin(lon1-lon2)<0 )
    {
      angle = (((slat2-slat1)
		* cos(d) ) / (sin(d)*clat1));

      if(angle >1) angle = 1;
      if(angle<-1) angle = -1;
      angle = acos(angle);

      /* JMW Redundant code?
      if(lat1>lat2)
	angle = angle * (180/pi);
      else
	angle = angle * (180/pi);
      */
      angle *= RAD_TO_DEG;
    }
  else
    {
      if (d != 0 && clat1 != 0){
        angle=(( (slat2-slat1)
          * cos(d) ) / (sin(d)*clat1));
        if(angle >1) angle = 1;
        if(angle<-1) angle = -1;
        angle = acos(angle);
      } else
        angle = 0;

      angle = 360 - (angle * RAD_TO_DEG);
    }

  return (double)angle;
}


double Reciprocal(double InBound)
{
  if(InBound >= 180)
    return InBound - 180;
  else
    return InBound + 180;
}

double BiSector(double InBound, double OutBound)
{
  double result;


  InBound = Reciprocal(InBound);

  if(InBound == OutBound)
    {
      result = Reciprocal(InBound);
    }

  else if (InBound > OutBound)
    {
      if( (InBound - OutBound) < 180)
	{
	  result = Reciprocal((InBound+OutBound)/2);
	}
      else
	{
	  result = (InBound+OutBound)/2;
	}
    }
  else
    {
      if( (OutBound - InBound) < 180)
	{
	  result = Reciprocal((InBound+OutBound)/2);
	}
      else
	{
	  result = (InBound+OutBound)/2;
	}
    }
  return result;
}


/////////////////////////////////////////////////////////////////

void PolarWinPilot2XCSoar(double POLARV[3], double POLARW[3], double ww[2]) {
  double d;
  double v1,v2,v3;
  double w1,w2,w3;

  v1 = POLARV[0]/3.6; v2 = POLARV[1]/3.6; v3 = POLARV[2]/3.6;
  //	w1 = -POLARV[0]/POLARLD[0];
  //    w2 = -POLARV[1]/POLARLD[1];
  //    w3 = -POLARV[2]/POLARLD[2];
  w1 = POLARW[0]; w2 = POLARW[1]; w3 = POLARW[2];

  d = v1*v1*(v2-v3)+v2*v2*(v3-v1)+v3*v3*(v1-v2);
  if (d == 0.0)
    {
      POLAR[0]=0;
    }
  else
    {
      POLAR[0]=((v2-v3)*(w1-w3)+(v3-v1)*(w2-w3))/d;
    }
  d = v2-v3;
  if (d == 0.0)
    {
      POLAR[1]=0;
    }
  else
    {
      POLAR[1] = (w2-w3-POLAR[0]*(v2*v2-v3*v3))/d;
    }


  WEIGHTS[0] = 70;                      // Pilot weight
  WEIGHTS[1] = ww[0]-WEIGHTS[0];        // Glider empty weight
  WEIGHTS[2] = ww[1];                   // Ballast weight

  POLAR[2] = (double)(w3 - POLAR[0] *v3*v3 - POLAR[1]*v3);

  // now scale off weight
  POLAR[0] = POLAR[0] * (double)sqrt(WEIGHTS[0] + WEIGHTS[1]);
  POLAR[2] = POLAR[2] / (double)sqrt(WEIGHTS[0] + WEIGHTS[1]);

}




void PExtractParameter(TCHAR *Source, TCHAR *Destination, int DesiredFieldNumber)
{
  int index = 0;
  int dest_index = 0;
  int CurrentFieldNumber = 0;
  int StringLength        = 0;

  StringLength = _tcslen(Source);

  while( (CurrentFieldNumber < DesiredFieldNumber) && (index < StringLength) )
    {
      if ( Source[ index ] == ',' )
	{
	  CurrentFieldNumber++;
	}
      index++;
    }

  if ( CurrentFieldNumber == DesiredFieldNumber )
    {
      while( (index < StringLength)    &&
	     (Source[ index ] != ',') &&
	     (Source[ index ] != 0x00) )
	{
	  Destination[dest_index] = Source[ index ];
	  index++; dest_index++;
	}
      Destination[dest_index] = '\0';
    }
}


void ReadWinPilotPolar() {

  TCHAR	szFile[MAX_PATH] = TEXT("\0");
  TCHAR ctemp[80];
  TCHAR TempString[200];
  HANDLE hFile;

  double POLARV[3];
  double POLARW[3];
  double ww[2];

  ww[0]= 403.0; // 383
  ww[1]= 101.0; // 121
  POLARV[0]= 115.03;
  POLARW[0]= -0.86;
  POLARV[1]= 174.04;
  POLARW[1]= -1.76;
  POLARV[2]= 212.72;
  POLARW[2]= -3.4;

  GetRegistryString(szRegistryPolarFile, szFile, MAX_PATH);
  SetRegistryString(szRegistryPolarFile, TEXT("\0"));

  hFile = CreateFile(szFile,GENERIC_READ,0,(LPSECURITY_ATTRIBUTES)NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

  if(hFile != INVALID_HANDLE_VALUE )
    {

      bool foundline = false;

      while(ReadString(hFile,200,TempString) && (!foundline))
	{

	  if(_tcsstr(TempString,TEXT("*")) != TempString) // Look For Comment
	    {
	      PExtractParameter(TempString, ctemp, 0);
	      ww[0] = StrToDouble(ctemp,NULL);

	      PExtractParameter(TempString, ctemp, 1);
	      ww[1] = StrToDouble(ctemp,NULL);

	      PExtractParameter(TempString, ctemp, 2);
	      POLARV[0] = StrToDouble(ctemp,NULL);
	      PExtractParameter(TempString, ctemp, 3);
	      POLARW[0] = StrToDouble(ctemp,NULL);

	      PExtractParameter(TempString, ctemp, 4);
	      POLARV[1] = StrToDouble(ctemp,NULL);
	      PExtractParameter(TempString, ctemp, 5);
	      POLARW[1] = StrToDouble(ctemp,NULL);

	      PExtractParameter(TempString, ctemp, 6);
	      POLARV[2] = StrToDouble(ctemp,NULL);
	      PExtractParameter(TempString, ctemp, 7);
	      POLARW[2] = StrToDouble(ctemp,NULL);

	      PolarWinPilot2XCSoar(POLARV, POLARW, ww);

	      foundline = true;
	    }
	}

      // file was OK, so save it
      if (foundline) {
	SetRegistryString(szRegistryPolarFile, szFile);
      }

      CloseHandle (hFile);
    }

}

// *LS-3	WinPilot POLAR file: MassDryGross[kg], MaxWaterBallast[liters], Speed1[km/h], Sink1[m/s], Speed2, Sink2, Speed3, Sink3
//								403,				101,					115.03,		  -0.86,	174.04,	 -1.76,	212.72,	-3.4


//////////////////////////////////////////////////



void CalculateNewPolarCoef(void)
{
  static double Polars[7][3] =
    {
      {-0.0538770500225782443497, 0.1323114348, -0.1273364037098239098543},
      {-0.0532456270195884696748, 0.1509454717, -0.1474304674787072275183},
      {-0.0598306909918491529791, 0.1896480967, -0.1883344146619101871894},
      {-0.0303118230885946660507, 0.0771466019, -0.0799469636558217515699},
      {-0.0222929913566948641563, 0.0318771616, -0.0307925896846546928318},
      {-0.0430828898445299480353, 0.0746938776, -0.0487285153053357557183},
      {0.0, 0.0, 0.0}

    };


  /* Weights:
     0 Pilot Weight?
     1 Glider Weight
     2 BallastWeight
  */

  static double Weights[7][3] = { {70,190,1},
				  {70,250,100},
				  {70,240,285},
				  {70,287,165},  // w ok!
				  {70,400,120},  //
				  {70,527,303},
				  {0,0,0}
  };
  int i;

  for(i=0;i<3;i++)
    {
      POLAR[i] = Polars[POLARID][i];
      WEIGHTS[i] = Weights[POLARID][i];
    }
  if (POLARID==6) {
    ReadWinPilotPolar();
  }

}


void RefreshTask() {
  double lengthtotal = 0.0;
  int i;
  // Only need to refresh info where the removal happened
  // as the order of other taskpoints hasn't changed
  for (i=0; i<MAXTASKPOINTS; i++) {
    if (Task[i].Index != -1) {
      RefreshTaskWaypoint(i);
      lengthtotal += Task[i].Leg;
    }
  }
  if (lengthtotal>0) {
    for (i=0; i<MAXTASKPOINTS; i++) {
      if (Task[i].Index != -1) {
	RefreshTaskWaypoint(i);
	TaskStats[i].LengthPercent = Task[i].Leg/lengthtotal;
	if ((i<MAXTASKPOINTS-1) && (Task[i+1].Index == -1)) {
	  Task[i].AATTargetOffsetRadius = 0.0;
	  Task[i].AATTargetOffsetRadial = 0.0;
	  Task[i].AATTargetLat = WayPointList[Task[i].Index].Latitude;
	  Task[i].AATTargetLon = WayPointList[Task[i].Index].Longitude;
	}
      }
    }
  }
  CalculateTaskSectors();
  CalculateAATTaskSectors();
}


void CalculateTaskSectors(void)
{
  int i;
  double SectorAngle, SectorSize, SectorBearing;

  for(i=0;i<MAXTASKPOINTS-1;i++)
    {
      if((Task[i].Index >=0) &&  (Task[i+1].Index >=0))
	{
	  if(i == 0)
	    {
	      SectorAngle = 90;
	      SectorSize = StartRadius;
	      SectorBearing = Task[i].OutBound;
	    }
	  else
	    {
	      SectorAngle = 45;
	      SectorSize = 5000;
	      SectorBearing = Task[i].Bisector;
	    }

	  Task[i].SectorStartLat =
	    FindLatitude(WayPointList[Task[i].Index].Latitude,
			 WayPointList[Task[i].Index].Longitude,
			 SectorBearing + SectorAngle, SectorSize);
	  Task[i].SectorStartLon =
	    FindLongitude(WayPointList[Task[i].Index].Latitude,
			  WayPointList[Task[i].Index].Longitude,
			  SectorBearing + SectorAngle, SectorSize);
	  Task[i].SectorEndLat   =
	    FindLatitude(WayPointList[Task[i].Index].Latitude,
			 WayPointList[Task[i].Index].Longitude,
			 SectorBearing - SectorAngle, SectorSize);
	  Task[i].SectorEndLon   =
	    FindLongitude(WayPointList[Task[i].Index].Latitude,
			  WayPointList[Task[i].Index].Longitude,
			  SectorBearing - SectorAngle, SectorSize);
	}
    }
}

void CalculateAATTaskSectors(void)
{
  int i;

  if(AATEnabled == FALSE)
    return;

  Task[0].AATTargetOffsetRadius = 0.0;
  Task[0].AATTargetOffsetRadial = 0.0;
  if (Task[0].Index>=0) {
    Task[0].AATTargetLat = WayPointList[Task[0].Index].Latitude;
    Task[0].AATTargetLon = WayPointList[Task[0].Index].Longitude;
  }

  for(i=1;i<MAXTASKPOINTS-1;i++)
    {
      if((Task[i].Index >=0))
	{
	  Task[i].AATTargetOffsetRadius = min(1.0,
                             max(Task[i].AATTargetOffsetRadius,-1.0));

	  Task[i].AATTargetOffsetRadial = min(1.0,
                             max(Task[i].AATTargetOffsetRadial,0.0));

	  double targetbearing;
	  double targetrange;

	  if(Task[i].AATType == SECTOR) {
	    targetrange = ((Task[i].AATTargetOffsetRadius+1.0)/2.0)
	      *Task[i].AATSectorRadius;
	  } else {
	    targetrange = Task[i].AATTargetOffsetRadius
	      *Task[i].AATCircleRadius;
	  }

	  targetbearing = Task[i].Bisector;
	  /*
	  if(Task[i].AATType == SECTOR) {
	    double r1 = Task[i].AATStartRadial;
	    double r2 = Task[i].AATFinishRadial;
	    targetbearing = (r2-r1)*Task[i].AATTargetOffsetRadial+r1;
	  } else {
	    targetbearing = 360.0*Task[i].AATTargetOffsetRadial;
	  }
	  */

	  Task[i].AATTargetLat =
	    FindLatitude (WayPointList[Task[i].Index].Latitude,
			  WayPointList[Task[i].Index].Longitude,
			  targetbearing,
			  targetrange);
	  Task[i].AATTargetLon =
	    FindLongitude (WayPointList[Task[i].Index].Latitude,
			   WayPointList[Task[i].Index].Longitude,
			   targetbearing,
			   targetrange);

	  if(Task[i].AATType == SECTOR)
	    {
	      Task[i].AATStartLat = FindLatitude (WayPointList[Task[i].Index].Latitude,WayPointList[Task[i].Index].Longitude, Task[i].AATStartRadial , Task[i].AATSectorRadius );
	      Task[i].AATStartLon = FindLongitude(WayPointList[Task[i].Index].Latitude,WayPointList[Task[i].Index].Longitude, Task[i].AATStartRadial , Task[i].AATSectorRadius );
	      Task[i].AATFinishLat= FindLatitude (WayPointList[Task[i].Index].Latitude,WayPointList[Task[i].Index].Longitude,	Task[i].AATFinishRadial , Task[i].AATSectorRadius );
	      Task[i].AATFinishLon= FindLongitude(WayPointList[Task[i].Index].Latitude,WayPointList[Task[i].Index].Longitude,	Task[i].AATFinishRadial , Task[i].AATSectorRadius );
	    }
	}
    }
}


double FindLatitude(double Lat, double Lon, double Bearing, double Distance)
{
  double result;

  Lat *= DEG_TO_RAD;
  Lon *= DEG_TO_RAD;
  Bearing *= DEG_TO_RAD;

  Distance = Distance/6371000;

  result = (double)asin(sin(Lat)*cos(Distance)+cos(Lat)*sin(Distance)*cos(Bearing));
  result *= RAD_TO_DEG;
  return result;
}

double FindLongitude(double Lat, double Lon, double Bearing, double Distance)
{
  double result;

  Lat *= DEG_TO_RAD;
  Lon *= DEG_TO_RAD;
  Bearing *= DEG_TO_RAD;

  Distance = Distance/6371000;

  if(cos(Lat)==0)
    result = Lon;
  else
    {
      result = Lon+(double)asin(sin(Bearing)*sin(Distance)/cos(Lat));
      result = (double)fmod((result+M_PI),(M_2PI));
      result = result - M_PI;
    }
  return result * RAD_TO_DEG;
}


static double xcoords[64] = {
  0,			0.09801714,		0.195090322,	0.290284677,	0.382683432,	0.471396737,	0.555570233,	0.634393284,
  0.707106781,	0.773010453,	0.831469612,	0.881921264,	0.923879533,	0.956940336,	0.98078528,		0.995184727,
  1,			0.995184727,	0.98078528,		0.956940336,	0.923879533,	0.881921264,	0.831469612,	0.773010453,
  0.707106781,	0.634393284,	0.555570233,	0.471396737,	0.382683432,	0.290284677,	0.195090322,	0.09801714,
  0,			-0.09801714,	-0.195090322,	-0.290284677,	-0.382683432,	-0.471396737,	-0.555570233,	-0.634393284,
  -0.707106781,	-0.773010453,	-0.831469612,	-0.881921264,	-0.923879533,	-0.956940336,	-0.98078528,	-0.995184727,
  -1,			-0.995184727,	-0.98078528,	-0.956940336,	-0.923879533,	-0.881921264,	-0.831469612,	-0.773010453,
  -0.707106781,	-0.634393284,	-0.555570233,	-0.471396737,	-0.382683432,	-0.290284677,	-0.195090322,	-0.09801714
};

static double ycoords[64] = {
  1,			0.995184727,	0.98078528,		0.956940336,	0.923879533,	0.881921264,	0.831469612,	0.773010453,
  0.707106781,	0.634393284,	0.555570233,	0.471396737,	0.382683432,	0.290284677,	0.195090322,	0.09801714,
  0,			-0.09801714,	-0.195090322,	-0.290284677,	-0.382683432,	-0.471396737,	-0.555570233,	-0.634393284,
  -0.707106781,	-0.773010453,	-0.831469612,	-0.881921264,	-0.923879533,	-0.956940336,	-0.98078528,	-0.995184727,
  -1,			-0.995184727,	-0.98078528,	-0.956940336,	-0.923879533,	-0.881921264,	-0.831469612,	-0.773010453,
  -0.707106781,	-0.634393284,	-0.555570233,	-0.471396737,	-0.382683432,	-0.290284677,	-0.195090322,	-0.09801714,
  0,			0.09801714,		0.195090322,	0.290284677,	0.382683432,	0.471396737,	0.555570233,	0.634393284,
  0.707106781,	0.773010453,	0.831469612,	0.881921264,	0.923879533,	0.956940336,	0.98078528,		0.995184727
};


void StartArc(HDC hdc,
	      double longitude0, double latitude0,
	      double longitude1, double latitude1,
	      double arclength) {
//  int scx, scy;

  double radius = Distance(latitude0, longitude0,
			   latitude1, longitude1);
  double bearing = Bearing(latitude0, longitude0,
			   latitude1, longitude1);
  double angle = 360*min(1, arclength/(2.0*3.1415926*radius));
  int i0 = (int)(bearing+angle/2);
  int i1 = (int)(bearing-angle/2);
  int i;
  if (i0<0) { i1+= 360; }
  if (i1<0) { i1+= 360; }
  if (i0>360) {i0-= 360; }
  if (i1>360) {i1-= 360; }
  i0 = i0*64/360;
  i1 = i1*64/360;
  POINT pt[2];
//  double lat, lon;
  int x=0;
  int y=0;

  if (i1<i0) {
    for (i=i0; i<64-1; i++) {
      //      MapWindow::LatLon2Screen(lon, lat, &scx, &scy);
      pt[0].x = x + (long) (radius * xcoords[i]);
      pt[0].y = y + (long) (radius * ycoords[i]);
      pt[1].x = x + (long) (radius * xcoords[i+1]);
      pt[1].y = y + (long) (radius * ycoords[i+1]);
      Polygon(hdc,pt,2);
    }
    for (i=0; i<i1-1; i++) {
      pt[0].x = x + (long) (radius * xcoords[i]);
      pt[0].y = y + (long) (radius * ycoords[i]);
      pt[1].x = x + (long) (radius * xcoords[i+1]);
      pt[1].y = y + (long) (radius * ycoords[i+1]);
      Polygon(hdc,pt,2);
    }
  } else {
    for (i=i0; i<i1-1; i++) {
      pt[0].x = x + (long) (radius * xcoords[i]);
      pt[0].y = y + (long) (radius * ycoords[i]);
      pt[1].x = x + (long) (radius * xcoords[i+1]);
      pt[1].y = y + (long) (radius * ycoords[i+1]);
      Polygon(hdc,pt,2);
    }
  }

}


int Circle(HDC hdc, long x, long y, int radius, RECT rc)
{
  POINT pt[65];
  int i;

  rectObj rect;
  rect.minx = x-radius;
  rect.maxx = x+radius;
  rect.miny = y-radius;
  rect.maxy = y+radius;
  rectObj rcrect;
  rcrect.minx = rc.left;
  rcrect.maxx = rc.right;
  rcrect.miny = rc.top;
  rcrect.maxy = rc.bottom;

  if (msRectOverlap(&rect, &rcrect)!=MS_TRUE) {
    return FALSE;
  }

  // JMW added faster checking...

  for(i=0;i<64;i++)
    {
      pt[i].x = x + (long) (radius * xcoords[i]);
      pt[i].y = y + (long) (radius * ycoords[i]);
    }
  pt[64].x = x + (long) (radius * xcoords[0]);
  pt[64].y = y + (long) (radius * ycoords[0]);

  Polygon(hdc,pt,65);
  return TRUE;
}


int Segment(HDC hdc, long x, long y, int radius, RECT rc,
	    double start,
	    double end)
{
  POINT pt[66];
  int i;
  int istart;
  int iend;

  rectObj rect;
  rect.minx = x-radius;
  rect.maxx = x+radius;
  rect.miny = y-radius;
  rect.maxy = y+radius;
  rectObj rcrect;
  rcrect.minx = rc.left;
  rcrect.maxx = rc.right;
  rcrect.miny = rc.top;
  rcrect.maxy = rc.bottom;

  if (msRectOverlap(&rect, &rcrect)!=MS_TRUE) {
    return FALSE;
  }

  // JMW added faster checking...

  while (start>=360.0) {
    start -= 360.0;
  }
  while (end<=0.0) {
    end += 360.0;
  }
  while (start<0.0) {
    start += 360.0;
  }
  while (end>360.0) {
    end -= 360.0;
  }

  istart = iround(start/360.0*64);
  iend = iround(end/360.0*64);

  int npoly = 0;

  if (istart>iend) {
    iend+= 64;
  }

  pt[0].x = x; pt[0].y = y; npoly=1;
  for(i=0;i<64;i++)
    {
      if (i<=iend-istart) {
	pt[npoly].x = x + (long) (radius * xcoords[(i+istart)%64]);
	pt[npoly].y = y + (long) (radius * ycoords[(i+istart)%64]);
	npoly++;
      }
    }
  pt[npoly].x = x; pt[npoly].y = y; npoly++;
  Polygon(hdc,pt,npoly);

  return TRUE;
}


void ConvertFlightLevels(void)
{
  unsigned i;

  for(i=0;i<NumberOfAirspaceCircles;i++)
    {
      if(AirspaceCircle[i].Base.FL  != 0)
	{
	  AirspaceCircle[i].Base.Altitude = (AirspaceCircle[i].Base.FL * 100) + ((QNH-1013)*30);
	  AirspaceCircle[i].Base.Altitude = AirspaceCircle[i].Base.Altitude / TOFEET;
	}
      if(AirspaceCircle[i].Top.FL  != 0)
	{
	  AirspaceCircle[i].Top.Altitude = (AirspaceCircle[i].Top.FL * 100) + ((QNH-1013)*30);
	  AirspaceCircle[i].Top.Altitude = AirspaceCircle[i].Top.Altitude / TOFEET;
	}
    }


  for(i=0;i<NumberOfAirspaceAreas;i++)
    {
      if(AirspaceArea[i].Base.FL  != 0)
	{
	  AirspaceArea[i].Base.Altitude = (AirspaceArea[i].Base.FL * 100) + ((QNH-1013)*30);
	  AirspaceArea[i].Base.Altitude = AirspaceArea[i].Base.Altitude / TOFEET;
	}
      if(AirspaceArea[i].Top.FL  != 0)
	{
	  AirspaceArea[i].Top.Altitude = (AirspaceArea[i].Top.FL * 100) + ((QNH-1013)*30);
	  AirspaceArea[i].Top.Altitude = AirspaceArea[i].Top.Altitude / TOFEET;
	}
    }
}

BOOL PolygonVisible(const POINT *lpPoints, int nCount, RECT rc)
{
  BOOL Sector[9] = {FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE};
  int i;
  int Count = 0;

  //return TRUE;

  for(i=0;i<nCount;i++)
    {
      if(lpPoints[i].y < MapWindow::MapRect.top)
	{
	  if(lpPoints[i].x < MapWindow::MapRect.left)
	    {
	      Sector[0] = TRUE;
	    }
	  else if((lpPoints[i].x >=MapWindow::MapRect.left)
		  && (lpPoints[i].x <MapWindow::MapRect.right))
	    {
	      Sector[1] = TRUE;
	    }
	  else if(lpPoints[i].x >=MapWindow::MapRect.right)
	    {
	      Sector[2] = TRUE;
	    }
	}
      else if((lpPoints[i].y >=MapWindow::MapRect.top)
	      && (lpPoints[i].y <MapWindow::MapRect.bottom))
	{
	  if(lpPoints[i].x <MapWindow::MapRect.left)
	    {
	      Sector[3] = TRUE;
	    }
	  else if((lpPoints[i].x >=MapWindow::MapRect.left)
		  && (lpPoints[i].x <MapWindow::MapRect.right))
	    {
	      Sector[4] = TRUE;
	      return TRUE;
	    }
	  else if(lpPoints[i].x >=MapWindow::MapRect.right)
	    {
	      Sector[5] = TRUE;
	    }
	}
      else if(lpPoints[i].y >=MapWindow::MapRect.bottom)
	{
	  if(lpPoints[i].x <MapWindow::MapRect.left)
	    {
	      Sector[6] = TRUE;
	    }
	  else if((lpPoints[i].x >=MapWindow::MapRect.left)
		  && (lpPoints[i].x <MapWindow::MapRect.right))
	    {
	      Sector[7] = TRUE;
	    }
	  else if(lpPoints[i].x >=MapWindow::MapRect.right)
	    {
	      Sector[8] = TRUE;
	    }
	}
    }

  for(i=0;i<9;i++)
    {
      if(Sector[i])
	{
	  Count ++;
	}
    }

  if(Count>= 2)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}

void SetRegistryColour(int i, DWORD c)
{
  SetToRegistry(szRegistryColour[i] ,c) ;
}


void SetRegistryBrush(int i, DWORD c)
{
  SetToRegistry(szRegistryBrush[i] ,c) ;
}


void ReadAssetNumber(void)
{
  strAssetNumber[0]= _T('A');
  strAssetNumber[1]= _T('A');
  strAssetNumber[2]= _T('A');
  /*
  if(strAssetNumber[0] != '\0')
    {
      return;
    }
  ReadUUID();
  if(strAssetNumber[0] != '\0')
    {
      return;
    }

  ReadCompaqID();
  */
}

void ReadCompaqID(void)
{
  PROCESS_INFORMATION pi;
  HANDLE hInFile;// = INVALID_HANDLE_VALUE;
  DWORD dwBytesRead;

  if(strAssetNumber[0] != '\0')
    {
      return;
    }

  CreateProcess(TEXT("\\windows\\CreateAssetFile.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, NULL, &pi);

  hInFile = CreateFile(TEXT("\\windows\\cpqAssetData.dat"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
  if (hInFile == INVALID_HANDLE_VALUE)
    {
      //	    MessageBox(hWnd, TEXT("Unable to open asset data file."), TEXT("Error!"), MB_OK);
      return;
    }
  SetFilePointer(hInFile, 976, NULL, FILE_BEGIN);
  memset(strAssetNumber, 0, 64 * sizeof(TCHAR));
  ReadFile(hInFile, &strAssetNumber, 64, &dwBytesRead, (OVERLAPPED *)NULL);
  CloseHandle(hInFile);
}

void ReadUUID(void)
{
  BOOL fRes;
  DWORD dwBytesReturned =0;
  DEVICE_ID DevID;
  int wSize;
  int i;

  GUID Guid;

  unsigned long temp, Asset;

  memset(&Guid, 0, sizeof(GUID));

  memset(&DevID, 0, sizeof(DEVICE_ID));
  DevID.dwSize = sizeof(DEVICE_ID);

  fRes = KernelIoControl( IOCTL_HAL_GET_DEVICEID, NULL, 0,
			  &DevID, sizeof( DEVICE_ID ), &dwBytesReturned );

  wSize = DevID.dwSize;

  if( (FALSE != fRes) || (ERROR_INSUFFICIENT_BUFFER != GetLastError()))
    return;

  memset(&DevID, 0, sizeof(wSize));
  DevID.dwSize = wSize;

  fRes = KernelIoControl( IOCTL_HAL_GET_DEVICEID, NULL, 0,
			  &DevID, wSize, &dwBytesReturned );

  if((FALSE == fRes) || (ERROR_INSUFFICIENT_BUFFER == GetLastError()) )
    return;

  BYTE* pDat = (BYTE*)&Guid.Data1;
  BYTE* pSrc = (BYTE*)(&DevID) + DevID.dwPresetIDOffset;
  memcpy(pDat, pSrc, DevID.dwPresetIDBytes);
  pDat +=  DevID.dwPresetIDBytes;
  pSrc =  (BYTE*)(&DevID) + DevID.dwPlatformIDOffset;
  memcpy(pDat, pSrc, DevID.dwPlatformIDBytes);

  temp = Guid.Data2; temp = temp << 16;
  temp += Guid.Data3 ;

  Asset = temp ^ Guid.Data1 ;

  temp = 0;
  for(i=0;i<4;i++)
    {
      temp = temp << 8;
      temp += Guid.Data4[i];
    }

  Asset = Asset ^ temp;

  temp = 0;
  for(i=0;i<4;i++)
    {
      temp = temp << 8;
      temp += Guid.Data4[i+4];
    }

  Asset = Asset ^ temp;

  _stprintf(strAssetNumber,TEXT("%08X%08X"),Asset,Guid.Data1 );
  return;
}


void WriteFileRegistryString(HANDLE hFile, TCHAR *instring) {
    int len;
    char ctempFile[MAX_PATH];
    TCHAR tempFile[MAX_PATH];
    DWORD dwBytesWritten;
    int i;

    tempFile[0]=0;
    for (i=0; i<MAX_PATH; i++) {
      tempFile[i]= 0;
    }
    GetRegistryString(instring, tempFile, MAX_PATH);
    WideCharToMultiByte( CP_ACP, 0, tempFile,
			 _tcslen(tempFile)+1,
			 ctempFile,
			 MAX_PATH, NULL, NULL);
    for (i=0; i<MAX_PATH; i++) {
      if (ctempFile[i]=='\?') {
	ctempFile[i]=0;
      }
    }
    len = strlen(ctempFile)+1;
    ctempFile[len-1]= '\n';
    WriteFile(hFile,ctempFile,len, &dwBytesWritten, (OVERLAPPED *)NULL);
}


void WriteProfile(TCHAR *szFile)
{
  SaveRegistryToFile(szFile);
}


void ReadFileRegistryString(HANDLE hFile, TCHAR *instring) {
    int i;
    TCHAR tempFile[MAX_PATH];

    for (i=0; i<MAX_PATH; i++) {
      tempFile[i]= 0;
    }
    ReadString(hFile, MAX_PATH, tempFile);
    tempFile[_tcslen(tempFile)]= 0;
    SetRegistryString(instring, tempFile);
}


void ReadProfile(TCHAR *szFile)
{

  LoadRegistryFromFile(szFile);

    WAYPOINTFILECHANGED = TRUE;
    TERRAINFILECHANGED = TRUE;
    TOPOLOGYFILECHANGED = TRUE;
    AIRSPACEFILECHANGED = TRUE;
    AIRFIELDFILECHANGED = TRUE;
    POLARFILECHANGED = TRUE;

    // assuming all is ok, we can...
    ReadRegistrySettings();

}


double ScreenAngle(int x1, int y1, int x2, int y2)
{
  return atan2(y2-y1, x2-x1)*RAD_TO_DEG;
}

void FormatWarningString(int Type, TCHAR *Name , AIRSPACE_ALT Base, AIRSPACE_ALT Top, TCHAR *szMessageBuffer, TCHAR *szTitleBuffer )
{
  TCHAR BaseStr[512];
  TCHAR TopStr[512];

  switch (Type)
    {
    case RESTRICT:		_tcscpy(szTitleBuffer,TEXT("Restricted")); break;
    case PROHIBITED:	_tcscpy(szTitleBuffer,TEXT("Prohibited")); break;
    case DANGER:			_tcscpy(szTitleBuffer,TEXT("Danger Area")); break;
    case CLASSA:			_tcscpy(szTitleBuffer,TEXT("Class A")); break;
    case CLASSB:			_tcscpy(szTitleBuffer,TEXT("Class B")); break;
    case CLASSC:			_tcscpy(szTitleBuffer,TEXT("Class C")); break;
    case CLASSD:			_tcscpy(szTitleBuffer,TEXT("Class D")); break;
    case CLASSE:			_tcscpy(szTitleBuffer,TEXT("Class E")); break;
    case CLASSF:			_tcscpy(szTitleBuffer,TEXT("Class F")); break;
    case NOGLIDER:		_tcscpy(szTitleBuffer,TEXT("No Glider")); break;
    case CTR:					_tcscpy(szTitleBuffer,TEXT("CTR")); break;
    case WAVE:				_tcscpy(szTitleBuffer,TEXT("Wave")); break;
    default:					_tcscpy(szTitleBuffer,TEXT("Unknown"));
    }

  if(Base.FL == 0)
    {
      if (Base.Altitude > 0)
        _stprintf(BaseStr,TEXT("%1.0f%s Alt"), ALTITUDEMODIFY * Base.Altitude, Units::GetUnitName(Units::GetUserAltitudeUnit()));
      else
        _stprintf(BaseStr,TEXT("GND"));
    }
  else
    {
      _stprintf(BaseStr,TEXT("FL %1.0f"),Base.FL );
    }

  if(Top.FL == 0)
    {
      _stprintf(TopStr,TEXT("%1.0f%s Alt"), ALTITUDEMODIFY * Top.Altitude, Units::GetUnitName(Units::GetUserAltitudeUnit()));
    }
  else
    {
      _stprintf(TopStr,TEXT("FL %1.0f"),Top.FL );
    }

  _stprintf(szMessageBuffer,TEXT("%s: %s\r\nBase: %s\r\nTop: %s\r\n"),szTitleBuffer, Name, BaseStr, TopStr);
}

// read string from file
// support national codepage
// hFile:  file handle
// Max:    max chars to fit in Buffer
// String: pointer to string buffer
// return: True if at least one byte was read from file
//         False Max > MAX_PATH or EOF or read error
BOOL ReadString(HANDLE hFile, int Max, TCHAR *String)
{
  int i,j;
  char c;
  char sTmp[MAX_PATH+1];
  DWORD dwNumBytesRead=0;
  DWORD dwTotalNumBytesRead=0;
  char  FileBuffer[MAX_PATH+1];
  DWORD dwFilePos;

  String[0] = '\0';
  sTmp[0] = 0;

  if (Max >= sizeof(sTmp))
    return(FALSE);


  dwFilePos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);

  if (hFile == INVALID_HANDLE_VALUE)
    return(FALSE);

  if (ReadFile(hFile, FileBuffer, sizeof(FileBuffer), &dwNumBytesRead, (OVERLAPPED *)NULL) == 0)
    return(FALSE);

  i = 0;
  j = 0;
  while(i<Max && j<(int)dwNumBytesRead){

    c = FileBuffer[j];
    j++;
    dwTotalNumBytesRead++;

    if((c == '\n')){
      break;
    }

    sTmp[i] = c;
    i++;
    continue;
  }

  sTmp[i] = 0;

  SetFilePointer(hFile, dwFilePos+j, NULL, FILE_BEGIN);

  sTmp[Max-1] = '\0';

  mbstowcs(String, sTmp, strlen(sTmp)+1);

  return (dwTotalNumBytesRead>0);

}

BOOL ReadStringX(FILE *fp, int Max, TCHAR *String){

  if (fp == NULL || Max < 1 || String == NULL)
    return (0);

  if (_fgetts(String, 200, fp) != NULL){

    TCHAR *pWC = &String[_tcslen(String)];

    while (pWC > String && (*pWC == '\r' || *pWC == '\n'))
      pWC--;

    *pWC = '\0';

    return (1);
  }

  return (0);

}



void InitSineTable(void)
{
  int i;
  double angle;

  for(i=0;i<910;i++)
    {
      angle = 0.1 * (double)i;
      angle *= DEG_TO_RAD;
      SINETABLE[i] = (double)sin(angle);
      FSINETABLE[i] = (float)sin(angle);
    }
}


float ffastcosine(float x)
{
  return ffastsine(x+90);
}

double fastcosine(double x)
{
  return fastsine(x+90);
}

double fastsine(double x)
{
  int index;

  while(x<0)
    {
      x = x + 360;
    }
  while(x>=360)
    {
      x = x - 360;
    }
  index = (int)(x*10);
  if((index>=0 )&&(index<=900))
    {
      return SINETABLE[index];
    }
  else if((index>900)&&(index<=1800))
    {
      return SINETABLE[1800 - index];
    }
  else if((index>1800)&&(index<=2700))
    {
      return -1*SINETABLE[index-1800];
    }
  else if((index>2700)&&(index<=3600))
    {
      index = index - 1800;
      return -1*SINETABLE[1800-index];
    }
  else
    {
      return 0;
    }
}


float ffastsine(float x)
{
  int index;

  while(x<0)
    {
      x = x + 360;
    }
  while(x>=360)
    {
      x = x - 360;
    }
  index = (int)(x*10);
  if((index>=0 )&&(index<=900))
    {
      return FSINETABLE[index];
    }
  else if((index>900)&&(index<=1800))
    {
      return FSINETABLE[1800 - index];
    }
  else if((index>1800)&&(index<=2700))
    {
      return -FSINETABLE[index-1800];
    }
  else if((index>2700)&&(index<=3600))
    {
      index = index - 1800;
      return -FSINETABLE[1800-index];
    }
  else
    {
      return 0;
    }
}


double StrToDouble(TCHAR *Source, TCHAR **Stop)
{
  int index = 0;
  int StringLength        = 0;
  double Sum = 0;
  double Divisor = 10;
  int neg = 0;

  StringLength = _tcslen(Source);

  while((Source[index] == ' ')||(Source[index]==9))
    // JMW added skip for tab stop
    {
      index ++;
    }
  if (Source[index]=='-') {
    neg=1;
    index++;
  }

  while( (index < StringLength)
	 &&
	 (
	  (Source[index]>= '0') && (Source [index] <= '9')
          )
	 )
    {
      Sum = (Sum*10) + (Source[ index ] - '0');
      index ++;
    }
  if(Source[index] == '.')
    {
      index ++;
      while( (index < StringLength)
	     &&
	     (
	      (Source[index]>= '0') && (Source [index] <= '9')
	      )
	     )
	{
	  Sum = (Sum) + (double)(Source[ index ] - '0')/Divisor;
	  index ++;Divisor = Divisor * 10;
	}
    }
  if(Stop != NULL)
    *Stop = &Source[index];

  if (neg) {
    return -Sum;
  } else {
    return Sum;
  }
}



void SaveSoundSettings()
{
  SetToRegistry(szRegistrySoundVolume, (DWORD)SoundVolume);
  SetToRegistry(szRegistrySoundDeadband, (DWORD)SoundDeadband);
  SetToRegistry(szRegistrySoundAudioVario, EnableSoundVario);
  SetToRegistry(szRegistrySoundTask, EnableSoundTask);
  SetToRegistry(szRegistrySoundModes, EnableSoundModes);
}


void SaveWindToRegistry() {
  SetToRegistry(szRegistryWindSpeed,(DWORD)CALCULATED_INFO.WindSpeed);
  SetToRegistry(szRegistryWindBearing,(DWORD)CALCULATED_INFO.WindBearing);
}


void LoadWindFromRegistry() {
  DWORD Temp;
  GetFromRegistry(szRegistryWindSpeed,&Temp);
  CALCULATED_INFO.WindSpeed = (double)Temp;
  GetFromRegistry(szRegistryWindBearing,&Temp);
  CALCULATED_INFO.WindBearing = (double)Temp;

}

void ReadDeviceSettings(int devIdx, TCHAR *Name){

  Name[0] = '\0';

  if (devIdx == 0){
    GetRegistryString(szRegistryDeviceA , Name, DEVNAMESIZE);
    return;
  }

  if (devIdx == 1){
    GetRegistryString(szRegistryDeviceB , Name, DEVNAMESIZE);
    return;
  }

}

void WriteDeviceSettings(int devIdx, TCHAR *Name){

  if (devIdx == 0)
    SetRegistryString(szRegistryDeviceA , Name);

  if (devIdx == 1)
    SetRegistryString(szRegistryDeviceB , Name);
}

unsigned int isqrt4(unsigned long val) {
  unsigned int temp, g=0;

  if (val >= 0x40000000) {
    g = 0x8000;
    val -= 0x40000000;
  }

#define INNER_MBGSQRT(s)                      \
  temp = (g << (s)) + (1 << ((s) * 2 - 2));   \
  if (val >= temp) {                          \
    g += 1 << ((s)-1);                        \
    val -= temp;                              \
  }

  INNER_MBGSQRT (15)
  INNER_MBGSQRT (14)
  INNER_MBGSQRT (13)
  INNER_MBGSQRT (12)
  INNER_MBGSQRT (11)
  INNER_MBGSQRT (10)
  INNER_MBGSQRT ( 9)
  INNER_MBGSQRT ( 8)
  INNER_MBGSQRT ( 7)
  INNER_MBGSQRT ( 6)
  INNER_MBGSQRT ( 5)
  INNER_MBGSQRT ( 4)
  INNER_MBGSQRT ( 3)
  INNER_MBGSQRT ( 2)

#undef INNER_MBGSQRT

  temp = g+g+1;
  if (val >= temp) g++;
  return g;
}

// http://www.azillionmonkeys.com/qed/sqroot.html


int iround(double i) {
  int g=(int)i;
  if (fabs(i-g)>0.5) {
    if (i<0) {
      return g-1;
    } else {
      return g+1;
    }
  } else {
    return g;
  }
}

long lround(double i) {
  long g=(long)i;
  if (fabs(i-g)>0.5) {
    if (i<0) {
      return (g-1);
    } else {
      return (g+1);
    }
  } else {
    return g;
  }
}


static int ByteCRC16(int value, int crcin)
{
    int k = (((crcin >> 8) ^ value) & 255) << 8;
    int crc = 0;
    int bits = 8;
    do
    {
        if (( crc ^ k ) & 0x8000)
            crc = (crc << 1) ^ 0x1021;
        else
            crc <<= 1;
        k <<= 1;
    }
    while (--bits);
    return ((crcin << 8) ^ crc);
}

WORD crcCalc(void *Buffer, size_t size){

  int crc = 0;
  unsigned char *pB = (unsigned char *)Buffer;

  do {
    int value = *pB++;
    crc = ByteCRC16(value, crc);
  } while (--size);

  return(crc);
}

///////////

void ExtractDirectory(TCHAR *Dest, TCHAR *Source) {
  int len = _tcslen(Source);
  int found = -1;
  int i;
  for (i=0; i<len; i++) {
    if ((Source[i]=='/')||(Source[i]=='\\')) {
      found = i;
    }
  }
  for (i=0; i<=found; i++) {
    Dest[i]= Source[i];
  }
  Dest[i]= 0;
}


/*
 * Copyright (c) 1990 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. [rescinded 22 July 1999]
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Perform a binary search.
 *
 * The code below is a bit sneaky.  After a comparison fails, we
 * divide the work in half by moving either left or right. If lim
 * is odd, moving left simply involves halving lim: e.g., when lim
 * is 5 we look at item 2, so we change lim to 2 so that we will
 * look at items 0 & 1.  If lim is even, the same applies.  If lim
 * is odd, moving right again involes halving lim, this time moving
 * the base up one item past p: e.g., when lim is 5 we change base
 * to item 3 and make lim 2 so that we will look at items 3 and 4.
 * If lim is even, however, we have to shrink it by one before
 * halving: e.g., when lim is 4, we still looked at item 2, so we
 * have to make lim 3, then halve, obtaining 1, so that we will only
 * look at item 3.
 */

void *bsearch(void *key, void *base0, size_t nmemb, size_t size, int (*compar)(const void *elem1, const void *elem2)){
	void *base = base0;
	int lim, cmp;
	void *p;

	for (lim = nmemb; lim != 0; lim >>= 1) {
		p = (char *)base + (lim >> 1) * size;
		cmp = (*compar)(key, p);
		if (cmp == 0)
			return (p);
		if (cmp > 0) {	/* key > p: move right */
			base = (char *)p + size;
			lim--;
		} /* else move left */
	}
	return (NULL);
}



TCHAR *strtok_r(TCHAR *s, TCHAR *delim, TCHAR **lasts){

  TCHAR *spanp;
	int   c, sc;
	TCHAR *tok;


	if (s == NULL && (s = *lasts) == NULL)
		return (NULL);

	/*
	 * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
	 */

cont:
	c = *s++;
	for (spanp = (TCHAR *)delim; (sc = *spanp++) != 0;) {
		if (c == sc)
			goto cont;
	}

	if (c == 0) {		/* no non-delimiter characters */
		*lasts = NULL;
		return (NULL);
	}
	tok = s - 1;

	/*
	 * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
	 * Note that delim must have one NUL; we stop if we see that, too.
	 */
	for (;;) {
		c = *s++;
		spanp = (TCHAR *)delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				*lasts = s;
				return (tok);
			}
		} while (sc != 0);
	}
	/* NOTREACHED */
}


/*

  INTERFACE FILE SECTION

  TODO - All this code, loading, searching, return etc will
  be moved into a CPP class very soon. This will allow better
  handling of the array, and a better place to swap in performance
  critical search, sort etc.

  See Also:
	Dialogs.cpp		gettext, DoStatusMessage

*/


void ReadLanguageFile() {

	TCHAR szFile1[MAX_PATH] = TEXT("\0");
	FILE *fp=NULL;

	// Open file from registry
	GetRegistryString(szRegistryLanguageFile, szFile1, MAX_PATH);
	SetRegistryString(szRegistryLanguageFile, TEXT("\0"));
	if (_tcslen(szFile1)>0)
		fp  = _tfopen(szFile1, TEXT("rt"));

	if (fp == NULL)
		return;

	// TODO - Safer sizes, strings etc - use C++ (can scanf restrict length?)
	TCHAR buffer[2049];	// key from scanf
	TCHAR key[2049];	// key from scanf
	TCHAR value[2049];	// value from scanf
	int found;			// Entries found from scanf

	/* Read from the file */
	while (
  	 (GetTextData_Size < MAXSTATUSMESSAGECACHE)
	 && fgetws(buffer, 2048, fp)
	 && ((found = swscanf(buffer, TEXT("%[^#=]=%[^\r\n][\r\n]"), key, value)) != EOF)
	) {
		// Check valid line?
		if ((found != 2) || !key || !value) continue;

		GetTextData[GetTextData_Size].key = StringMallocParse(key);
		GetTextData[GetTextData_Size].text = StringMallocParse(value);

		// Global counter
		GetTextData_Size++;
	}

	// file was OK, so save registry
	SetRegistryString(szRegistryLanguageFile, szFile1);

	fclose(fp);
}

void ReadStatusFile() {

	// DEFAULT - 0 is loaded as default, and assumed to exist
	StatusMessageData[0].key = TEXT("DEFAULT");
	StatusMessageData[0].doStatus = true;
	StatusMessageData[0].doSound = true;
	StatusMessageData[0].sound = TEXT("IDR_WAV_DRIP");
	StatusMessageData[0].delay_ms = 1500; // 1.5 s
	StatusMessageData_Size++;

	// Load up other defaults - allow overwrite in config file
	#include "Status_defaults.cpp"

	TCHAR szFile1[MAX_PATH] = TEXT("\0");
	FILE *fp=NULL;

	// Open file from registry
	GetRegistryString(szRegistryStatusFile, szFile1, MAX_PATH);
	SetRegistryString(szRegistryStatusFile, TEXT("\0"));

	if (_tcslen(szFile1)>0)
		fp  = _tfopen(szFile1, TEXT("rt"));

	// Unable to open file
	if (fp == NULL)
		return;

	// TODO - Safer sizes, strings etc - use C++ (can scanf restrict length?)
	TCHAR buffer[2049];	// Buffer for all
	TCHAR key[2049];	// key from scanf
	TCHAR value[2049];	// value from scanf
	int ms;				// Found ms for delay
	TCHAR **location;	// Where to put the data
	int found;			// Entries found from scanf
	bool some_data;		// Did we find some in the last loop...

	// Init first entry
	_init_Status(StatusMessageData_Size);
	some_data = false;

	/* Read from the file */
	while (
		(StatusMessageData_Size < MAXSTATUSMESSAGECACHE)
		&& fgetws(buffer, 2048, fp)
		&& ((found = swscanf(buffer, TEXT("%[^#=]=%[^\n]\n"), key, value)) != EOF)
	) {
		// Check valid line? If not valid, assume next record (primative, but works ok!)
		if ((found != 2) || !key || !value) {

			// Global counter (only if the last entry had some data)
			if (some_data) {
				StatusMessageData_Size++;
				some_data = false;
				_init_Status(StatusMessageData_Size);
			}

		} else {

			location = NULL;

			if (wcscmp(key, TEXT("key")) == 0) {
				some_data = true;	// Success, we have a real entry
				location = &StatusMessageData[StatusMessageData_Size].key;
			} else if (wcscmp(key, TEXT("sound")) == 0) {
				StatusMessageData[StatusMessageData_Size].doSound = true;
				location = &StatusMessageData[StatusMessageData_Size].sound;
			} else if (wcscmp(key, TEXT("delay")) == 0) {
				if (swscanf(value, TEXT("%d"), &ms) == 1)
					StatusMessageData[StatusMessageData_Size].delay_ms = ms;
			} else if (wcscmp(key, TEXT("hide")) == 0) {
				if (wcscmp(value, TEXT("yes")) == 0)
					StatusMessageData[StatusMessageData_Size].doStatus = false;
			}

			// Do we have somewhere to put this && is it currently empty ? (prevent lost at startup)
			if (location && (wcscmp(*location, TEXT("")) == 0)) {
				// TODO - this picks up memory lost from no entry, but not duplicates - fix.
				*location = StringMallocParse(value);
			}
		}

	}

	// How many we really got (blank next just in case)
	StatusMessageData_Size++;
	_init_Status(StatusMessageData_Size);

	// file was ok, so save it to registry
	SetRegistryString(szRegistryStatusFile, szFile1);

	fclose(fp);
}

// Create a blank entry (not actually used)
void _init_Status(int num) {
	StatusMessageData[num].key = TEXT("");
	StatusMessageData[num].doStatus = true;
	StatusMessageData[num].doSound = false;
	StatusMessageData[num].sound = TEXT("");
	StatusMessageData[num].delay_ms = 2500;  // 2.5 s
}


//////////////////////////
// Registry file handling
/////////////////

const static int nMaxValueNameSize = MAX_PATH;
const static int nMaxValueValueSize = 4096;
const static int nMaxClassSize = MAX_PATH;
const static int nMaxKeyNameSize = MAX_PATH;

void LoadRegistryFromFile(TCHAR *szFile)
{
  FILE *fp=NULL;
  if (_tcslen(szFile)>0)
    fp = _tfopen(szFile, TEXT("r"));
  if(fp == NULL) {
    // error
    return;
  }
  TCHAR inval[nMaxValueValueSize];
  TCHAR name[nMaxValueValueSize];
  TCHAR value[nMaxValueValueSize];
  int j;

  while (_fgetts(inval, nMaxValueValueSize, fp)) {
	  if (_stscanf(inval, TEXT("%[^#=]=\"%[^\r\n\"]\"[\r\n]"), name, value) == 2) {
		SetRegistryString(name, value);
	  } else if (_stscanf(inval, TEXT("%[^#=]=%d[\r\n]"), name, &j) == 2) {
		SetToRegistry(name, j);
	  } else if (_stscanf(inval, TEXT("%[^#=]=\"\"[\r\n]"), name) == 1) {
		SetRegistryString(name, TEXT(""));
	  } else {
		ASSERT(false);	// Invalid line reached
	  }
  }

  fclose(fp);
}


void SaveRegistryToFile(TCHAR *szFile)
{
  TCHAR lpstrName[nMaxKeyNameSize+1];
  //  TCHAR lpstrClass[nMaxClassSize+1];
  BYTE pValue[nMaxValueValueSize+1];

  HKEY hkFrom;
  LONG res = ::RegOpenKeyEx(HKEY_CURRENT_USER, szRegistryKey,
			    0, KEY_ALL_ACCESS, &hkFrom);

  if (ERROR_SUCCESS != res) {
    return;
  }

  FILE *fp=NULL;
  if (_tcslen(szFile)>0)
    fp = _tfopen(szFile, TEXT("w"));
  if(fp == NULL) {
    // error
    return;
  }

  for (int i = 0;;i++) {
    DWORD nType;
    DWORD nValueSize = nMaxValueValueSize;
    DWORD nNameSize = nMaxKeyNameSize;
    DWORD nClassSize = nMaxClassSize;

    LONG res = ::RegEnumValue(hkFrom, i, lpstrName,
			      &nNameSize, 0,
			      &nType, pValue,
			      &nValueSize);

    if (ERROR_NO_MORE_ITEMS == res) {
      break;
    }

    // type 1 text
    // type 4 integer (valuesize 4)
    TCHAR outval[nMaxValueValueSize];
    lpstrName[nNameSize]= 0; // null terminate, just in case

    outval[0] = '\0';

    if (nType==4) { // data
      _stprintf(outval,TEXT("%s=%d\r\n"), lpstrName, *((DWORD*)pValue));
    }
	// XXX SCOTT - Check that the output data (lpstrName and pValue) do not contain \r or \n
    if (nType==1) { // text
      pValue[nValueSize]= 0; // null terminate, just in case
      pValue[nValueSize+1]= 0; // null terminate, just in case
      _stprintf(outval,TEXT("%s=\"%s\"\r\n"), lpstrName, pValue);
    }

    if (outval[0] != '\0')
      _fputts(outval, fp);

  }

  fclose(fp);

  ::RegCloseKey(hkFrom);
}

TCHAR* StringMallocParse(TCHAR* old_string) {
	TCHAR buffer[2048];	// Note - max size of any string we cope with here !
	TCHAR* new_string;
	unsigned int used = 0;
	unsigned int i;
	for (i = 0; i < wcslen(old_string); i++) {
		if (used < 2045) {
			if (old_string[i] == '\\' ) {
				if (old_string[i + 1] == 'r') {
					// Do nothing
					i++;
				} else if (old_string[i + 1] == 'n') {
					buffer[used++] = '\r';
					buffer[used++] = '\n';
					i++;
				} else if (old_string[i + 1] == '\\') {
					buffer[used++] = '\\';
					i++;
				} else {
					buffer[used++] = old_string[i];
				}
			} else {
				buffer[used++] = old_string[i];
			}
		}
	};
	buffer[used++] = NULL;

	new_string = (TCHAR *)malloc((wcslen(buffer)+1)*sizeof(TCHAR));
	wcscpy(new_string, buffer);

	return new_string;
}

// Get local My Documents path - optionally include file to add and location
//	(Warning - static buffer returned, use immediately - not thread safe !!!)
TCHAR* LocalPath(TCHAR* file, int loc) {
	static TCHAR buffer[MAX_PATH];
	SHGetSpecialFolderPath(hWndMainWindow, buffer, loc, false);
	wcsncat(buffer, TEXT("\\"), MAX_PATH);
	wcsncat(buffer, file, MAX_PATH);
	return buffer;
}

void ConvertTToC(CHAR* pszDest, const TCHAR* pszSrc)
{
	for(unsigned int i = 0; i < _tcslen(pszSrc); i++)
		pszDest[i] = (CHAR) pszSrc[i];
}

void ConvertCToT(TCHAR* pszDest, const CHAR* pszSrc)
{
	for(unsigned int i = 0; i < strlen(pszSrc); i++)
		pszDest[i] = (TCHAR) pszSrc[i];
}


void propGetFontSettings(TCHAR *Name, LOGFONT* lplf) {

  TCHAR Buffer[128];
  TCHAR *pWClast, *pToken;
  LOGFONT lfTmp;

  ASSERT(Name != NULL);
  ASSERT(Name[0] != '\0');
  ASSERT(lplf != NULL);

  if (GetRegistryString(Name, Buffer, sizeof(Buffer)/sizeof(TCHAR)) == 0) {

    // typical font entry
    // 26,0,0,0,700,1,0,0,0,0,0,4,2,<fontname>

    //FW_THIN   100
    //FW_NORMAL 400
    //FW_MEDIUM 500
    //FW_BOLD   700
    //FW_HEAVY  900

    memset ((void *)&lfTmp, 0, sizeof (LOGFONT));

    if ((pToken = strtok_r(Buffer, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfHeight = _tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfWidth = _tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfEscapement = _tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfOrientation = _tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfWeight = _tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfItalic = (unsigned char)_tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfUnderline = (unsigned char)_tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfStrikeOut = (unsigned char)_tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfCharSet = (unsigned char)_tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfOutPrecision = (unsigned char)_tcstol(pToken, NULL, 10);
    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfClipPrecision = (unsigned char)_tcstol(pToken, NULL, 10);

    // DEFAULT_QUALITY			   0
    // RASTER_FONTTYPE			   0x0001
    // DRAFT_QUALITY			     1
    // NONANTIALIASED_QUALITY  3
    // ANTIALIASED_QUALITY     4
    // CLEARTYPE_QUALITY       5
    // CLEARTYPE_COMPAT_QUALITY 6

    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfQuality = (unsigned char)_tcstol(pToken, NULL, 10);

    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;
    lfTmp.lfPitchAndFamily = (unsigned char)_tcstol(pToken, NULL, 10);

    if ((pToken = strtok_r(NULL, TEXT(","), &pWClast)) == NULL) return;

    _tcscpy(lfTmp.lfFaceName, pToken);

    memcpy((void *)lplf, (void *)&lfTmp, sizeof (LOGFONT));

  }
  return;
}


int propGetScaleList(double *List, size_t Size){

  TCHAR Buffer[128];
  TCHAR Name[] = TEXT("ScaleList");
  TCHAR *pWClast, *pToken;
  int   Idx = 0;

  ASSERT(List != NULL);
  ASSERT(Size > 0);

	if (GetRegistryString(Name, Buffer, sizeof(Buffer)/sizeof(TCHAR)) == 0){

    pToken = strtok_r(Buffer, TEXT(","), &pWClast);

    while(Idx < (int)Size && pToken != NULL){
      List[Idx] = _tcstod(pToken, NULL);
      Idx++;
      pToken = strtok_r(NULL, TEXT(","), &pWClast);
    }

    return(Idx);

  } else {
    return(0);
  }

}


long GetUTCOffset(void) {
#ifndef GNAV
  long utcoffset=0;
  // returns offset in seconds
  TIME_ZONE_INFORMATION TimeZoneInformation;
  GetTimeZoneInformation(&TimeZoneInformation);

  utcoffset = TimeZoneInformation.Bias*60;

  if (GetTimeZoneInformation(&TimeZoneInformation)==TIME_ZONE_ID_DAYLIGHT) {
    utcoffset += TimeZoneInformation.DaylightBias*60;
  }
  return utcoffset;
#else
  return UTCOffset;
#endif
}

