#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'
#define ar array
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;

const int N = 5e3 + 5;
const int INF = 1e9 + 5;

int indeg[N], prv[N][N], dp[N][N];
vector<ar<int,2>> G[N];

int n, m, t;
int u, v, c;

int main() {
  cin >> n >> m >> t;

  for(int i=0; i<m; i++) {
    cin >> u >> v >> c, u--, v--;
    G[u].pb({c, v});
    indeg[v]++;
  }
  
  queue<int> q;
  for(int i=0; i<n; i++) {
    for(int j=0; j<=n; j++) {
      prv[i][j] = -1;
      dp[i][j] = INF;
    }
    if(indeg[i] == 0) q.push(i);
  }

  dp[0][0] = 0;

  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(auto [c, v]: G[u]) {
      for(int i=1; i<=n; i++) {
        ll cur = dp[u][i-1] + c;
        if(cur < dp[v][i]) {
          prv[v][i] = u;
          dp[v][i] = cur;
        }
      }
      if(--indeg[v] == 0) q.push(v);
    }
  }

  int j=0;
  for(int i=1; i<=n; i++) if(dp[n-1][i] <= t) j = i;

  cout << j + 1 << en;

  int u = n-1;
  vi ans;
  while(u != -1) {
    ans.pb(u);
    u = prv[u][j];
    j--;
  }

  reverse(all(ans));
  for(auto x: ans) cout << x + 1 << " ";
}
