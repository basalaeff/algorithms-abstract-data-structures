#include "4.pyramid.hpp"

// ============================================================================
// ВЫЧИСЛЕНИЕ МАКСИМАЛЬНОЙ ВЫСОТЫ
// ============================================================================
// 1) Сортируем блоки по ширине.
// 2) После сортировки блоки одинаковой ширины стоят рядом.
// 3) Для каждой группы одинаковой ширины ищем максимальную высоту.
// 4) Добавляем максимум группы к ответу.
//
// Это корректно, потому что из блоков одинаковой ширины можно взять только
// один, а среди них выгоднее взять самый высокий.
// ============================================================================

long long calculateMaxPyramidHeight(Array& blocks) {
  sortBlocksByWidth(blocks);

  long long maxPyramidHeight = 0;
  int index = 0;

  while (index < blocks.length()) {
    long long currentWidth = getBlockWidth(blocks.get(index));
    long long maxHeight = getBlockHeight(blocks.get(index));

    index++;

    while (index < blocks.length() &&
           getBlockWidth(blocks.get(index)) == currentWidth) {
      long long currentHeight = getBlockHeight(blocks.get(index));

      if (currentHeight > maxHeight) {
        maxHeight = currentHeight;
      }

      index++;
    }

    maxPyramidHeight += maxHeight;
  }

  return maxPyramidHeight;
}
