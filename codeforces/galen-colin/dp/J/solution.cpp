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
  cin.tie(NULL);

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

/*
if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

int n, m;
int u, v;
int k, x;

const int N = 1e5 + 5, X = 11;
const int MOD = 1e9 + 7;

int dp[N][X][3]; // node, nHighest, </>/= k
int ndp[X][3];

vi G[N];

int add(ll x, ll y) {
  return (x + y) % MOD;
}

int mul(ll x, ll y) {
  return (x * y) % MOD;
}

void dfs(int u, int p=-1) {
  // these coefficients are only for the first placement
  dp[u][0][1] = k-1;
  dp[u][0][2] = m-k;
  dp[u][1][0] = 1;

  for(auto v: G[u]) {
    if(v==p)continue;
    // = k
    // < k
    // > k

    dfs(v, u);
    memset(ndp, 0, sizeof(ndp)); // use another dp dimension to store the current dp values

    for(int i=0; i<=x; i++) {
      for(int j=0; j+i<=x; j++) {
        int lt = dp[v][j][1];
        int gt = dp[v][j][2];
        int eq = dp[v][j][0];

        int cur0 = mul(dp[u][i][0], lt);
        ndp[i+j][0] = add(ndp[i+j][0], cur0);

        int lg = add(lt, gt);
        int lgeq = add(lg, eq);

        int cur1 = mul(dp[u][i][1], lgeq);
        ndp[i+j][1] = add(ndp[i+j][1], cur1);

        int cur2 = mul(dp[u][i][2], lg);
        ndp[i+j][2] = add(ndp[i+j][2], cur2);
      }
    }

    for(int i=0; i<=x; i++) {
      // update coefficients for every children
      dp[u][i][0] = ndp[i][0];
      dp[u][i][1] = ndp[i][1];
      dp[u][i][2] = ndp[i][2];
    }
  }
}

void solve() {
  cin >> n >> m;
  FOR(n-1) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  cin >> k >> x;
  dfs(0);

  int ans = 0;
  for(int i=0; i<=x; i++) {
    int cur = add(dp[0][i][0], add(dp[0][i][1], dp[0][i][2]));
    ans = add(ans, cur);
  }
  cout << ans << en;

}

int main() {
  fast;
  int t=1;
  //cin >> t;
  while(t--)
    solve();
}

