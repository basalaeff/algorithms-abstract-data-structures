#include <cctype>
#include <limits>
#include <sstream>
#include <stdexcept>

#include "3.mic.hpp"

namespace {

// ============================================================================
// ПРОПУСК ПРОБЕЛОВ
// ============================================================================
// Передвигает позицию до первого непробельного символа.
// ============================================================================

void skipSpaces(const std::string& query, int& position) {
  while (position < static_cast<int>(query.length()) &&
         std::isspace(static_cast<unsigned char>(query[position]))) {
    position++;
  }
}

// ============================================================================
// ПРОВЕРКА СИМВОЛА
// ============================================================================
// Проверяет, что в текущей позиции находится ожидаемый символ.
// ============================================================================

void expectSymbol(const std::string& query, int& position, char expected,
                  const std::string& message) {
  skipSpaces(query, position);

  if (position >= static_cast<int>(query.length()) ||
      query[position] != expected) {
    throw std::runtime_error(message);
  }

  position++;
}

// ============================================================================
// ЧТЕНИЕ НАТУРАЛЬНОГО ЧИСЛА
// ============================================================================
// Читает натуральное число и возвращает его строковое представление.
// ============================================================================

std::string readNaturalNumber(const std::string& query, int& position) {
  skipSpaces(query, position);

  if (position >= static_cast<int>(query.length()) ||
      !std::isdigit(static_cast<unsigned char>(query[position]))) {
    // Ожидается натуральное число.
    throw std::runtime_error("Expected natural number.");
  }

  unsigned long long value = 0;

  while (position < static_cast<int>(query.length()) &&
         std::isdigit(static_cast<unsigned char>(query[position]))) {
    int digit = query[position] - '0';

    if (value > (std::numeric_limits<unsigned long long>::max() - digit) / 10) {
      // Натуральное число слишком большое.
      throw std::runtime_error("Natural number is too large.");
    }

    value = value * 10 + digit;
    position++;
  }

  if (value == 0) {
    // Натуральное число должно быть больше нуля.
    throw std::runtime_error("Natural number must be greater than zero.");
  }

  return std::to_string(value);
}

}  // namespace

// ============================================================================
// РАЗБОР СТРОКИ
// ============================================================================
// Разбирает строку запроса и создает Set для каждого входного множества.
// ============================================================================

void Mic::parse(const std::string& query) {
  clear();

  setsCount_ = countSets(query);
  sets_ = new Set[setsCount_];
  outputs_ = new std::string[setsCount_];

  int position = 0;
  int currentSet = 0;

  // Ожидается открывающая фигурная скобка внешнего множества.
  expectSymbol(query, position, '{', "Expected outer opening brace.");

  while (currentSet < setsCount_) {
    // Ожидается открывающая фигурная скобка множества.
    expectSymbol(query, position, '{', "Expected set opening brace.");

    std::ostringstream output;
    bool hasElements = false;

    output << "{";
    skipSpaces(query, position);

    while (position < static_cast<int>(query.length()) &&
           query[position] != '}') {
      std::string value = readNaturalNumber(query, position);

      if (!sets_[currentSet].at(value)) {
        sets_[currentSet].add(value);

        if (hasElements) {
          output << ", ";
        }

        output << value;
        hasElements = true;
      }

      skipSpaces(query, position);

      if (position >= static_cast<int>(query.length())) {
        // Ожидается запятая или закрывающая фигурная скобка множества.
        throw std::runtime_error("Expected comma or set closing brace.");
      }

      if (query[position] == ',') {
        position++;
        skipSpaces(query, position);

        if (position < static_cast<int>(query.length()) &&
            query[position] == '}') {
          // Ожидается натуральное число.
          throw std::runtime_error("Expected natural number.");
        }
      }

      else if (query[position] != '}') {
        // Ожидается запятая или закрывающая фигурная скобка множества.
        throw std::runtime_error("Expected comma or set closing brace.");
      }
    }

    // Ожидается закрывающая фигурная скобка множества.
    expectSymbol(query, position, '}', "Expected set closing brace.");

    output << "}";
    outputs_[currentSet] = output.str();
    currentSet++;

    skipSpaces(query, position);

    if (currentSet < setsCount_) {
      // Ожидается запятая между множествами.
      expectSymbol(query, position, ',', "Expected comma between sets.");
    }
  }

  // Ожидается закрывающая фигурная скобка внешнего множества.
  expectSymbol(query, position, '}', "Expected outer closing brace.");
  skipSpaces(query, position);

  if (position != static_cast<int>(query.length())) {
    // Неожиданные символы после запроса.
    throw std::runtime_error("Unexpected symbols after query.");
  }
}
