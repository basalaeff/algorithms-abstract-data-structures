#include <istream>
#include <stdexcept>
#include <string>

#include "4.pyramid.hpp"

// ============================================================================
// ЧТЕНИЕ БЛОКОВ
// ============================================================================
// 1) Для каждого блока читаем ширину и высоту.
// 2) Проверяем ограничения 1 <= width, height <= 10^9.
// 3) Преобразуем блок в строку "width height".
// 4) Добавляем строку в Array через существующий метод addToTheEnd.
// ============================================================================

void readBlocks(std::istream& input, Array& blocks, int blocksCount) {
  for (int i = 0; i < blocksCount; i++) {
    long long width = 0;
    long long height = 0;

    if (!(input >> width >> height)) {
      // Ошибка: данные блока не указаны полностью.
      throw std::runtime_error("Block data not specified.");
    }

    if (width < 1 || width > 1000000000LL || height < 1 ||
        height > 1000000000LL) {
      // Ошибка: ширина и высота блока должны быть от 1 до 1000000000.
      throw std::out_of_range("Block values must be from 1 to 1000000000.");
    }

    blocks.addToTheEnd(std::to_string(width) + " " + std::to_string(height));
  }
}
