#include "4.pyramid.hpp"

// ============================================================================
// ВОССТАНОВЛЕНИЕ ПИРАМИДЫ
// ============================================================================
// Пирамида хранится внутри Array:
// - для индекса rootIndex левый потомок находится в 2 * rootIndex + 1;
// - правый потомок находится в 2 * rootIndex + 2.
//
// В максимальной пирамиде ширина родителя должна быть не меньше ширины потомков.
// Если один из потомков шире родителя, самый широкий элемент поднимается наверх,
// а heapify продолжается ниже.
// ============================================================================

void heapify(Array& blocks, int heapSize, int rootIndex) {
  int largestIndex = rootIndex;
  int leftIndex = 2 * rootIndex + 1;
  int rightIndex = 2 * rootIndex + 2;

  if (leftIndex < heapSize &&
      getBlockWidth(blocks.get(leftIndex)) >
          getBlockWidth(blocks.get(largestIndex))) {
    largestIndex = leftIndex;
  }

  if (rightIndex < heapSize &&
      getBlockWidth(blocks.get(rightIndex)) >
          getBlockWidth(blocks.get(largestIndex))) {
    largestIndex = rightIndex;
  }

  if (largestIndex != rootIndex) {
    swapBlocks(blocks, rootIndex, largestIndex);
    heapify(blocks, heapSize, largestIndex);
  }
}
