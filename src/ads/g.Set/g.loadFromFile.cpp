#include "g.Set.hpp"
#include "fstream"


// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
// Загружает строки из файла в множество.
// Каждая строка файла = отдельный элемент множества.
// ============================================================================

void Set::loadFromFile(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file.");
  }

  std::string line;

  while (std::getline(file, line)) {
    add(line);
  }

  file.close();
}