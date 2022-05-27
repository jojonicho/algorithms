#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef long long ll;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

vi G[N];
ll dp[N][2];

int n, u, v;

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

void dfs(int u, int p=-1) {
  dp[u][0] = 1;
  dp[u][1] = 1;
  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    dp[u][0] = mul(dp[u][0], dp[v][0] + dp[v][1]);
  }
  // if black, all children must be white
  for(auto v: G[u]) {
    if(v == p) continue;
    dp[u][1] = mul(dp[u][1], dp[v][0]);
  }
}

int main() {
  cin >> n;

  for(int i=0; i<n-1; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(0);

  cout << add(dp[0][0], dp[0][1]);
}
