#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

const int N = 1e5 + 5;

vi G[N];
int indeg[N];

int n, m;
int a, b;

int main() {
  cin >> n >> m;

  while(m--) {
    cin >> a >> b, a--, b--;
    G[a].pb(b);
    indeg[b]++;
  }

  queue<int> q;
  for(int i=0; i<n; i++) {
    if(indeg[i] == 0) q.push(i);
  }

  vi ans;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    ans.pb(u);
    for(auto v: G[u]) {
      if(--indeg[v] == 0) q.push(v);
    }
  }

  if((int)ans.size() != n) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for(auto x: ans) cout << x + 1 << " ";
}

