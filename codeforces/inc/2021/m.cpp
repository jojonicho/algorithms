#include <bits/stdc++.h>

using namespace std;

long long int k, n, s;

int main() {
  cin >> k >> s >> n;
  n = n - k * s;
  long long int nawal = n;
  if (n < 0) {
    cout << "NO" << endl;
    return 0;
  }

  if (n <= s * (k - 2) && n >= 0) {
    cout << "YES" << endl;
    return 0;
  }
  n = n - s * (k - 2);
  if (n % 2 == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (n % 2 == 1) {
    if (s == 1) {
      cout << "NO" << endl;
      return 0;
    }
    if (k == 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}