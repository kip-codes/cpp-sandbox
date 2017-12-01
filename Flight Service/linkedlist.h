// linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

class ListNode;

class LinkedList
{
  ListNode* head;
  friend ostream& operator<<(ostream &os, LinkedList& list);
public:
  static const int EMPTY = -1;
  void initialize(const int seats);
  ~LinkedList();
  int operator[](const int seatNum) const;
  int& operator[](const int seatNum); //allows the offset to be changed
}; //class LinkedList`

class ListNode
{
  int offset;
  ListNode* next; //pointer to another ListNode
  ListNode(const int n, ListNode* ptr); //MUST BE PRIVATE
  friend ostream& operator<<(ostream &os, LinkedList& list);
public:
  friend class LinkedList;
}; //class ListNode

#endif
