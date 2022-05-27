#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

const string IMPOSSIBLE = "IMPOSSIBLE";
const int N = 1e5 + 5;

vi G[N];

int n, m;
int u, v;

int C[N];

bool dfs(int u, int p=-1, int c=0) {
  if(C[u] == -1) C[u] = c;
  else return C[u] == c;
  bool ok = 1;
  for(auto v: G[u]) {
    if(v == p) continue;
    ok &= dfs(v, u, c^1);
  }
  return ok;
}

int main() {
  memset(C, -1, sizeof(C));
  cin >> n >> m;
  while(m--) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  bool ok = 1;
  for(int i=0; i<n; i++) {
    if(C[i] == -1) ok &= dfs(i);
  }

  if(!ok) {
    cout << IMPOSSIBLE;
    return 0;
  }
  for(int i=0; i<n; i++) cout << C[i]+1 << " ";
}
