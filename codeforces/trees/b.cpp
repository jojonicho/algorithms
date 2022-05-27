#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];

double dfs(int u, int p = -1) {
  int nChildren = 0;
  double ans = 0;
  for (auto v : G[u]) {
    if (v == p) continue;
    ans += dfs(v, u);
    nChildren++;
  }
  if (nChildren == 0) return 0;
  //   return (nChildren + ans) / nChildren;
  return 1 + ans / nChildren;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  cout << setprecision(12) << dfs(0);
}