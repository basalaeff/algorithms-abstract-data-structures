#pragma once
#include <string>

// ============================================================================
// УЗЕЛ ОДНОСВЯЗНОГО СПИСКА
// ============================================================================
// Класс Node - узел. Он содержит строковое значение и указатель на следующий узел.
class Node {
 public:
  std::string data_;
  Node* next_;

  Node(const std::string& value, Node* nextNode = nullptr)
      : data_(value), next_(nextNode) {}
};
