#include <bits/stdc++.h>

//#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py a.cpp

using namespace std;
//using namespace atcoder;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
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
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
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

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

const int N = 1e5 + 5;

vector<int> st[N];

vi G[N];
int X[N];
int ans[N][25];

int n, q;
int u, v;
int k;

void dfs(int u, int p=-1) {
  //st[u].insert(X[u]);
  st[u].pb(X[u]);
  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);
    // small to large
    //multiset<int> &stU = st[u], &stV = st[v];
    vector<int> &stU = st[u], &stV = st[v];
    int szU = stU.size(), szV = stV.size();
    if(szU < szV) swap(stU, stV);
    for(auto x: stV) stU.pb(x);
    //st[u] = stU;
  }
  vector<int> stU = st[u];
  sort(all(stU));
  // kth biggest = stU[n-1-k]
  k = 0;
  int len = stU.size();
  int idx = len - 1;
  while(idx >= 0) {
    ans[u][k] = stU[idx];
    k++;
    idx--;
  }
  //auto it = stU.rbegin();
  //while(it != stU.rend()) {
    //ans[u][k] = *it;
    //it++;
    //k++;
  //}

}

int main() {
  fast;
  cin >> n >> q;

  for(int i=0; i<n; i++) cin >> X[i];

  for(int i=0; i<n-1; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(0);

  while(q--) {
    cin >> u >> k, u--, k--;
    cout << ans[u][k] << en;
  }
}
