#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "../Node/TreeNode.hpp"

template <typename T>
class BinarySearchTree {
 private:
  TreeNode<T>* root_;

  TreeNode<T>* insert(TreeNode<T>* node, T value);
  void clear(TreeNode<T>* node);

  void collect(TreeNode<T>* node, std::vector<T>& out) const;

 public:
  BinarySearchTree() : root_(nullptr){};
  ~BinarySearchTree() { clear(root_); };

  void insert(T value);

  void printTwoChildren() const;
};
#include "bst.clear.tpp"
#include "bst.collect.tpp"
#include "bst.insert.tpp"
#include "bst.printTwoChildren.tpp"
