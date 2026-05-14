#include "../../ads/g.Set/g.Set.hpp"
#include "iostream"

// ============================================================================
// MAIN
// ============================================================================
// Запуск:
//

// ============================================================================

int main(int argc, char* argv[]) {
  try {
    std::string filename;

    std::string query;

    // =========================================================================
    // ЧТЕНИЕ АРГУМЕНТОВ
    // =========================================================================

    for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];

      if (arg == "--file" && i + 1 < argc) {
        filename = argv[++i];
      }

      else if (arg == "--query" && i + 1 < argc) {
        query = argv[++i];
      }
    }

    // Проверка аргументов
    if (filename.empty()) {
      throw std::runtime_error("File path not specified.");
    }

    if (query.empty()) {
      throw std::runtime_error("Query not specified.");
    }

    // =========================================================================
    // СОЗДАНИЕ SET
    // =========================================================================

    Set set;

    // =========================================================================
    // ЗАГРУЗКА ДАННЫХ
    // =========================================================================

    set.loadFromFile(filename);

    // =========================================================================
    // ОБРАБОТКА QUERY
    // =========================================================================

    // PRINT
    if (query == "PRINT") {
      set.print();

      return 0;
    }

    // Ищем первый пробел
    size_t spacePos = query.find(' ');

    // Если команда без аргумента
    if (spacePos == std::string::npos) {
      throw std::runtime_error("Invalid query.");
    }

    // Команда
    std::string command = query.substr(0, spacePos);

    // Значение
    std::string value = query.substr(spacePos + 1);

    // =========================================================================
    // SETADD
    // =========================================================================

    if (command == "SETADD") {
      set.add(value);
      set.saveToFile(filename);

      std::cout << "Added: " << value << std::endl;
    }

    // =========================================================================
    // SETDEL
    // =========================================================================

    else if (command == "SETDEL") {
      set.del(value);
      set.saveToFile(filename);

      std::cout << "Deleted: " << value << std::endl;
    }

    // =========================================================================
    // SET_AT
    // =========================================================================

    else if (command == "SET_AT") {
      if (set.at(value)) {
        std::cout << "FOUND" << std::endl;
      }

      else {
        std::cout << "NOT FOUND" << std::endl;
      }
    }

    // =========================================================================
    // НЕИЗВЕСТНАЯ КОМАНДА
    // =========================================================================

    else {
      throw std::runtime_error("Unknown command.");
    }
  }

  catch (const std::exception& error) {
    std::cerr << "Error: " << error.what() << std::endl;

    return 1;
  }

  return 0;
}