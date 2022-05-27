#include <bits/stdc++.h>
using namespace std;
#define en '\n';

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

const int N = 405, M = 405;

int dp[N][N], A[N][N];
int n, m;
int cost[M];  // prefix cost of emptying purple portal area and having obsidian
              // outline wrt costumn

void solve() {
  memset(dp, 0, sizeof(dp));
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      A[i][j] = s[j - 1] == '1';
      // dp[i][j] = A[i][j] + dp[i-i][j] + dp[i][j-1] - dp[i-1][j-1];
      dp[i][j] = A[i][j] +
                 dp[i - 1][j];  // we actually only need to prefix sum the rows
    }
  }

  const int INF = m * n;
  int ans = INF;

  for (int i = 1; i <= n - 4; i++) {
    for (int i2 = i + 4; i2 <= n; i2++) {
      for (int j = 1; j <= m; j++) {
        cost[j] = 0;
        cost[j] =
            cost[j - 1] + dp[i2 - 1][j] - dp[i][j] + (!A[i][j]) + (!A[i2][j]);
      }
      int mn = INF;
      for (int j = m - 3; j >= 1; j--) {
        int j2 = j + 3;
        mn = min(mn, i2 - i - 1 - (dp[i2 - 1][j2] - dp[i][j2]) + cost[j2 - 1]);
        ans = min(ans, mn - cost[j] + i2 - i - 1 - (dp[i2 - 1][j] - dp[i][j]));
      }
    }
  }
  cout << ans << en;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}