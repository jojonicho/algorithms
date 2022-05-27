#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back

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

const int N = 2e5 + 5;

vi G[N];

// int dist[N][N];
map<int, array<int, N>> dist;

int dfs(int start, int u, int p = -1, int d = 0) {
  int mxNode = u, mx = 0;
  dist[start][u] = d;

  for (auto v : G[u]) {
    if (v == p) continue;
    int candidate = dfs(start, v, u, d + 1);
    if (dist[start][candidate] > mx) {
      mx = dist[start][candidate];
      mxNode = candidate;
    }
  }
  return mxNode;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  int u = dfs(0, 0);  // find one of the diameter endpoint
  int v = dfs(u, u);  // find the other diameter endpoint
  dfs(v, v);
  // dfs(u, u) and dfs(v, v) but MLE so u -> 0 and v -> 1

  for (int i = 0; i < n; i++) cout << max(dist[u][i], dist[v][i]) << " ";
}