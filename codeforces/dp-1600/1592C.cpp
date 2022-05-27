#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back

#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL);
#define F_OR(i, a, b, s) \
  for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)     \
  F_ORC(__VA_ARGS__) \
  (__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...)     \
  E_ACHC(__VA_ARGS__) \
  (__VA_ARGS__)

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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y <<
// ")"; return dd; }

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/
const int N = 1e5 + 5;
int A[N], X[N];
vi G[N];

int dfs(int u, int p) {
  X[u] = A[u];
  for (auto v : G[u]) {
    if (v == p) continue;
    X[u] ^= dfs(v, u);
  }
  return X[u];
}

int dfs2(int u, int p, int x) {
  int xCnt = 0;
  for (auto v : G[u]) {
    if (p == v) continue;
    xCnt += dfs2(v, u, x);
    if (xCnt >= 2) return 2;
  }

  if (X[u] == 0 && xCnt >= 1) return 2;
  if (X[u] == x || xCnt >= 1) return 1;
  return 0;
}

void solve() {
  int n, k;
  cin >> n >> k;

  FOR(n) cin >> A[i];
  FOR(n - 1) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  int x = dfs(0, -1);
  if (x == 0)
    cout << "YES" << en;
  else if (k == 2)
    cout << "NO" << en;
  else {
    cout << (dfs2(0, -1, x) == 2 ? "YES" : "NO") << en;
  }

  // x ^ x = 0
  // x ^ x ^ x = x
  memset(A, 0, sizeof(A));
  memset(X, 0, sizeof(X));
  FOR(n) G[i].clear();
}

int main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}