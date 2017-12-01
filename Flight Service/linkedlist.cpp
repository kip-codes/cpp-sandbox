#include <iostream>
#include <iomanip>
#include <cstring>

#include "linkedlist.h"

using namespace std;

ListNode::ListNode(const int n, ListNode* ptr)
{ 
  offset = n;
  next = ptr;
}//ListNode()

// seats will be width
void LinkedList::initialize(const int seats) 
{
  head = NULL;

  for(int i = 0; i < seats; i++)
  {
    head = new ListNode(EMPTY, head);
  }//for
}//initialize()

//Deallocates the linked list from memory
LinkedList::~LinkedList()
{
  ListNode* tracer;

  while (head)
  {
     tracer = head;
     head = head->next;
     delete tracer;
  }//while
}//~LinkedList()

int LinkedList::operator[](const int seatNum) const
{
 // ListNode* tracer = head;
  ListNode* tracer;
  int i = 0;
   
  for (tracer = head; i < seatNum; i++, tracer = tracer->next);
//for (int i = 0; i < seatNum; i++)
    //tracer = tracer->next;

  return tracer->offset;
}//operator[] const


int& LinkedList::operator[](const int seatNum)
{
  ListNode* tracer;
  int i = 0;

  for (tracer = head; i < seatNum; i++, tracer = tracer->next);
  //ListNode* tracer = head;
  //for (int i = 0; i < seatNum; i++)
    //tracer = tracer->next;

  return tracer->offset;
}//operator[] ACTIVE

ostream& operator<<(ostream &os, LinkedList& list)
{
  ListNode* tracer;
  
  for (tracer = list.head; tracer != NULL; tracer = tracer->next)
  { 
    if (tracer->offset == LinkedList::EMPTY)
      os << '-';
    else //else
      os << 'X';
  }//if

  return os;
}// operator <<
