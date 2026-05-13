#include <iostream>
#include <stdexcept>

#include "1.rpn.hpp"

// ============================================================================
// Выполнение арифметической операции
// ============================================================================

int performOperation(int left, int right, char operation) {
  switch (operation) {
    case '+':
      return left + right;

    case '-':
      return left - right;

    case '*':
      return left * right;

    case '/':
      if (right == 0) {
        throw std::runtime_error("Division by zero.");
      }

      return left / right;

    default:
      throw std::runtime_error("Unknown operator.");
  }
}