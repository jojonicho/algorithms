#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

const int N = 2e5 + 5;

vi G[N];
int dp[N][2]; // take or no take

int n;

void dfs(int u, int p=-1) {
  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    dp[u][0] += max(dp[v][0], dp[v][1]); // sum of dp from all children
  }
  for(auto v: G[u]) {
    if(v == p) continue;
    dp[u][1] = max(dp[u][1], dp[v][0] + 1 + dp[u][0] - max(dp[v][0], dp[v][1])); // exclude taken edge (u,v)
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n-1; i++) {
    int u, v; cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(0);

  cout << max(dp[0][0], dp[0][1]);
}
