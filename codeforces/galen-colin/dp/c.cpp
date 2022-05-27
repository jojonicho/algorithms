#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5, MASK = 1 << 3, INF = 1e9 + 5;
int V[N], MSK[N];
int dp[N][MASK];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < MASK; j++) dp[i][j] = INF;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> V[i] >> s;
    for (char c : s) MSK[i] |= 1 << (c - 'A');
  }

  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int mask2 = MSK[i];
    for (int mask = 0; mask < MASK; mask++) {
      dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);  // no take V[i+1];
      dp[i + 1][mask | mask2] =
          min(dp[i + 1][mask | mask2], dp[i][mask] + V[i]);
    }
  }

  int &ans = dp[n][MASK - 1];
  if (ans == INF) ans = -1;
  cout << ans;
}