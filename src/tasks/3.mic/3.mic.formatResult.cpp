#include <sstream>
#include <stdexcept>

#include "3.mic.hpp"

// ============================================================================
// ФОРМАТИРОВАНИЕ РЕЗУЛЬТАТА
// ============================================================================
// Формирует строку результата для вывода в консоль.
//
// Алгоритм:
// 1) Проверяем, что результат поиска существует.
// 2) Добавляем в строку первое найденное множество.
// 3) Добавляем в строку второе найденное множество.
// 4) Добавляем количество общих элементов.
// 5) Возвращаем готовую строку результата.
// ============================================================================

std::string Mic::formatResult() const {
  if (firstIndex_ < 0 || secondIndex_ < 0 || outputs_ == nullptr) {
    // Результат не найден.
    throw std::runtime_error("Result not found.");
  }

  std::ostringstream output;

  output << "Result: {";
  output << outputs_[firstIndex_];
  output << ", ";
  output << outputs_[secondIndex_];
  output << "}, common elements count: ";
  output << maxCommonCount_;

  return output.str();
}
