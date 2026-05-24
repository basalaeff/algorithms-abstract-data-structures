#include <fstream>

#include "a.Array.hpp"

// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
void Array::loadFromFile(const std::string& filename) {
  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    throw std::runtime_error("Cannot open file for reading: " + filename);
  }
  std::string line;
  size_ = 0;
  while (getline(inFile, line) && size_ < maxCapacity_) {
    data_[size_] = line;
    size_++;
  }
  inFile.close();
}
