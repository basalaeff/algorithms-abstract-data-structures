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

int evaluatePostfix(const std::string& expression) {
  Stack stack;

  // Добавляю поддержку чисел.
  // Исправляю посимвольную обработку на обработку токенов
  // Добавить многозначные и отрицательные
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {
    // Если это число (включая многозначные и отрицательные)
    if (std::isdigit(token[0]) ||
        (token.size() > 1 && token[0] == '-' && std::isdigit(token[1]))) {
      stack.push(token);
    }

    // Если оператор
    else if (token.size() == 1 && isOperator(token[0])) {
      int right = std::stoi(stack.top());
      stack.pop();

      int left = std::stoi(stack.top());
      stack.pop();

      int result = performOperation(left, right, token[0]);

      stack.push(std::to_string(result));
    }
  }

  return std::stoi(stack.top());
}