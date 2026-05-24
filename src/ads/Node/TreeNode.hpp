#pragma once

// ============================================================================
// УЗЕЛ БИНАРНОГО ДЕРЕВА
// ============================================================================
// Класс TreeNode - узел бинарного дерева. Он содержит целочисленное значение,
// указатель на левый дочерний узел и указатель на правый дочерний узел.
template <typename T>
class TreeNode {
 public:
  T data_;
  TreeNode<T>* left_;
  TreeNode<T>* right_;

  TreeNode(T value, TreeNode<T>* leftNode = nullptr,
           TreeNode<T>* rightNode = nullptr)
      : data_(value), left_(leftNode), right_(rightNode) {}
};