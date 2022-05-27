#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define en '\n';

const ll INF = 1e18 + 10;
const int N = 3005, K = 4;
ll dp[N][K];
int A[N], C[N];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> C[i];

  for (int i = 0; i <= n; i++)
    for (int j = 0; j < K; j++) dp[i][j] = INF;

  ll ans = INF;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
    dp[i][1] = C[i];
    for (int j = 1; j < i; j++) {
      if (A[i] <= A[j]) continue;
      for (int k = 1; k <= 3; k++) {
        // take or no take
        dp[i][k] = min({dp[i][k], dp[j][k - 1] + C[i], dp[j][k]});
      }
      ans = min(ans, dp[i][3]);
    }
  }

  if (ans >= INF) ans = -1;
  cout << ans;
}