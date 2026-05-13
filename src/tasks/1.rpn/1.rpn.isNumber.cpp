#include "1.rpn.hpp"

bool isNumber(const std::string& token) {
  try {
    std::stod(token);
    return true;
  } catch (...) {
    return false;
  }
}