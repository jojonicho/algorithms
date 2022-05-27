#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 1e5 + 5, M = 1e5 + 5; // nStrings, len(string)
const ll INF = 1e14 + 5;

ll dp[N][2]; // index, reversed
ll C[N];
string S[N], T[N];

int n;

int main() {
  cin >> n;
  for(int i=1; i<=n; i++) cin >> C[i];

  for(int i=1; i<=n; i++) {
    cin >> S[i];
    T[i] = S[i];
    reverse(all(T[i]));

    dp[i][0] = dp[i][1] = INF;
  }

  S[0] = T[0] = "";
  dp[0][0] = dp[0][1] = 0;
  for(int i=1; i<=n; i++) {
    if(S[i] >= S[i-1]) dp[i][0] = dp[i-1][0];
    if(S[i] >= T[i-1]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
    if(T[i] >= S[i-1]) dp[i][1] = dp[i-1][0] + C[i];
    if(T[i] >= T[i-1]) dp[i][1] = min(dp[i][1], dp[i-1][1] + C[i]);
  }

  ll ans = min(dp[n][0], dp[n][1]);

  if(ans >= INF) ans = -1;
  cout << ans;
}
