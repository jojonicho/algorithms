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

const int N = 2e5 + 5;

int vis[N];
vi S;
vi G[N], RG[N];

void dfs1(int u) {
  if(vis[u])
    return;
  vis[u] = 1;
  for(auto v: G[u])
    dfs1(v);
  S.pb(u);
}

int C[N];

void dfs2(int u, int rt) {
  if(vis[u] == 0)
    return;
  vis[u] = 0;
  C[u] = rt;
  for(auto v: RG[u])
    dfs2(v, rt);
  // do something with the component
}

int n, m;
int u, v;

int main() {
  fast;
  cin >> n >> m; // nPeople, nObjects
  m *= 2;

  char a, b;
  FOR(n) {
    cin >> a >> u >> b >> v, u--, v--;
    // x1 V x2 
    // ~x1 -> x2
    // ~x2 -> x1 
    // because atleast one of x1 or x2 must be true
    
    // x1 -> 2*u
    // ~x1 -> 2*u + 1

    u *= 2;
    v *= 2;
    int nu = u + 1, nv = v + 1;

    if(a == '-')
      swap(u, nu);
    if(b == '-')
      swap(v, nv);

    G[nu].pb(v);
    RG[v].pb(nu);

    G[nv].pb(u);
    RG[u].pb(nv);
  }

  for(int i=0; i<m; i++) {
    if(vis[i])
      continue;
    dfs1(i);
  }
  
  int c = 0;
  for(int i=m-1; i>=0; i--) {
    int u = S[i];
    if(vis[u] == 0)
      continue;
    dfs2(u, c++);
  }

  vt<char> ans(m);
  for(int i=0; i<m; i+=2) {
    if(C[i] == C[i+1]) {
      cout << "IMPOSSIBLE" << en;
      return 0;
    }
    int idx = i/2;
    // topological order
    // if C[x1] < C[~x1] -> x1 should be false
    ans[idx] = (C[i] > C[i+1] ? '+' : '-');
  }

  for(auto x: ans)
    cout << x << " ";
  cout << en;
}

