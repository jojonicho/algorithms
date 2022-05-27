#include <bits/stdc++.h>
using namespace std;
#define en '\n'

void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c, r--, c--;
  int G[n][m];

  bool exists = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char d;
      cin >> d;
      G[i][j] = d == 'B';
      exists |= G[i][j];
    }
  }
  if (!exists) {
    cout << -1 << en;
    return;
  }
  if (G[r][c]) {
    cout << 0 << en;
    return;
  }

  bool ok = 0;
  for (int i = 0; i < n; i++)
    if (G[i][c]) ok = 1;

  for (int j = 0; j < m; j++)
    if (G[r][j]) ok = 1;

  cout << (ok ? 1 : 2) << en;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
