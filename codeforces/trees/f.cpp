#include <bits/stdc++.h>
using namespace std;

#define en '\n';
typedef vector<int> vi;

const int N = 2e5 + 5;
int tin[N], tout[N], dep[N], P[N];
vi G[N];

int n, m;

int t = 0;

void dfs(int u, int p = -1, int depth = 0) {
  tin[u] = t;
  t++;

  dep[u] = depth;
  P[u] = p;
  for (auto v : G[u]) {
    if (v == p) continue;
    dfs(v, u, depth + 1);
  }

  tout[u] = t;
  t++;
}

bool isAncestor(int u, int v) { return tin[u] > tin[v] && tout[u] < tout[v]; }

int main() {
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(0);

  while (m--) {
    int k;
    cin >> k;

    int A[k];
    for (int i = 0; i < k; i++) cin >> A[i], A[i]--;

    int u = 0;
    for (int i = 0; i < k; i++) {
      if (dep[A[i]] > dep[A[u]]) u = i;
    }
    u = A[u];

    bool ok = 1;
    for (auto v : A) {
      if (v == 0 || u == v) continue;
      if (!isAncestor(u, v) && !isAncestor(u, P[v])) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << en;
  }
}