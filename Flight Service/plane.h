#ifndef PLANE_H
#define	PLANE_H
#include <fstream>
#include "linkedlist.h"

using namespace std;


class Plane
{
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  int rows;
  int width;
  int reserved;
  LinkedList* passengers;
  int getRow() const;
  void showGrid() const;
  int flightNumber;
public:
  Plane(int flightNum);
  Plane(ifstream &inf);
  ~Plane();
  void addFlight();
  void writePlane(ofstream &outf) const;
  friend ifstream& operator>>(ifstream &inf, Plane& plane);
  friend ostream& operator<<(ostream& os, const Plane& plane);  
  Plane& operator++();
  Plane& operator--(int dummy);
  Plane& operator!();
  bool findPassenger(const char* poi, const int fNum) const;
}; // class Plane

#endif	// PLANE_H


