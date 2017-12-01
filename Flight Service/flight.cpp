// Author: Sean Davis

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"

using namespace std;

Flight& Flight::operator++(int dummy)
{
  ++(*plane);
  return *this;
}// operator ++


Flight::~Flight()
{
  ofstream outf("flights2.csv", ios::app);
  outf << flightNum << ',' << origin << ',' << destination << ',';
  plane->writePlane(outf);
  outf.close();
  delete plane;
}  // freeFlight()

void Flight::addFlight()
{
  cout << "\nFlight number to add: ";
  cin >> flightNum;
  cin.ignore(TEN, '\n');
  cout << "Origin: ";
  cin.getline(origin, MAX_CITY_LENGTH);
  cout << "Destination: ";
  cin.getline(destination, MAX_CITY_LENGTH);
  plane = new Plane(flightNum);
  plane->addFlight();
}  // addFlight()

int Flight::getFlightNumber() const
{
  return flightNum;
}  // getFlightNumber()

ostream& operator<<(ostream& os, const Flight& flight)
{
  os << left << setw(Flight::FLIGHT_NUM_SPACE) << flight.flightNum << ' ' 
    << setw(Flight::MAX_CITY_LENGTH) << flight.origin << ' '  
    << flight.destination << endl;

  return os;
}//operator <<

ifstream& operator>>(ifstream& inf, Flight& flight)
{
  inf >> flight.flightNum;
  inf.ignore(Flight::TEN, ',');
  inf.getline(flight.origin, Flight::MAX_CITY_LENGTH, ',');
  inf.getline(flight.destination, Flight::MAX_CITY_LENGTH, ',');
  flight.plane = new Plane(flight.flightNum);
  inf >> *(flight.plane);
  
  return inf;
}// operator >>

Flight& Flight::operator!()
{
  !(*plane);
  return *this;
}  // rer();

Flight& Flight::operator--()
{
  (*plane)--;
  return *this;
} //oper

bool Flight::findPassenger(char* poi) const
{
  return plane->findPassenger(poi, flightNum);  
}//findPassenger()
