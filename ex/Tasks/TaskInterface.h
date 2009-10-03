/* Generated by Together */

#ifndef TASKINTERFACE_H
#define TASKINTERFACE_H

struct AIRCRAFT_STATE;
struct GEOPOINT;
class TaskPoint;

class TaskInterface {
public:

  virtual void setActiveTaskPoint(unsigned) = 0;
  
  virtual TaskPoint* getActiveTaskPoint() = 0;

  double get_active_bearing(const AIRCRAFT_STATE &);

  double get_active_distance(const AIRCRAFT_STATE &);

  virtual void report(const GEOPOINT &location) = 0;

  virtual bool update_sample(const AIRCRAFT_STATE &, const AIRCRAFT_STATE&) = 0;

};
#endif //TASKINTERFACE_H
