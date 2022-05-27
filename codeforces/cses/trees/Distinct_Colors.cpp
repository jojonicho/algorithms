#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

const int N = 2e5 + 5;
int C[N], ans[N];
vi G[N];
set<int> st[N];

void dfs(int u, int p = -1) {
  st[u].insert(C[u]);
  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    // stu is the one we want to merge to, the bigger size must be stU
    set<int> &stU = st[u], &stV = st[v];
    if(stV.size() > stU.size()) swap(stV, stU);
    for(auto x: stV) stU.insert(x);
  }
  ans[u] = st[u].size();
}

int main() {
  int n; cin >> n;
  for(int i=0; i<n; i++) {
    cin >> C[i];
  }

  for(int i=0; i<n-1; i++) {
    int u, v; cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  // small to large merging
  dfs(0);

  for(int i=0; i<n; i++) cout << ans[i] << " ";
}
