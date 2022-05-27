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

int n, k, l;
int u, v;

int dp_size[N];
int mp[N];
bool is_removed[N];
ll ans;

vi G[N];

int mx_depth;

int get_subtree_sizes(int u, int p=-1) {
  dp_size[u] = 1;

  for(auto v: G[u]) {
    if(v==p || is_removed[v]) continue;
    dp_size[u] += get_subtree_sizes(v, u);
  }
  return dp_size[u];
}

int get_centroid(int u, int p, int tree_size) {
  for(auto v: G[u]) {
    if(v == p || is_removed[v]) continue;
    if(dp_size[v] * 2 > tree_size)
      return get_centroid(v, u, tree_size);
  }
  return u;
}

void get_ans(int u, int p, int depth, int t) {
  if(depth > k) return;
  chmax(mx_depth, depth);

  if(t == 0)
    mp[depth]++;
  else
    ans += mp[k - depth];

  for(auto v: G[u]) {
    if(v == p || is_removed[v]) continue;
    get_ans(v, u, depth + 1, t);
  }
}

void centroid_decomp(int u) {
  int m = get_subtree_sizes(u); // current total nodes
  u = get_centroid(u, -1, m);
  is_removed[u] = 1;

  for(int i=1; i<=mx_depth; i++) {
    mp[i] = 0;
  }
  mp[0] = 1;

  mx_depth = 0;

  for(auto v: G[u]) {
    if(is_removed[v]) continue;
    get_ans(v, u, 1, 1); // add to ans first, avoid over counting
    get_ans(v, u, 1, 0);
  }

  for(auto v: G[u]) {
    if(is_removed[v]) continue;
    centroid_decomp(v);
  }
}

int main() {
  fast;
  cin >> n >> k;

  FOR(n-1) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  centroid_decomp(0);
  cout << ans << en;
}

