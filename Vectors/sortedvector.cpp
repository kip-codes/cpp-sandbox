//
// sortedvector.cpp
//
#include <iostream>
#include "sortedvector.h"

SortedVector::SortedVector()
  :  Container(0)
{
  array = NULL;
}//SortedVector()

SortedVector::~SortedVector()
{
  delete[] array;
}//~SortedVector()

const int& SortedVector::operator[](const int index) const
{
  if(getSize() - 1 < index || index < 0)
  { 
    cout << "Virtual seg fault.\n";
    return array[0];
  }//if
  
  return array[index];
}//operator []

void SortedVector::resize()
{
  if(capacity < 1)
  {
    array = new int[1];
    array[0] = 0;
    capacity = 1;
    return;
  }//if
  
  int* temp = new int[capacity*2];
  int k = getSize();
  
  for(int i = 0; i < k; i++)
    temp[i] = array[i];

  for(int j = k; j < capacity; j++)
    temp[j] = 0;

  delete[] array;
  array = temp;
  capacity *= 2; 
}//resize()

int SortedVector::getCapacity() const
{
  return capacity;
}//getCapacity()

int* SortedVector::insert(int num)
{
  int k = getSize();
  while(capacity < k + 1)
    resize();
  
  int i;

  for(i = 0; i < capacity; i++)
  {
    if(num < array[0] || (!(array[i] < num) && !(num < array[i])))
    {  
      for(int j = k; j > i; j--)
        array[j] = array[j-1];
        

      array[i] = num;
      size++;
      return &array[i];
    }//if

    else if ((array[i] < num) && (num < array[i+1])) //else if
    {
      for(int j = k; j > i+1; j--)
        array[j] = array[j-1];


      array[i+1] = num;
      size++;
      return &array[i+1];
    }//else
  }//for

  array[k] = num;
  size++;
  return &array[k];
}//insert()

int* SortedVector::erase(int num)
{
  int k = getSize();
  for(int i = 0; i < k; i++)
  {
    if (!(array[i] < num) && !(num < array[i]))
    {
      for(int j = i; j < k - 1; j++)
        array[j] = array[j+1];

      array[k-1] = 0;
      size--;

      if(i < capacity)
        return &array[i];
   
      else
        return NULL;
    }//if
  }//for

  return NULL;
}//erase()
int* SortedVector::find(int num)
{
  int k = getSize();
  
  if(array[k-1] < num)
    return NULL;

  for(int i = 0; i < k; i++)
  {
    if(!(array[i] < num) && !(num < array[i]))
    {
      for(int j = 0; j < i; j++)
        cout << array[j] << " ";
      return &array[i];
    }//if
  }//for

  return NULL;
}//find()

