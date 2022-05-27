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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}

const int N = 1005, K = 1005;
const ll INF = 1e15 + 10;
ll A[N], skip[N][K], buy[N][K], take[N][K];
int n, k;

void solve() {
  memset(skip, 0x3f, sizeof(skip));
  memset(buy, 0x3f, sizeof(buy));
  memset(take, 0x3f, sizeof(take));
  cin >> n >> k;
  FOR(n) cin >> A[i];

  FOR(n) {
    skip[i][0] = buy[i][0] = take[i][0] = 0;
    for (int j = k; j >= 0; j--) {
      // skip
      skip[i][j] =
          min({skip[i][j], skip[i - 1][j], buy[i - 1][j], take[i - 1][j]});
      // buy
      buy[i][j] =
          min(buy[i][j],
              min({buy[i - 1][j - 1], take[i - 1][j - 1], skip[i - 1][j - 1]}) +
                  A[i]);
      // take
      take[i][j] = min(take[i][j], buy[i - 2][j - 2]);
    }
  }
  cout << min({buy[n - 1][k], take[n - 1][k], skip[n - 1][k]}) << en;
}

int main() {
  fast;
  int t;
  cin >> t;
  FOR(t) {
    cout << "Case " << i + 1 << ": ";
    solve();
  }
}