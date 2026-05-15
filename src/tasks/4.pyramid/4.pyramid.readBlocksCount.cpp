#include "4.pyramid.hpp"

#include <istream>
#include <stdexcept>

// ============================================================================
// ЧТЕНИЕ КОЛИЧЕСТВА БЛОКОВ
// ============================================================================
// 1) Читаем первое число входных данных.
// 2) Проверяем, что количество блоков находится в допустимом диапазоне.
// 3) Возвращаем количество блоков.
// ============================================================================

int readBlocksCount(std::istream& input) {
  int blocksCount = 0;

  if (!(input >> blocksCount)) {
    // Ошибка: количество блоков не указано.
    throw std::runtime_error("Blocks count not specified.");
  }

  if (blocksCount < 1 || blocksCount > 100000) {
    // Ошибка: количество блоков должно быть от 1 до 100000.
    throw std::out_of_range("Blocks count must be from 1 to 100000.");
  }

  return blocksCount;
}
