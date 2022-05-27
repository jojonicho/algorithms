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

#define pb push_back

typedef long long ll;
typedef vector<int> vi;

const int N = 1005;
const int T = 1000;
const ll INF = 1e18 + 10;

int M[N];
vi G[N];
ll dp[N][T + 1];

int n, m, c;
int u, v;

int main() {
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);
  cin >> n >> m >> c;
  for(int i=0; i<n; i++) {
    for(int j=0; j<=T; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;

  for(int i=0; i<n; i++) cin >> M[i];

  for(int i=0; i<m; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
  }

  ll ans = 0;
  for(int t=1; t<=T; t++) {
    for(int u=0; u<n; u++) {
      for(auto v: G[u]) {
        dp[v][t] = max(dp[v][t], dp[u][t-1] + M[v]);
        debug() << im(u) im(v) im(t) im(dp[v][t]);
      }
    }
    ans = max(ans, dp[0][t] - c * t * t);
  }

  cout << ans;
}
