#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;

const int N = 5e3+5, M = 5e3+5;
const int INF = 1e9 + 5;

bool vis[N];
int dp[N][N]; // node i, cost of reaching j other nodes
int nxt[N][N];

vector<array<int, 2>> G[N];

int n, m, t;
int u, v, c;

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = 1;

  for(auto [c, v]: G[u]) {
    dfs(v);
    for(int i=1; i<=n; i++) {
      ll curCost = dp[v][i-1] + c;
      if(curCost < dp[u][i]) {
        dp[u][i] = curCost;
        nxt[u][i] = v;
      }
    }
  }
}

int main() {
  cin >> n >> m >> t;
  for(int i=0; i<m; i++) {
    cin >> u >> v >> c, u--, v--;
    G[u].pb({c, v});
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<=n; j++) {
      dp[i][j] = INF;
    }
  }

  dp[n-1][0] = 0; // set node n-1 as the only endpoint
  dfs(0);

  int j = 0;
  for(int i=1; i<=n; i++) {
    if(dp[0][i] <= t) j = i;
  }

  cout << j + 1 << en;
  int u = 0;
  for(int i=j; i>=0; i--) {
    cout << u + 1 << " ";
    u = nxt[u][i];
  }
}
