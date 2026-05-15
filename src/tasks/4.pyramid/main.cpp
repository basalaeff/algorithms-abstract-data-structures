#include <exception>
#include <iostream>

#include "4.pyramid.hpp"

// ============================================================================
// MAIN
// ============================================================================
// Запуск:
// ./pyramid
//
// Формат ввода:
// N
// width height
// width height
// ...
//
// Формат вывода:
// максимальная высота пирамиды
// ============================================================================

int main() {
  try {
    std::cout << runPyramid(std::cin) << std::endl;
  }

  catch (const std::exception& error) {
    // Ошибка: описание причины сбоя.
    std::cerr << "Error: " << error.what() << std::endl;

    return 1;
  }

  return 0;
}
