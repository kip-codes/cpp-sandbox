//
// container.h
//
#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

class Container
{
protected:
  int size;
public:
  Container(int siz); //the only constr*cter
  virtual ~Container();
  int getSize() const;
  virtual int* insert(int num) = 0; // = 0 means it is "pure virtual"
  virtual int* erase(int num) = 0; // = 0 means it is "pure virtual"
  virtual int* find(int num) = 0; // = 0 means it is "pure virtual"
}; //class Container

#endif
