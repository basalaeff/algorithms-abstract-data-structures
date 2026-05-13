#include <cctype>
#include <sstream>

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

double evaluatePostfix(const std::string& expression) {
  Stack stack;

  // Добавляю поддержку чисел.
  // Исправляю посимвольную обработку на обработку токенов
  // Добавить многозначные и отрицательные
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {
    // Если это число (включая многозначные, дробные и отрицательные)
    if (isNumber(token)) {
      stack.push(token);
    }

    // Если оператор
    else if (token.size() == 1 && isOperator(token[0])) {
      double right = std::stod(stack.top());
      stack.pop();

      double left = std::stod(stack.top());
      stack.pop();

      double result = performOperation(left, right, token[0]);

      stack.push(std::to_string(result));
    }
  }

  return std::stod(stack.top());
}