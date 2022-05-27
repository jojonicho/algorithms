#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int dp[N][3][2]; // idx, (not reversed, reversing, reversed)
int A[N];

int n;
string s;

int main() {
  cin >> n >> s;
  for(int i=1; i<=n; i++) A[i] = s[i-1] - '0';

  for(int i=1; i<=n; i++) {
    int x = A[i], y = !x;
    dp[i][0][x] = dp[i-1][0][y] + 1;
    dp[i][0][y] = dp[i-1][0][y];

    dp[i][1][y] = max(dp[i-1][0][x], dp[i-1][1][x]) + 1;
    dp[i][1][x] = max(dp[i-1][0][x], dp[i-1][1][x]);

    dp[i][2][x] = max(dp[i-1][1][y], dp[i-1][2][y]) + 1;
    dp[i][2][y] = max(dp[i-1][1][y], dp[i-1][2][y]);
  }

  cout << max(dp[n][2][0], dp[n][2][1]);
}
