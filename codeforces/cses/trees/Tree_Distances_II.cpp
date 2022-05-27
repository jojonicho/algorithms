#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define pb push_back

const int N = 2e5 + 5;

vi G[N];

int sz[N];  // subtree size
ll dp[N];

int dfs(int u, int p = -1) {
  sz[u] = 1;
  for (auto v : G[u]) {
    if (v == p) continue;
    sz[u] += dfs(v, u);
    dp[u] += dp[v] + sz[v];
  }
  return sz[u];
}

int n;
void dfs2(int u, int p = -1) {
  for (auto v : G[u]) {
    if (v == p) continue;
    dp[v] = dp[v] + dp[u] - (dp[v] + sz[v]) + n - sz[v];
    dfs2(v, u);
  }
}

int main() {
  cin >> n;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs(0);
  dfs2(0);
  for (int i = 0; i < n; i++) cout << dp[i] << " ";
}