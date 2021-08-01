#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define vpill vector<pair<int, long long>>
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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

const int W = 50, GAP = W + 1, INF = 1e9 + 5;

int n, m;

struct comp {
  bool operator()(pill &a, pill &b) { return b.second < a.second; }
};
priority_queue<pill, vpill, comp> pq;

int main() {
  fast;
  cin >> n >> m;

  vpii G[n * GAP];
  auto add_edge = [&](int u, int v, int w) {
    u *= GAP;
    v *= GAP;
    G[u].pb({v + w, 0});
    //   debug() << imie(u) imie(v + w);
    FOR(i, 1, GAP) {
      // debug() << imie(u + i) imie(v) imie((w + i) * (w + i));
      G[u + i].pb({v, (w + i) * (w + i)});
    }
  };

  FOR(m) {
    int u, v, w;
    cin >> u >> v >> w;
    // undirected to directed edges
    u--;
    v--;
    add_edge(u, v, w);
    add_edge(v, u, w);
  }

  ll dist[n * GAP];
  fill(dist, dist + n * GAP, INF);

  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    int u = cur.first;
    ll w = cur.second;
    for (auto next : G[u]) {
      int v = next.first;
      ll x = next.second;
      ll weight = w + x;
      if (dist[v] > weight) {
        dist[v] = weight;
        pq.push({v, weight});
      }
    }
  }

  FOR(n) {
    int ans = dist[i * GAP];
    if (ans == INF) {
      ans = -1;
    }
    cout << ans << " ";
  }
  cout << en;
}