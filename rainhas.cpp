#include <string>
#include <vector>
#include "./romanos.hpp"

std::string decimal_p_romano(int decimal) {
  std::string romano = "";
  std::vector<std::pair<int, std::string>> algarismos = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
  };

  for (auto& par : algarismos) {
    while (decimal >= par.first) {
      romano += par.second;
      decimal -= par.first;
    }
  }

  return romano;
}

int romanos_para_decimal(const char* num_romano) {
  for (int i = 0; i < 3000; i++) {
    if (std::string(num_romano) == decimal_p_romano(i + 1)) {
      return i + 1;
    }
  }
  return -1;
}
