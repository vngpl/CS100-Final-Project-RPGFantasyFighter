#include <iostream>

#include "Display.hpp"

constexpr size_t N_ENEMY = 3;

bool convert_check(char& c, char cap) {
  if (c - 'a' == cap - 'A' || c == cap) {
    c = cap;
    return true;
  }
  return false;
}

const char getInput123() {
  char option;
  do {
    std::cin >> option;
    if (option != '1' && option != '2' && option != '3') {
      Display::printInvalidInput();
    }
  } while (option != '1' && option != '2' && option != '3');
  return option;
}

const char getInputYN() {
  char option;
  do {
    std::cin >> option;
    if (!convert_check(option, 'Y') && !convert_check(option, 'N')) {
      Display::printInvalidInput();
    }
  } while (!convert_check(option, 'Y') && !convert_check(option, 'N'));
  return option;
}

const char getInputNWP() {
  char option;
  do {
    std::cin >> option;
    if (!convert_check(option, 'N') && !convert_check(option, 'W') &&
        !convert_check(option, 'P')) {
      Display::printInvalidInput();
    }
  } while (!convert_check(option, 'N') && !convert_check(option, 'W') &&
           !convert_check(option, 'P'));
  return option;
}