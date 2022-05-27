#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

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

// Each test case begins with a line containing two integers integer N, the
// number of trees on Alan's farm, and K, the capacity of Barbara's basket.

// Barbara wants to buy some number of trees such that the total number of
// banana bunches on these purchased trees equals the capacity K of her basket.
// She wants to do this while spending as little money as possible. How many
// trees should she buy?
const int K = 1e3 + 5, N = 5005;
const ll INF = 5e9 + 5;
ll dp[N][K][4];  // curK, isConsecutive
int B[N];
int n, k;
ll go(int idx, int curK, int isCon) {
  if (curK == 0) return dp[idx][0][isCon] = 0;
  if (isCon == 4) {
    return INF;
  }
  if (idx >= n) {
    return INF;
  }

  ll &ans = dp[idx][curK][isCon];
  if (ans != -1) return ans;

  ll take = INF, jump = INF, skip = INF;

  if (isCon == 0 || isCon == 2) {
    skip = go(idx + 1, curK, isCon);  // skipping
    take = 1 + go(idx + 1, curK - B[idx], isCon + 1);
  }
  if (isCon == 1 || isCon == 3) {
    take = 1 + go(idx + 1, curK - B[idx], isCon);  // keep taking
    skip = go(idx + 1, curK, isCon + 1);
  }
  return ans = min({take, skip});
}

void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  FOR(n) cin >> B[i];
  dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 0;
  ll ans = go(0, k, 0);
  if (ans >= INF) ans = -1;
  cout << ans << en;
}

int main() {
  fast;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}