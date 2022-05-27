#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 1e9 + 5;
int P[N], S[N], A[N];
vector<int> G[N];

int n;
long long ans;
bool ok = 1;

void dfs(int u) {
  int parentS = u ? S[P[u]] : 0;

  if (S[u] == -1) {  // means S[v] != -1
    int mn = G[u].empty() ? parentS : INF;
    for (auto v : G[u]) {
      mn = min(mn, S[v]);
    }
    S[u] = mn;
  }

  if (S[u] < parentS) ok = 0;
  ans += S[u] - parentS;

  for (auto v : G[u]) {
    dfs(v);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> P[i], P[i]--;
    G[P[i]].push_back(i);
  }

  P[0] = -1;
  for (int i = 0; i < n; i++) cin >> S[i];

  dfs(0);

  if (!ok)
    cout << -1;
  else
    cout << ans;
}