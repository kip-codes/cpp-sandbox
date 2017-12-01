// BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree;

template <typename T>
class BSTNode
{
  BSTNode<T>* left;
  BSTNode<T>* right;
  T data;
public:
  BSTNode(BSTNode<T>* l, BSTNode<T>* r, const T& d) : left(l), right(r), data(d)
    {};
  friend class BinarySearchTree<T>;

}; //class BSTNode

template <typename T>
class BinarySearchTree
{
  BSTNode<T>* root;
  void insert(BSTNode<T>* t, const T& value);
  void find(BSTNode<T>* t, const T& value) const;
  BSTNode<T>* findMin(BSTNode<T>* t) const;
  void remove(BSTNode<T> * &t, const T &value);
  void inOrder(BSTNode<T>* t) const;
  void postOrder(BSTNode<T>* t) const;
  void makeEmpty(BSTNode<T>* t);
public:
  BinarySearchTree() : root(NULL)
    {};
  ~BinarySearchTree();
  void makeEmpty();
  void insert(const T& value);
  void find(const T& value) const;
  void remove(const T& value);
  void inOrder() const;
  void postOrder() const;


}; //class BST


#include "BinarySearchTree.cpp"
#endif
