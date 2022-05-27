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

const int MOD = 1e9 + 7;
const ll MOD2 = 4LL * MOD * MOD;
ll add(ll x, ll y) {
  ll res = x + y;
  if(res >= MOD2)
    res -= MOD2;
  return res;
}

struct Mat {
  vt<vt<ll>> v;
  int n, m;
  Mat(int n, int m) : n(n), m(m) { 
    v = vt<vt<ll>>(n, vt<ll>(m));
  }
  Mat operator*(Mat &b) {
    Mat c(n, b.m);
    for(int i=0; i<n; i++) {
      for(int k=0; k<b.n; k++) {
        for(int j=0; j<b.m; j++) {
          c.v[i][j] = add(c.v[i][j], v[i][k] * b.v[k][j]);
        }
      }
    }
    for(int i=0; i<n; i++)
      for(int j=0; j<b.m; j++)
        c.v[i][j] %= MOD;
    return c;
  };

  Mat operator^(ll p) {
    Mat r(n, m), a(*this);
    for(int i=0; i<n; i++)
      r.v[i][i] = 1;
    while(p) {
      if(p&1)
        r = r * a;
      a = a * a;
      p /= 2;
    }
    return r;
  }
};

int n, m, k;
int u,v;

int main() {
  fast;
  cin >> n >> m >> k;
  Mat res(n, n);

  while(m--) {
    cin >> u >> v, u--, v--;
    res.v[u][v]++;
  }

  res = res ^ k;
  //dbg() << im(res.v);
  cout << res.v[0][n-1] << en;
}

