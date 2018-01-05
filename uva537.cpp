/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/

#include <string>
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;

float ReadValue(string statement, int pos, char unit) {
  int field_end = statement.find(unit, pos);
  float scalar = 1.0f;
  char last_digit_or_scalar = statement[field_end-1];
  if (last_digit_or_scalar >= '0' and last_digit_or_scalar <= '9') {
  } else {
    field_end--;
    if (last_digit_or_scalar == 'm') {
      scalar *= 0.001f;
    } else if (last_digit_or_scalar == 'M') {
      scalar *= 1000000.0f;
    } else if (last_digit_or_scalar == 'k') {
      scalar *= 1000.0f;
    }
  }
  string str_value = statement.substr(pos+2, field_end-pos-2);
  return scalar * std::stof(str_value);
}

int main() {
  int n;
  cin >> n;
  cin.get();
  for (int idx = 1; idx <= n; idx++) {
    string statement;
    getline(cin, statement);
    std::cout << "Problem #" << idx << std::endl;
    float i, u, p;
    int current_pos = statement.find("I=");
    int volt_pos = statement.find("U=");
    int power_pos = statement.find("P=");
    bool has_current = (current_pos != string::npos);
    bool has_volt = (volt_pos != string::npos);
    bool has_power = (power_pos != string::npos);
    if (has_current) {
      i = ReadValue(statement, current_pos, 'A');
    }
    if (has_volt) {
      u = ReadValue(statement, volt_pos, 'V');
    }
    if (has_power) {
      p = ReadValue(statement, power_pos, 'W');
    }
    
    float ans = 0.0f;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    if (!has_current) {
      ans = p / u;
      std::cout << "I="<< ans <<'A'<< std::endl;
    }
    if (!has_volt) {
      ans = p/i;
      std::cout << "U=" << ans <<'V' << std::endl;
    }
    if (!has_power) {
      ans = i *u;
      std::cout << "P=" << ans <<'W' << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
