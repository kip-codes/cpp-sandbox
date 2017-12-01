//
// sortedvector.h
//
#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H

#include "container.h"
using namespace std;

class SortedVector : public Container //FIXME double-check permission for derived class
{
  int capacity;
protected:
  int* array;
  void resize();
public:
  SortedVector();
  ~SortedVector();
  const int& operator[](const int index) const;  
  int getCapacity() const;
  virtual int* insert(int num);
  virtual int* erase(int num);
  virtual int* find(int num);
}; //class SortedVector

#endif

