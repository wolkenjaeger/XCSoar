/* Generated by Together */

#include "AATPoint.hpp"

GEOPOINT AATPoint::get_reference_scored_origin()
{
  if (getActiveState() == BEFORE_ACTIVE) {
    return get_search_max().Location;
  } else {
    return TargetLocation;
  }
}

GEOPOINT AATPoint::get_reference_scored_destination()
{
  if (getActiveState() == CURRENT_ACTIVE) {
    return TargetLocation;
  } else {
    return get_search_max().Location;
  }
}

GEOPOINT AATPoint::get_reference_travelled_destination()
{
  return get_search_max().Location;
}

GEOPOINT AATPoint::get_reference_travelled_origin()
{
  return get_search_max().Location;
}

GEOPOINT AATPoint::get_reference_remaining_origin()
{
  if (getActiveState() == BEFORE_ACTIVE) {
    return get_search_max().Location;
  } else {
    return TargetLocation;
  }
}

GEOPOINT AATPoint::get_reference_remaining_destination()
{
  if (getActiveState() == BEFORE_ACTIVE) {
    return get_search_max().Location;
  } else {
    return TargetLocation;
  }
}

double 
AATPoint::getElevation() 
{
  // TODO: look up elevation of target and use that instead
  return Elevation; // + SAFETYTERRAIN
}
