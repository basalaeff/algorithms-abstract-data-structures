#include "4.pyramid.hpp"

// ============================================================================
// ЗАПУСК
// ============================================================================
// 1) Читаем количество блоков.
// 2) Создаем Array нужной вместимости.
// 3) Читаем блоки в Array.
// 4) Вычисляем максимальную высоту пирамиды.
// ============================================================================

long long runPyramid(std::istream& input) {
  int blocksCount = readBlocksCount(input);
  Array blocks(blocksCount);

  readBlocks(input, blocks, blocksCount);

  return calculateMaxPyramidHeight(blocks);
}
