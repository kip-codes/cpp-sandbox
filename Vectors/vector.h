//
// vector.h
//
#ifndef VECTOR_H
#define VECTOR_H

#include "container.h"
#include "sortedvector.h"
using namespace std;

class Vector : public SortedVector //FIXME double-check permission for derived class
{
  int capacity;
protected:
  int* array;
  //void resize();
public:
  //SortedVector();
  //~SortedVector();
  int& operator[](const int index);  
  //int getCapacity() const;
  int* insert(int num);
  int* erase(int num);
  int* find(int num);
}; //class Vector

#endif

