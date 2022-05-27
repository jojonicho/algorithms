#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef long long ll;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

vi G[N];
int indeg[N];
ll dp[N];

int n, m;
int u, v;

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

int main() {
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    indeg[v]++;
  }

  queue<int> q;
  for(int i=0; i<n; i++) if(indeg[i] == 0) q.push(i);
  dp[0] = 1;
  
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(auto v: G[u]) {
      dp[v] = add(dp[v], dp[u]);
      if(--indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  cout << dp[n-1];
}
