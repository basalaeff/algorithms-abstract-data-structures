#include "fstream"
#include "g.Set.hpp"

// ============================================================================
// СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================
// Сохраняет все элементы множества в файл.
//
// 1) Открывается файл.
// 2) Проходим по всей hash table.
// 3) Записываем каждый элемент в новую строку.
//
// ===========================================================

void Set::saveToFile(const std::string& filename) const {
  std::ofstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Failed to save file.");
  }

  for (int i = 0; i < TABLE_SIZE; i++) {
    Node* current = table_[i];

    while (current != nullptr) {
      file << current->data_ << std::endl;

      current = current->next_;
    }
  }

  file.close();
}