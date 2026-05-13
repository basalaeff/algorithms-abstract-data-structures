#include <cctype>

#include "../../ads/d.Stack/d.Stack.hpp"
#include "1.rpn.hpp"

// ============================================================================
// Вычисление выражения в обратной польской записи
// ============================================================================
// Алгоритм:
// 1) Читаем символ.
// 2) Если число:
//      -> помещаем в стек.
// 3) Если оператор:
//      -> достаём 2 числа;
//      -> выполняем операцию;
//      -> результат кладём обратно.
// 4) В конце в стеке остаётся ответ.
//
// Пример:
// 314*+
// 1 * 4 = 4
// 3 + 4 = 7
// Ответ: 7
// ============================================================================

int evaluatePostfix(const std::string& expression) {
  Stack stack;

  for (char symbol : expression) {
    // Пропускаем пробелы
    if (symbol == ' ') {
      continue;
    }

    // Если символ — число
    if (std::isdigit(symbol)) {
      std::string value(1, symbol);

      stack.push(value);
    }

    // Если символ — оператор
    else if (isOperator(symbol)) {
      int right = std::stoi(stack.top());
      stack.pop();

      int left = std::stoi(stack.top());
      stack.pop();

      int result = performOperation(left, right, symbol);

      stack.push(std::to_string(result));
    }
  }

  return std::stoi(stack.top());
}