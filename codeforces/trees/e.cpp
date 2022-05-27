#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define en '\n';

const int N = 2e5 + 5;
vector<int> G[N];
int A[N];
ll cur, SUM;  // sum over all A_i
ll sum[N];
ll dp[N];

int n;

ll dfs(int u, int p = -1, ll dep = 1) {
  sum[u] = A[u];
  for (auto v : G[u]) {
    if (v == p) continue;
    sum[u] += dfs(v, u, dep + 1);
    cur += dep * A[v];
  }
  return sum[u];
}

void dfs2(int u, int p = -1) {
  for (auto v : G[u]) {
    if (v == p) continue;
    ll up = sum[v];
    ll down = SUM - sum[v];

    sum[u] -= sum[v];
    sum[v] = SUM;  // new root has sum of all A_i

    dp[v] = dp[u] - up + down;
    dfs2(v, u);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  SUM = dfs(0);
  dp[0] = cur;
  dfs2(0);
  cout << *max_element(dp, dp + n);
}