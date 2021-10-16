#include <bits/stdc++.h>
using namespace std;

#define int long long

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

bool is_compact(int x, int y, int n) {
  while (n) {
    if (n % 10 != x && n % 10 != y) {
      return false;
    }
    n /= 10;
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int M = 1e9 + 7;
  int x, y, n;
  cin >> x >> y >> n;

  vector<vector<int>> dp(n + 1, vector<int>(9 * n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int d = (i == n ? 1 : 0); d <= 9; d++) {
      for (int j = d; j <= 9 * n; j++) {
        dp[i][j] += dp[i - 1][j - d];
        dp[i][j] %= M;
        debug() << imie(j) imie(dp[i][j]);
      }
    }
  }

  int ans = 0;
  for (int j = 1; j <= 9 * n; j++) {
    if (is_compact(x, y, j)) {
      debug() << imie(j) imie(dp[n][j]);
      ans += dp[n][j];
      ans %= M;
    }
  }

  cout << ans << "\n";
  return 0;
}