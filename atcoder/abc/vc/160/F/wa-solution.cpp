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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int X = 2e5;

int add(ll x, ll y) {
  return (x+y) % MOD;
}

int mul(ll x, ll y) {
  return (x*y) % MOD;
}

int iv[X + 1], fact[X + 1], ifact[X + 1];
void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= X; i++) {
    iv[i] = MOD - mul(MOD / i, iv[MOD % i]);
    fact[i] = mul(fact[i - 1], i);
    ifact[i] = mul(ifact[i - 1], iv[i]);
  }
}

vt<int> G[N];
int sub[N], dp[N], ans[N];

int n;
int u, v;

int dfs1(int u, int p=-1) {
  sub[u] = 1;
  for(auto v: G[u]) {
    if(v == p)
      continue;
    //sub[u] += dfs1(v, u);
    sub[u] = add(sub[u], dfs1(v, u));
  }
  return sub[u];
}

void dfs2(int u, int p=-1) {
  dp[u] = 1;
  for(auto v: G[u]) {
    if(v==p)
      continue;
    // distribute (n-1) numbers to the subtrees
    // stars and bars?
    // no, permutatations with repetitions
    // every subtree in children is an distinguishable item
    dfs2(v, u);
    dp[u] = mul(dp[u], dp[v]);
    dp[u] = mul(dp[u], ifact[sub[v]]);
  }
  dp[u] = mul(dp[u], fact[sub[u] - 1]);
}

int bin_pow(int x, int p) {
  if(p==0) return 1;
  if(p&1) return mul(x, bin_pow(x, p-1));
  return bin_pow(mul(x, x), p/2);
}

int inverse(int x) {
  return bin_pow(x, MOD-2);
}

void dfs3(int u, int p=-1, int pdu=1) {
  ans[u] = mul(dp[u], pdu);
  for(auto v: G[u]) {
    if(v==p)
      continue;
    int pdv = mul(ans[u], ifact[sub[v]-1]);
    pdv = mul(pdv, inverse(dp[v]));
    pdv = mul(pdv, fact[sub[v]]);

    pdv = mul(pdv, ifact[n-sub[v]]);
    dfs3(v, u, pdv);
  }
}

void solve() {
  cin >> n;

  FOR(n-1) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs1(0);
  dfs2(0);
  dfs3(0);

  for(int i=0; i<n; i++)
    cout << ans[i] << en;
}

int main() {
  fast;
  int t=1;
  //cin >> t;
  pre();
  while(t--)
    solve();
}


