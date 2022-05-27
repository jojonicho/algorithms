#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'

typedef vector<int> vi;
typedef long long ll;

const int N = 2e5 + 5;
const int LOG = 18;

int A[N];
vi G[N];

int n, q;

int up[N][LOG], depth[N];
void binary_lift(int u, int p=0) {
  for(auto v: G[u]) {
    if(v == p) continue;
    depth[v] = depth[u] + 1;
    up[v][0] = u;
    for(int i=1; i<LOG; i++) {
      up[v][i] = up[up[v][i-1]][i-1];
    }
    binary_lift(v, u);
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
// binary_lift(0);
ll pref[N];

void dfs(int u, int p=0) {
  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    pref[u] += pref[v];
  }
}

int main() {
  cin >> n >> q;
  for(int i=0; i<n-1; i++) {
    int u, v; cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  
  binary_lift(1);

  while(q--) {
    int u, v; cin >> u >> v;
    pref[u]++;
    int _lca = lca(u,v);
    pref[_lca]--;
    pref[v]++;
    pref[up[_lca][0]]--;
  }

  dfs(1);
  for(int i=1; i<=n; i++) cout << pref[i] << " ";
}
