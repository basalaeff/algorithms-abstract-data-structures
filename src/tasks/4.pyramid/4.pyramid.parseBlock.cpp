#include "4.pyramid.hpp"

#include <sstream>
#include <stdexcept>

// ============================================================================
// ПОЛУЧЕНИЕ ШИРИНЫ БЛОКА
// ============================================================================
// 1) Создаем поток из строки блока.
// 2) Читаем первое число как ширину.
// 3) Возвращаем ширину.
// ============================================================================

long long getBlockWidth(const std::string& block) {
  std::istringstream blockStream(block);

  long long width = 0;
  long long height = 0;

  if (!(blockStream >> width >> height)) {
    // Ошибка: блок в массиве имеет неверный формат.
    throw std::runtime_error("Block has invalid format.");
  }

  return width;
}

// ============================================================================
// ПОЛУЧЕНИЕ ВЫСОТЫ БЛОКА
// ============================================================================
// 1) Создаем поток из строки блока.
// 2) Читаем ширину и высоту.
// 3) Возвращаем высоту.
// ============================================================================

long long getBlockHeight(const std::string& block) {
  std::istringstream blockStream(block);

  long long width = 0;
  long long height = 0;

  if (!(blockStream >> width >> height)) {
    // Ошибка: блок в массиве имеет неверный формат.
    throw std::runtime_error("Block has invalid format.");
  }

  return height;
}
