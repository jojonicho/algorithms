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
typedef tuple<ll, int, int> BFEdges; // bellman-ford edges

const int N = 2505;

vi G[N], RG[N];

int n, m;

int u, v;
ll w;

int main() {
  fast;
  cin >> n >> m;

  vt<BFEdges> edges(m);

  FOR(m) {
    cin >> u >> v, u--, v--;
    cin >> w;
    edges[i] = {w, u, v};
    G[u].pb(v);
    RG[v].pb(u);
  }

  int last = -1;

  ll INF = 1e18;
  vll dist(n, -INF);
  dist[0] = 0;

  vi lasts;
  FOR(n) {
    last = -1;
    for(auto [w, u, v]: edges) {
      ll w2 = dist[u] + w;
      if(w2 > dist[v]) {
        dist[v] = w2;
        last = v;
        if(i == n-1)
          lasts.pb(last);
      }
    }
  }

  vt<bool> processed(n);

  if(last != -1) { // positive cycle
    bool flag = 0; // check if any of the cycle reaches n, and if 1 reaches the cycle

    for(auto i: lasts) {
      if(processed[i])
        continue;

      auto bfs = [&](int i, vi G[], int target) {
        queue<int> q;
        q.push(i);
        vt<bool> vis(n);

        while(!q.empty()) {
          u = q.front(); q.pop();
          if(u == target) {
            return true;
          }
          if(vis[u])
            continue;

          vis[u] = 1;
          processed[u] = 1;

          for(auto v: G[u]) {
            q.push(v);
          }
        }
        return false;
      };

      if(bfs(i, G, n-1) && bfs(i, RG, 0)) {
        flag = 1;
        break;
      }
    }

    if(flag) {
      cout << -1 << en;
      return 0;
    }
  }
  cout << dist[n-1] << en;
}

