#include "a.Array.hpp"
#include <fstream>

// ============================================================================
// СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================
void Array::saveToFile(const std::string& filename) const {
  std::ofstream outFile(filename);
  if (!outFile.is_open()) {
    throw std::runtime_error("Cannot open file for writing: " + filename);
  }
  for (int i = 0; i < size_; i++) {
    outFile << data_[i] << std::endl;
  }
  outFile.close();
}