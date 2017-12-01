//
// container.cpp
//
#include <iostream>
#include "container.h"

// Input:
//  int, desired size to set Container
// Output:
//  none
// Both directly derived class constr*ctors will have to call this function from their initialization list.
Container::Container(int siz)
{
  size = siz;
}// Container(int)


// Input:
//  none
// Output:
//  none
// A virtual destr*ctor is required whenever a class has any virtual method
Container::~Container()
{
}// ~Container()


// Input:
//  none
// Output:
//  int, the size currently in Container
// Returns the number of items currently stored in the container, i.e. the value of size
int Container::getSize() const
{
  return size;
}// getSize()

