#include<bits/stdc++.h>
using namespace std;

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

const int N = 1e5 + 5;
const int K = 25;
const int HOOF = 1, PAPER = 2, SCISSORS = 3;

//char C[N];
int C[N];
int dp[N][K][4];

int n,k;

int main() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  cin >> n >> k;
  for(int i=1; i<=n; i++) {
    char c; cin >> c;
    if(c == 'H') C[i] == HOOF;
    else if(c == 'P') C[i] = PAPER;
    else C[i] = SCISSORS;
  }

  auto getWin = [&](int x) {
    if(x == HOOF) return PAPER;
    if(x == PAPER) return SCISSORS;
    return HOOF;
  };

  for(int i=1; i<=n; i++) {
    for(int j=0; j<=k; j++) {
      // stay
      for(auto x: {1, 2, 3})
        dp[i][j][x] = dp[i-1][j][x] + (getWin(C[i]) == x);
      if(j == 0) continue;
      // win
      for(auto x: {1, 2, 3}) {
        int win = getWin(x);
        dp[i][j][win] = max(dp[i][j][win], (getWin(C[i]) == win) + dp[i-1][j-1][x]);
      }
    }
  }

  int ans = 0;
  for(int j=0; j<=k; j++)
    for(auto x: {1, 2, 3})
      ans = max(ans, dp[n][j][x]);

  cout << ans;
}

