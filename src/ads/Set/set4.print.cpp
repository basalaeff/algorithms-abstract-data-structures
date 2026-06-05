#include "Set.hpp"
#include "iostream"

// ============================================================================
// A4 PRINT
// ============================================================================
// Вывод всех элементов множества.
// ============================================================================

void Set::print() const {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Node* current = table_[i];

    while (current != nullptr) {
      std::cout << current->data_ << std::endl;

      current = current->next_;
    }
  }
}