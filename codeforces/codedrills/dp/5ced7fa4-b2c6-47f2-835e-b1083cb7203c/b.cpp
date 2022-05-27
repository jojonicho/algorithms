#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en '\n';

ll n, m, k;

void solve() {
  cin >> n >> m >> k, k -= 2;     // max diameter is k-2
  ll complete = n * (n - 1) / 2;  // n choose 2

  bool ok = 1;

  // multigraph or disconnected or negative diameter
  if (m > complete || m < n - 1 || k < 0)
    ok = 0;
  else if (k == 0)
    ok = n == 1;
  else if (k == 1)
    ok = m == complete;

  cout << (ok ? "YES" : "NO") << en;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
