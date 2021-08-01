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

const int M = 1e9 + 7;

int mul(const int v1, const int v2) { return (int)((1LL * v1 * v2) % M); }

int mod_pow(int a, int p) {
  int res = 1;
  while (p != 0) {
    if (p & 1) res = mul(res, a);
    p >>= 1;
    a = mul(a, a);
  }
  return res;
}

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/
const int N = 500;
ll h, w, n;
ll G[N + 5][N + 5] = {}, memo[N + 5][N + 5];

ll dp(int r, int c) {
  if (c <= 0 || c > w || r == h) {  // reaches the bottom
    return 0;
  }
  if (memo[r][c] != -1) {
    return memo[r][c];
  }
  if (G[r + 1][c]) {
    int c1 = c, c2 = c;
    while (c1 >= 1 && G[r + 1][c1]) {
      c1--;
    }
    while (c2 <= w && G[r + 1][c2]) {
      c2++;
    }
    return memo[r][c] = 1ll + dp(r, c1) + dp(r, c2);
  }
  return memo[r][c] = dp(r + 1, c);
}

int main() {
  fast;
  memset(memo, -1, sizeof(memo));
  cin >> h >> w >> n;

  FOR(n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = a; j <= c; j++) {
      for (int k = b; k <= d; k++) {
        G[j][k] = 1;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= w; i++) {
    chmax(ans, dp(0, i));
  }
  cout << ans << en;
}