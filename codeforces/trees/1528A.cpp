#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL);

typedef vector<int> vi;
typedef long long ll;

const int N = 1e5 + 5; 

vi G[N];
int L[N], R[N];
ll dp[N][2]; // left, right

int n;
int u, v;

void dfs(int u, int p=-1) {
  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    dp[u][0] += max(dp[v][0] + abs(L[u] - L[v]), dp[v][1] + abs(L[u] - R[v]));
    dp[u][1] += max(dp[v][0] + abs(R[u] - L[v]), dp[v][1] + abs(R[u] - R[v]));
  }
}

void solve() {
  cin >> n;
  for(int i=0; i<n; i++) {
    G[i].clear();
    dp[i][0] = dp[i][1] = 0;
  }

  for(int i=0; i<n; i++) {
    cin >> L[i] >> R[i];
  }

  for(int i=0; i<n-1; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(0);
  cout << max(dp[0][0], dp[0][1]) << en;
}

int main() {
  fast;
  int t; cin >> t;
  while(t--) solve();
}
