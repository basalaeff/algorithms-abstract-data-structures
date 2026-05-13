#include "d.Stack.hpp"
#include <fstream>
#include <stdexcept>

// ============================================================================
// СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================

void Stack::saveToFile(const std::string& filename) const {
  std::ofstream outFile(filename);
  if (!outFile.is_open()) {
    throw std::out_of_range("Cannot open file for writing: " + filename);
  }
  Node* temp = top_;
  while (temp != nullptr) {
    outFile << temp->data_ << std::endl;
    temp = temp->next_;
  }
  outFile.close();
}