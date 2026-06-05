#include "Set.hpp"

// ============================================================================
// A2 SETDEL
// ============================================================================
// Удаление элемента из множества.
//
// 1) Вычисляется hash.
// 2) Проходим список.
// 3) Если элемент найден:
//    - меняются указатели;
//    - память освобождается.
//
// Сложность: O(1)
// ============================================================================

void Set::del(const std::string& value) {
  int index = hash(value);

  Node* current = table_[index];

  Node* previous = nullptr;

  while (current != nullptr) {
    if (current->data_ == value) {
      // Если удаляется первый элемент
      if (previous == nullptr) {
        table_[index] = current->next_;
      }

      // Если элемент внутри списка
      else {
        previous->next_ = current->next_;
      }

      delete current;

      return;
    }

    previous = current;

    current = current->next_;
  }
}