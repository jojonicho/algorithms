#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int X = 511; // 2^9 = 512, max(A) = 500, max XOR

int A[N];
int dp[N][X + 5]; // smallest last element to form xor value of x
int n;
int main() {
  cin >> n;

  for(int i=1; i<=n; i++) cin >> A[i];
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=X; j++) {
      dp[i][j] = X;
    }
  }

  dp[0][0] = 0;
  for(int i=1; i<=n; i++) {
    int x = A[i];
    for(int j=0; j<=X; j++) {
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
      if(dp[i-1][j] < x) {
        int nxt = j^x;
        dp[i][nxt] = min(dp[i][nxt], x);
      }
    }
  }
  
  vector<int> ans;
  for(int i=0; i<=X; i++) if(dp[n][i] != X) ans.push_back(i);
  cout << (int)ans.size() << '\n';
  for(auto x: ans) cout << x << " ";
}
