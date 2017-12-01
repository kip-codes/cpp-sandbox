// BinarySearchTree.cpp


#include <cassert>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{

}//~BinarySearchTree()


template <typename T>
void BinarySearchTree<T>::makeEmpty()
{

}//makeEmpty()


template <typename T>
void BinarySearchTree<T>::makeEmpty(BSTNode<T>* t)
{

}//makeEmpty() recursive


template <typename T>
void BinarySearchTree<T>::insert(const T& value)
{
  if(!root) root = new BSTNode<T>(NULL, NULL, value);
  else //else
    insert(root, value);
}//insert() NON-recursive


template <typename T>
void BinarySearchTree<T>::insert(BSTNode<T> *t, const T &value)
{
  assert(t->data != value);

  //BASE CASE(s)
  if (!t->left && value < t->data) 
  {
    t->left = new BSTNode<T>(NULL, NULL, value);
    return;
  }//if

  if (!t->right && t->data < value)
  {
    t->right = new BSTNode<T>(NULL, NULL, value);
    return; 
  }//if

  if
    (value < t->data) insert(t->left, value);

  else //else
    insert(t->right, value);
}//insert() recursive


template <typename T>
void BinarySearchTree<T>::find(const T& value) const
{
  assert(root != __null);

}//find()


template <typename T>
void BinarySearchTree<T>::find(BSTNode<T> *t, const T &value) const
{

}//find () recursive


template <typename T>
BSTNode<T>* BinarySearchTree<T>::findMin(BSTNode<T> *t) const
{

}//findMin() recursive?


template <typename T>
void BinarySearchTree<T>::remove(const T& value)
{
  assert(root);

}//remove()


template <typename T>
void BinarySearchTree<T>::remove(BSTNode<T> * &t, const T &value)
{
  assert(t != __null);

}//remove() recursive


template <typename T>  
void BinarySearchTree<T>::inOrder() const
{


}//inOrder()


template <typename T>
void BinarySearchTree<T>::inOrder(BSTNode<T>* t) const
{

}//inOrder() recursive


template <typename T>
void BinarySearchTree<T>::postOrder() const
{


}//postOrder()


template <typename T>
void BinarySearchTree<T>::postOrder(BSTNode<T>* t) const
{


}//postOrder() recursive
