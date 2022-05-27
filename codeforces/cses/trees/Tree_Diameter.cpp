#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back

const int N = 2e5 + 5;

vi G[N];
int ans;

int dfs(int u, int p = -1) {
  int mx = 0;
  for (auto v : G[u]) {
    if (v == p) continue;
    int cur = dfs(v, u);
    ans = max(ans, mx + cur);
    mx = max(mx, cur);
  }
  return 1 + mx;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs(0);
  cout << ans;
}