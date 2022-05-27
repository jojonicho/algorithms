#include <bits/stdc++.h>
using namespace std;

bool ok[26];

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  for (int i = 0; i < k; i++) {
    char c;
    cin >> c;
    ok[c - 'a'] = 1;
  }

  long long ans = 0;
  int len = 0;
  for (int i = 0; i < n; i++) {
    if (ok[s[i] - 'a']) {
      ans += len + 1;
      len++;
    } else
      len = 0;
  }
  cout << ans;
}