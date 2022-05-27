#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef long long ll;

const int N = 1e5 + 5;

vi G[N];
int C[N];
int dp[2];

int n;
int u, v;
ll ans;

void dfs(int u, int p=-1, int c=0) {
  if(C[u] != -1) return;
  C[u] = c;
  int sz = 0;
  for(auto v: G[u]) {
    if(v == p) continue;
    sz++;
    dfs(v, u, c^1);
  }
  dp[c]++;
  //debug() << im(u) im(sz) im(c) im(dp[c^1]);
  ans += dp[c^1] - sz;
}

int main() {
  memset(C, -1, sizeof(C));
  cin >> n;
  for(int i=0; i<n-1; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(0);
  cout << ans;
}
