#include <bits/stdc++.h>

using namespace std;

int x;
string s;

int main() {
  getline(cin, s);
  stringstream stream(s);
  vector<int> a;
  while (stream >> x) {
    a.push_back(x);
  }

  getline(cin, s);
  stringstream streams(s);
  vector<int> b;
  while (streams >> x) {
    b.push_back(x);
  }

  int n = a.size();

  int vijay = 0;
  int adhi = 0;
  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      total++;
      if (a[i] < b[j]) {
        // cout << a[i] << " vs " << b[j] << " menang vijay" << endl;
        vijay++;
      } else if (a[i] > b[j]) {
        // cout << a[i] << " vs " << b[j] << " menang adhi" << endl;
        adhi++;
      }
    }
  }
  if (vijay == adhi) {
    cout << "Imbang" << endl;
    return 0;
  }
  if (vijay > adhi) {
    int gc = gcd(vijay, total);
    cout << "Vijay menang dengan peluang " << (vijay / gc) << "/"
         << (total / gc) << endl;
    return 0;
  }

  int gc = gcd(adhi, total);
  cout << "Adhi menang dengan peluang " << (adhi / gc) << "/" << (total / gc)
       << endl;
  return 0;
}