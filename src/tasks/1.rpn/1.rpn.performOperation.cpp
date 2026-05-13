#include <stdexcept>
#include <iostream>

#include "1.rpn.hpp"

// ============================================================================
// Выполнение арифметической операции
// ============================================================================

int performOperation(int left, int right, char operation) {
  try {
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
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}