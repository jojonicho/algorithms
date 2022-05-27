#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'
#define all(x) (x).begin(), (x).end()

typedef vector<int> vi;

const int N = 1e5 + 5;
const int INF = N;

vi G[N];
int indeg[N];
int dp[N];
int prv[N];

int n, m;
int u, v;


// DAG
int main() {
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    indeg[v]++;
  }

  queue<int> q;
  for(int i=0; i<n; i++) {
    if(indeg[i] == 0) q.push(i);
    prv[i] = -1;
    dp[i] = -INF;
  }

  dp[0] = 1;

  while(!q.empty()) {
    int u = q.front(); q.pop();
    int cur = dp[u] + 1;
    for(auto v: G[u]) {
      if(cur > dp[v]) {
        dp[v] = cur;
        prv[v] = u;
      }
      if(--indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  if(dp[n-1] < 0) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  vi ans;
  int u = n-1;
  while(u != -1) {
    ans.pb(u);
    u = prv[u];
  }

  cout << dp[n-1] << en;
  reverse(all(ans));
  for(auto x: ans) cout << x + 1 << " ";
}
