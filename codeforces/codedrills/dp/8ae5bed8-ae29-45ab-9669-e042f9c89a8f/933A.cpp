#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int dp[N][5];
int A[N];

int n;

int main() {
  cin >> n;
  for(int i=1; i<=n; i++) cin >> A[i];

  for(int i=1; i<=n; i++) {
    int x = A[i];
    dp[i][1] = dp[i-1][1];
    dp[i][2] = dp[i-1][2];
    dp[i][3] = dp[i-1][3];
    dp[i][4] = dp[i-1][4];
    if(x == 1) {
      dp[i][1] = dp[i-1][1] + 1;
      dp[i][3] = max(dp[i-1][2], dp[i-1][3]) + 1;
    } else {
      dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + 1;
      dp[i][4] = max(dp[i-1][3], dp[i-1][4]) + 1;
    }
  }

  cout << max({dp[n][1], dp[n][2], dp[n][3], dp[n][4]});
}
