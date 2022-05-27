#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 5, K = 2e3 + 5;
const ll INF = 1e18 + 10;
int A[N], B[K];
ll dp[K][N];

int n, k, p;

int main() {
  cin >> n >> k >> p;

  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= k; i++) cin >> B[i];

  sort(A + 1, A + n + 1);
  sort(B + 1, B + k + 1);

  for (int i = 0; i <= k; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = INF;

  dp[0][0] = 0;
  // 01 knapsack, n in inner loop cause ans is dp[n]
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      // take or no take
      ll u = A[j], v = B[i];
      ll take = max(dp[i - 1][j - 1], abs(u - v) + abs(v - p));
      ll notake = dp[i - 1][j];
      dp[i][j] = min(take, notake);
    }
  }
  cout << dp[k][n];
}