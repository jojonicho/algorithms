#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'
typedef vector<int> vi;

const int N = 2e5+5;
const int LOG = 18;

vi G[N];
int up[N][LOG];
int depth[N];

int n, q;

void dfs(int u, int p=-1) {
  for(auto v: G[u]) {
    if(v == p) continue;
    up[v][0] = u; // 2^0 = 1
    depth[v] = depth[u] + 1;

    for(int i=1; i<LOG; i++) {
      up[v][i] = up[up[v][i-1]][i-1]; // 8 = 4 + 4
    }
    dfs(v, u);
  }
}

int lca(int u, int v) {
  if(depth[u] < depth[v]) swap(u, v);
  int dist = depth[u] - depth[v];
  // every number can be represented with powers of two
  for(int i=LOG-1; i>=0; i--) {
    if((dist >> i) & 1) u = up[u][i];
  }

  if(u == v) return u;
  for(int i=LOG-1; i>=0; i--) {
    if(up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int main() {
  cin >> n >> q;
  for(int i=1; i<n; i++) {
    int u = i;
    int v; cin >> v, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(0);

  while(q--) {
    int u, v; cin >> u >> v, u--, v--;
    cout << lca(u, v) + 1 << en;
  }

}
