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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

/*
DEBUG: -D LOCAL
dbg() << imie(k) imie(x) imie(row) imie(col);
*/

typedef tuple<ll, int> Edge;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll dp[N];
ll dist[N];
vt<Edge> G[N];
int dp_min[N];
int dp_max[N];

int n, m;
int u, v;
int w;

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

int main() {
  fast;
  cin >> n >> m;
  while(m--) {
    cin >> u >> v, u--, v--;
    cin >> w;
    G[u].pb({w, v});
  }

  FOR(n) {
    dist[i] = INF;
    dp_min[i] = n + 1;
    dp_max[i] = 0;
  }

  priority_queue<Edge, vt<Edge>, greater<Edge>> pq;
  pq.push({0, 0});
  dist[0] = 0;
  dp[0] = 1;
  dp_min[0] = 0;
  dp_max[0] = 0;

  while(!pq.empty()) {
    auto [wu, u] = pq.top(); pq.pop();
    for(auto [wv, v]: G[u]) {
      ll w = wu + wv;
      if(w < dist[v]) {
        dist[v] = w;
        dp[v] = dp[u];
        dp_min[v] = dp_min[u] + 1;
        dp_max[v] = dp_max[u] + 1;
        pq.push({w, v});
      } else if(w == dist[v]) {
        dp[v] = add(dp[v], dp[u]);
        chmax(dp_max[v], dp_max[u] + 1);
        chmin(dp_min[v], dp_min[u] + 1);
      }
    }
  }

  cout << dist[n-1] << " ";
  cout << dp[n-1] << " ";
  cout << dp_min[n-1] << " ";
  cout << dp_max[n-1] << " ";

  cout << en;
}

