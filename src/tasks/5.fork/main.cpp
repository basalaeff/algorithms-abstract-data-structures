#include <iostream>
#include <sstream>

#include "../../ads/BinarySearchTree/BinarySearchTree.hpp"

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
    BinarySearchTree<int> tree;
    std::stringstream ss(query);
    int x;

    // Флаг:
    // удалось ли считать хотя бы одно число
    bool hasNumbers = false;

    // Читаем числа
    while (ss >> x) {
      hasNumbers = true;

      if (x == 0) {
        break;
      }

      tree.insert(x);
    }

    // Если числа вообще не считались
    if (!hasNumbers) {
      throw std::invalid_argument("invalid query");
    }

    // Проверка мусора после чисел
    if (!ss.eof()) {
      throw std::invalid_argument("invalid input");
    }

    tree.printTwoChildren();
  }

  // Обработка всех стандартных исключений
  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}