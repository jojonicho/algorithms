#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define vt vector
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back

#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);

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
#define dor > dbg &operator<<
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, dbg &>::type operator<<( \
            c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct dbg {
#ifdef LOCAL
  ~dbg() { cerr << endl; }
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
};

#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/*
if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

typedef ar<int, 3> Edge; // minutes, coins, v
typedef tuple<ll, int, int> State; // minutes, coins, edge

const int MXC = 49 * 50;

void solve() {
  int n, m, s;
  cin >> n >> m >> s;

  // minimize time
  // not amount of silver coins used
  // max silver coins = 50 * M (nEdges) = 50 * 100 = 5000
  // dp?

  vt<vt<Edge>> G(n);

  for(int i=0; i<m; i++) {
    int u, v;
    int a, b;
    cin >> u >> v, u--, v--;
    cin >> a >> b;

    G[u].pb({b, a, v});
    G[v].pb({b, a, u}); // time, cost
  }

  vt<int> C(n), D(n);

  for(int i=0; i<n; i++)
    cin >> C[i] >> D[i]; // cost, time

  s = min(s, MXC);

  priority_queue<State, vt<State>, greater<State>> pq;
  pq.push({0, s, 0});

  const ll INF = 1e18;
  vt<vt<ll>> dp(n, vt<ll>(MXC+1, INF));
  dp[0][s] = 0;

  while(!pq.empty()) {
    auto [tu, cu, u] = pq.top(); pq.pop();
    if(tu > dp[u][cu])
      continue;

    for(auto [tv, cv, v]: G[u]) {
      for(int i=0; i<=MXC; i++) {
        int c = min<ll>(MXC, cu - cv + (ll) i * C[u]);
        if(c < 0)
          continue;
        ll t = tu + tv + (ll) i * D[u];

        if(t < dp[v][c]) {
          dp[v][c] = t;
          pq.push({t, c, v});
        }
        if(c == MXC)
          break;
      }
    }
  }

  for(int i=1; i<n; i++)
    cout << *min_element(all(dp[i])) << en;
}

int main() {
  fast;
  int t=1;
  //cin >> t;
  while(t--)
    solve();
}

