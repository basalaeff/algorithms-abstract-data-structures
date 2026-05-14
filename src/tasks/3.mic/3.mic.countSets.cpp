#include <cctype>
#include <stdexcept>

#include "3.mic.hpp"

// ============================================================================
// ПОДСЧЕТ МНОЖЕСТВ
// ============================================================================
// Подсчитывает количество внутренних множеств во входной строке.
//
// Пример:
// {{1, 2}, {3, 4}, {5}} -> 3
// ============================================================================

int Mic::countSets(const std::string& query) const {
  int depth = 0;
  int count = 0;

  for (int i = 0; i < static_cast<int>(query.length()); i++) {
    char symbol = query[i];

    if (symbol == '{') {
      depth++;

      if (depth == 2) {
        count++;
      }
    }

    else if (symbol == '}') {
      depth--;

      if (depth < 0) {
        // Неверный порядок фигурных скобок.
        throw std::runtime_error("Invalid braces order.");
      }
    }

    else if (!std::isspace(static_cast<unsigned char>(symbol)) && depth == 0) {
      // Неожиданный символ вне внешнего множества.
      throw std::runtime_error("Unexpected symbol outside outer set.");
    }
  }

  if (depth != 0) {
    // Неверное количество фигурных скобок.
    throw std::runtime_error("Invalid braces count.");
  }

  if (count < 2) {
    // Требуется как минимум два множества.
    throw std::runtime_error("At least two sets are required.");
  }

  return count;
}
