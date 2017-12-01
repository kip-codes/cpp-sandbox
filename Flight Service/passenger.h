// passenger.h

#ifndef PASSENGER_H
#define	PASSENGER_H

#include "plane.h"

class Passenger 
{
public:
  static const int NAME_LENGTH = 30;
  static const int CANCELLED = -1;
private:
  short flightNum;
  short row; 
  char seat;
  char name[NAME_LENGTH];
  friend ostream& operator<<(ostream &os, const Passenger& P);
  friend ifstream& operator>>(ifstream &inf, Plane& plane);  
public:
  Passenger();
  Passenger(short flightNu, short ro, char sea, const char nam[]);
  static void copyPassengers(); 
  bool operator==(const int fNum) const;
  bool operator==(const char* nam) const;
  void operator!();
}; // class passengers 

#endif	// PASSENGERS_H

