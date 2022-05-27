#include <bits/stdc++.h>
using namespace std;

#define en '\n'

const int N = 1e5 + 5, M = 9; //500 < 2^9
const int MX = 511;
const int INF = MX + 1;

int A[N];
int dp[N][MX + 1];

int n;

int main() {
  cin >> n;
  for(int i=1; i<=n; i++) cin >> A[i];

  for(int i=0; i<=n; i++) {
    for(int j=0; j<=MX; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;

  for(int i=1; i<=n; i++) {
    int x = A[i];
    for(int j=0; j<=MX; j++) {
      // we can extend dp if last number to form j < x
      if(dp[i-1][j] >= x) continue;
      int y = j ^ x;
      dp[i][y] = min(dp[i][y], x);
    }
    for(int j=0; j<=MX; j++) dp[i][j] = min(dp[i][j], dp[i-1][j]);
    //for(int j=0; j<x; j++) {
      ////if(!dp[i-1][j]) continue;
      ////int y = x ^ j; 
      ////dp[i][y] |= dp[i-1][j];
      ////dp[i]
      //// take or no take
      //dp[i][x] = dp[i-1][j] ^ x;
      //st.insert(dp[i][x]);
    //}
  }
  int ans = 0;
  for(int i=0; i<=MX; i++) if(dp[n][i] != INF) ans++;
  cout << ans << en;
  for(int i=0; i<=MX; i++) if(dp[n][i] != INF) cout << i << " ";
}
