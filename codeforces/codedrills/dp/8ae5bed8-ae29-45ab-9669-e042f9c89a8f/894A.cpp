#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int pref[N], suff[N];

string s;
int n;

int main() {
  cin >> s;
  n = s.size();

  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i - 1] == 'Q');
  for (int i = n; i >= 1; i--) suff[i] = suff[i + 1] + (s[i - 1] == 'Q');

  int ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    if (s[i - 1] == 'A') ans += pref[i - 1] * suff[i + 1];
  }
  cout << ans;
}
