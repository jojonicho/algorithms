#include <bits/stdc++.h>
using namespace std;

#define en '\n'

typedef long long ll;

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

const int N = 1e3 + 5, K = 1e3 + 5;
const int MOD = 1e9 + 7;

ll dp[N][K][2]; // n, k. direction

int n, k;

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll go(int i, int j, int right) {
  if(j == 1 || i == 0 || i == n + 1) return 1;
  ll &ans = dp[i][j][right];
  if(ans != -1) return ans;
  if(right) return ans = add(go(i+1, j, 1), go(i-1, j-1, 0));
  return ans = add(go(i-1, j, 0), go(i+1 ,j-1, 1));
}

void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> k;

  //for(int i=1; i<=n; i++) {
    //for(int j=1; j<=k; j++) {
      //dp[i][j][0] = dp[i][j][1] = 1;
    //}
  //}

  //for(int j=1; j<=k; j++) {
    //for(int i=n; i>=1; i--) {
      //dp[i][j][1] = add(dp[i+1][j][1], dp[i-1][j-1][0]);
    //}
    //for(int i=1; i<=n; i++) {
      //dp[i][j][0] = add(dp[i+1][j][0], dp[i+1][j-1][1]);
    //}
    //for(int i=1; i<=n; i++) {
      //for(auto x: {0, 1}) dp[i][j][x] = add(dp[i][j][x], 1);
    //}

    //for(int i=1; i<=n; i++) debug() << im(i) im(j) im(dp[i][j][0]) im(dp[i][j][1]);
  //}

  cout << go(1, k, 1) << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
