#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef long long ll;

const int N = 5e4 + 5, K = 505;

vi G[N];
ll dp[N][K];
int par[N];

int n, k;
int u, v;
int ans; 

void dfs(int u, int p=-1) {
  par[u] = p;
  dp[u][0] = 1;

  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    for(int i=1; i<=k; i++) {
      dp[u][i] += dp[v][i-1];
    }
  }

  int curU = u, curK = k;
  while(curK && curU != -1) {
    ans += dp[curU][curK];
    curU = par[curU];
    curK--;
  }
}

int main() {
  cin >> n >> k;
  for(int i=0; i<n-1; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(0);
  cout << ans;
}
