#include <iostream>

#include "3.mic.hpp"

// ============================================================================
// MAIN
// ============================================================================
// Запуск:
// ./mic --q '{{1, 2, 3}, {2, 3, 4}, {5, 6}, {3, 4, 5}}'
// ============================================================================

int main(int argc, char* argv[]) {
  std::string query;

  // ==========================================================================
  // ЧТЕНИЕ АРГУМЕНТОВ КОМАНДНОЙ СТРОКИ
  // ==========================================================================

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (arg == "--q") {
      if (i + 1 >= argc) {
        std::cerr << "Error: query not specified." << std::endl;
        return 1;
      }

      query = argv[++i];
    }

    else {
      std::cerr << "Error: unknown argument: " << arg << std::endl;
      return 1;
    }
  }

  if (query.empty()) {
    std::cerr << "Error: query not specified." << std::endl;
    return 1;
  }

  // ==========================================================================
  // ВЫПОЛНЕНИЕ ЗАДАЧИ
  // ==========================================================================

  try {
    Mic mic;

    std::cout << mic.run(query) << std::endl;
  }

  catch (const std::exception& error) {
    std::cerr << "Error: " << error.what() << std::endl;

    return 1;
  }

  return 0;
}
