#include <iostream>

#include "1.rpn.hpp"

int main(int argc, char *argv[]) {
  std::string query;

  // Чтение аргументов командной строки
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--q" && i + 1 < argc) {
      query = argv[++i];
    }
  }

  // ================================================
  // Выполнение запроса
  // ================================================
  if (!query.empty()) {
    std::string expression(query);
    int result = evaluatePostfix(expression);
    std::cout << "Result: " << result << std::endl;
  } else {
    std::cout << "Error: query not specified." << std::endl;
    return 1;
  }
  return 0;
}