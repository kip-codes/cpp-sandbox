// passenger.cpp

// Author: Sean Davis
#include <cstring>
#include <fstream>
#include "passenger.h"
using namespace std;


Passenger::Passenger() 
{
} // Passenger()


Passenger::Passenger(short flightNu, short ro, char sea, const char nam[]) : 
  flightNum(flightNu), row(ro), seat(sea)
{
  strcpy(name, nam);
}  // Passenger()


void Passenger::copyPassengers()
{
  Passenger passenger;

  ifstream inf("passengers.dat", ios::binary);
  ofstream outf("passengers2.dat", ios::binary);

  while(inf.read( (char*) &passenger, sizeof(Passenger)))
    outf.write((char*) &passenger, sizeof(Passenger));

  outf.close();
  inf.close();
}  // copyPassengers()

bool Passenger::operator==(const int fNum) const
{
  if(fNum == flightNum)
    return true;

  return false;
}//operator ==

bool Passenger::operator==(const char* nam) const
{
  if(strcmp(nam, name) == 0 ) 
    return true;

  return false; 
}//operator ==

void Passenger::operator!()
{
  flightNum = CANCELLED;
}//operator !

ostream& operator<<(ostream &os, const Passenger& P)
{
  os << P.name;
  return os;
}//ostream

