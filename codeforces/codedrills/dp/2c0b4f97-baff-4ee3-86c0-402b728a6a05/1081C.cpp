#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 2e3 + 5, M = 2e3 + 5, K = 2e3+5;

int dp[N][K];

int n, m, k;

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

int main() {
  cin >> n >> m >> k;

  for(int i=1; i<=n; i++) {
    dp[i][0] = m;
    for(int j=1; j<=k; j++) {
      dp[i][j] = add(dp[i-1][j], mul(dp[i-1][j-1], m - 1));
    }
  }
  cout << dp[n][k];
}
