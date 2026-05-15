#include "4.pyramid.hpp"

// ============================================================================
// ОБМЕН БЛОКОВ
// ============================================================================
// 1) Получаем два элемента через существующий метод get.
// 2) Записываем их на места друг друга через существующий метод replaceByIndex.
// ============================================================================

void swapBlocks(Array& blocks, int firstIndex, int secondIndex) {
  if (firstIndex == secondIndex) {
    return;
  }

  std::string firstBlock = blocks.get(firstIndex);
  std::string secondBlock = blocks.get(secondIndex);

  blocks.replaceByIndex(firstIndex, secondBlock);
  blocks.replaceByIndex(secondIndex, firstBlock);
}
