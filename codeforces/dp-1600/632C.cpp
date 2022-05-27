#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) cin >> S[i];

  auto cmp = [&](string &a, string &b) { return a + b < b + a; };
  sort(all(S), cmp);
}
