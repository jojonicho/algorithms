#include <iostream>

using namespace std;

int n;

int get(int n) {
  for (int i = -50; i <= 50; i++) {
    for (int j = -50; j <= 50; j++) {
      for (int k = -50; k <= 50; k++) {
        if ((i * i * i + j * j * j + k * k * k) == n) {
          cout << i << " " << j << " " << k << endl;
          return 0;
        }
      }
    }
  }
  if (n == 4 || n == 5 || n == 13 || n == 14 || n == 31 || n == 32 || n == 40 ||
      n == 41 || n == 49) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 16) {
    cout << "-511 -1609 1626\n";
  }
  if (n == 24) {
    cout << "-2901096694 -15550555555 15584139827\n";
  }
  if (n == 30) {
    cout << "-283059965 -2218888517 2220422932\n";
  }
  if (n == 33) {
    cout << "8866128975287528 -8778405442862239 -2736111468807040\n";
  }
  if (n == 39) {
    cout << "117367 134476 -159380\n";
  }
  if (n == 42) {
    cout << "-80538738812075974 80435758145817515 12602123297335631\n";
  }
  return 0;
}

int main() {
  cin >> n;
  get(n);
}