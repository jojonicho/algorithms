#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N = 1e5 + 5;
int P[N];
bool C[N];
vi ans, G[N];

bool dfs(int u) {
  bool ok1 = C[u];
  bool ok2 = 1;

  for (auto v : G[u]) {
    if (!dfs(v)) ok2 = 0;
  }
  if (ok1 && ok2) ans.push_back(u);
  return ok1;
}

int main() {
  int n;
  cin >> n;
  int root = -1;

  for (int i = 1; i <= n; i++) {
    cin >> P[i] >> C[i];
    if (P[i] == -1)
      root = i;
    else
      G[P[i]].push_back(i);
  }
  dfs(root);

  if (ans.empty()) {
    cout << -1;
    return 0;
  }

  sort(ans.begin(), ans.end());
  for (auto x : ans) cout << x << " ";
}