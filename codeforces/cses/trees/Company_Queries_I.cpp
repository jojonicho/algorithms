#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define en '\n'
typedef vector<int> vi;
 
#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<( \
            c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) cerr << boolalpha << i;
  ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
  sim dor(const c &) { ris; }
#endif
}
;
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y <<
// ")"; return dd; }
 
const int N = 2e5+5;
const int LOG = 18;
 
vi G[N];
int up[N][LOG];
int depth[N];
 
int n, q;
 
void dfs(int u, int p=-1) {
  for(auto v: G[u]) {
    if(v == p) continue;
    up[v][0] = u; // 2^0 = 1
    depth[v] = depth[u] + 1;
 
    for(int i=1; i<LOG; i++) {
      up[v][i] = up[up[v][i-1]][i-1]; // 8 = 4 + 4
    }
    dfs(v, u);
  }
}
 
int main() {
  cin >> n >> q;
  for(int i=1; i<n; i++) {
    int v; cin >> v, v--;
    int u = i;
    G[u].pb(v);
    G[v].pb(u);
  }
 
  dfs(0);
 
  while(q--) {
    int u, k; cin >> u >> k, u--;
    int dist = k - 1;
 
    for(int i=LOG-1; i>=0; i--) {
      if((dist >> i) & 1) {
        u = up[u][i];
      }
    }
 
    if(u == 0) {
      cout << -1 << en;
      continue;
    }
    u = up[u][0];
    cout << u + 1 << en;
  }
 
}
