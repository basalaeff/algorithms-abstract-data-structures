#include "d.Stack.hpp"
#include <fstream>
#include <stdexcept>

// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================

void Stack::loadFromFile(const std::string& filename) {
  // Очищаем текущий стек перед загрузкой
  while (top_ != nullptr) {
    pop();
  }

  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    throw std::out_of_range("Cannot open file for reading: " + filename);
  }

  std::string line;
  while (std::getline(inFile, line)) {
    if (!line.empty()) {
      push(line);
    }
  }
  inFile.close();

  // Переворачиваем стек обратно
  if (top_ == nullptr || top_->next_ == nullptr) {
    return;
  }

  Node* prev = nullptr;
  Node* curr = top_;
  Node* next = nullptr;

  while (curr != nullptr) {
    next = curr->next_;
    curr->next_ = prev;
    prev = curr;
    curr = next;
  }

  top_ = prev;  // теперь порядок правильный
}