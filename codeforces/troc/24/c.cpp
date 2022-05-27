#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

int main() {
  int n, k;
  cin >> n >> k;

  ll ans = 1e18 + 10;

  string s;
  cin >> s;

  int A[n];

  auto getAns = [&]() {
    ll BIT[2] = {};

    ll inv = 0;
    for (int i = 0; i < n; i++) {
      int x = A[i];
      inv += i - BIT[x] - (x ? BIT[0] : 0);
      BIT[x] += 1;
    }
    return inv;
  };

  for (int l = 0; l <= k; l++) {
    int r = k - l;
    for (int i = 0; i < n; i++) {
      A[i] = s[i] - '0';
    }
    // from left
    int lc = l;
    for (int i = 0; lc && i < n; i++) {
      if (A[i]) A[i] = 0, lc--;
    }

    int rc = r;
    // from right
    for (int i = n - 1; rc && i >= 0; i--) {
      if (!A[i]) A[i] = 1, rc--;
    }
    ans = min(ans, getAns());
  }

  cout << ans;
}