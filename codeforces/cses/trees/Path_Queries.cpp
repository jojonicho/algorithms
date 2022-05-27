#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'

typedef vector<int> vi;
typedef long long ll;

const int N = 2e5 + 5;
const int LOG = 18;

template <typename T>
struct binary_indexed_tree {
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N) : N(N), BIT(N + 1, 0) {}
  void add(int i, T x) {
    i++;
    while (i <= N) {
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i) {
    i++;
    T ans = 0;
    while (i > 0) {
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R) { return sum(R) - sum(L - 1); }
};
// sort(B, B + n);
// int r = unique(B, B + n) - B;
binary_indexed_tree<ll> BIT(2 * N);

ll A[N], tin[N], tout[N];

vi G[N];

int n, q;
ll x;

int timer;
void dfs(int u, int p=-1) {
  tin[u] = timer;
  BIT.add(timer, A[u]);
  timer++;

  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
  }

  tout[u] = timer;
  BIT.add(timer, -A[u]);
  timer++;
}

int main() {
  cin >> n >> q;
  for(int i=1; i<=n; i++) cin >> A[i];

  for(int i=0; i<n-1; i++) {
    int u, v; cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(1);

  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int u; cin >> u >> x;
      BIT.add(tin[u], x - A[u]);
      BIT.add(tout[u], A[u] - x);
      A[u] = x;
    } else {
      int u; cin >> u;
      cout << BIT.sum(tin[u]) << en;
    }
  }
}
