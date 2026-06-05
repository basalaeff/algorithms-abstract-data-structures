#include "Set.hpp"

// ============================================================================
// A3 SET_AT
// ============================================================================
// Проверка наличия элемента.
//
// true  -> найден
// false -> не найден
//
// Сложность: O(1)
// ============================================================================

bool Set::at(const std::string& value) const {
  int index = hash(value);

  Node* current = table_[index];

  while (current != nullptr) {
    if (current->data_ == value) {
      return true;
    }

    current = current->next_;
  }

  return false;
}