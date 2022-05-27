#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef long long ll;

const int N = 1e5+5;

int C[N]; // also used for vis
vi same[N], diff[N];

int n, m;
int u, v;

bool dfs(int u, int p=-1, int c=0) {
  if(C[u] != -1) {
    return C[u] == c;
  }
  C[u] = c;
  bool ok = 1;

  for(auto v: same[u]) {
    if(v == p) continue;
    ok &= dfs(v, u, c);
  }

  for(auto v: diff[u]) {
    if(v == p) continue;
    ok &= dfs(v, u, c^1);
  }

  return ok;
}

int main() {
  memset(C, -1, sizeof(C));
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);

  cin >> n >> m;

  while(m--) {
    char t; cin >> t;
    cin >> u >> v, u--, v--;
    if(t == 'S') {
      same[u].pb(v);
      same[v].pb(u);
    } else {
      diff[u].pb(v);
      diff[v].pb(u);
    }
  }

  int nComponents = 0;
  bool ok = 1;
  for(int i=0; ok && i<n; i++) {
    if(C[i] != -1) continue;
    ok &= dfs(i);
    nComponents++;
  }

  if(!ok) {
    cout << 0;
    return 0;
  }

  cout << 1;
  for(int i=0; i<nComponents; i++) {
    cout << 0;
  }
}
