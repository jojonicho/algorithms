#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef long long ll;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

vi G[N];

int C[N];

ll dp[N][4];

int n, k;

int u, v;

int c;

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

void dfs(int u, int p=-1) {
  if(C[u]) { // only 1 way to color this
    for(auto c: {1, 2, 3}) {
      dp[u][c] = c == C[u];
    }
  } else {
    dp[u][1] = 1;
    dp[u][2] = 1;
    dp[u][3] = 1;
  }

  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    dp[u][1] = mul(dp[u][1], add(dp[v][2], dp[v][3]));
    dp[u][2] = mul(dp[u][2], add(dp[v][1], dp[v][3]));
    dp[u][3] = mul(dp[u][3], add(dp[v][1], dp[v][2]));
  }
}

int main() {
  freopen("barnpainting.in", "r", stdin);
  freopen("barnpainting.out", "w", stdout);
  cin >> n >> k;
  for(int i=0; i<n-1; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  while(k--) {
    cin >> u >> c, u--;
    C[u] = c;
  }
  dfs(0);

  cout << add(add(dp[0][1], dp[0][2]), dp[0][3]);
}
