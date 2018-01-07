/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

inline int CountDigits(int x) {
  int ret = 0;
  while (x) {
    ret++;
    x /= 10;
  }
  return ret;
}

int Generate(int x) {
  int ret = x;
  while(x) {
    ret += (x%10);
    x/=10;
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bool found = false;
    int num_digits = CountDigits(x);
    int start = x - (num_digits * 9);
    if (start < (x/2)) 
      start = x/2;
    for (int k = x - (num_digits * 9); k < x && !found; k++) {
      if (Generate(k) == x) {
        cout << k << endl;
        found = true;
      }
    }
    if (!found) {
      cout << 0 << endl;
    }
  }
  return 0;
}
