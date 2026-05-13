#include <iostream>

#include "1.rpn.hpp"

int main(int argc, char* argv[]) {
  std::string query;

  // ========================================================================
  // Чтение аргументов командной строки
  // ========================================================================
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    // Если найден флаг --q
    if (arg == "--q") {
      // Проверяем наличие выражения после флага
      if (i + 1 >= argc) {
        std::cerr << "Error: expression not specified." << std::endl;
        return 1;
      }

      // Сохраняем выражение
      query = argv[++i];
    }
  }

  // ========================================================================
  // Выполнение запроса
  // ========================================================================

  if (query.empty()) {
    std::cerr << "Error: query not specified." << std::endl;
    return 1;
  }

  try {
    double result = evaluatePostfix(query);

    std::cout << "Result: " << result << std::endl;
  }

  // Обработка всех стандартных исключений
  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}