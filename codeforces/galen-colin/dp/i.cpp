#include <bits/stdc++.h>
using namespace std;
#define en '\n';

const int N = 505;
int A[N][N], dp[N];

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  auto rowAns = [&](int i) {
    int ans = 0, cur = 0;
    for (int j = 0; j < m; j++) {
      if (A[i][j])
        cur++;
      else
        cur = 0;
      ans = max(ans, cur);
    }
    return ans;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> A[i][j];
    dp[i] = rowAns(i);
  }

  while (q--) {
    int r, c;
    cin >> r >> c, r--, c--;
    A[r][c] = !A[r][c];
    int ans = dp[r] = rowAns(r);

    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans << en;
  }
}