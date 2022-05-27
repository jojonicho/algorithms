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

const int MOD = 1e9 + 7;

const int X = 5e5;
ll iv[X + 1], fact[X + 1], ifact[X + 1];
ll nCk(int n, int k) { 
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= X; i++) {
    iv[i] = MOD - MOD / i * iv[MOD % i] % MOD;
    fact[i] = fact[i - 1] * i % MOD;
    ifact[i] = ifact[i - 1] * iv[i] % MOD;
  }
}

int add(ll x, ll y) {
  return (x + y) % MOD;
}

int mul(ll x, ll y) {
  return (x * y) % MOD;
}

int binpow(ll x, int p) {
  if(!p) return 1;
  if(p&1) return mul(x, binpow(x, p-1));
  return binpow(mul(x, x), p/2);
}

void solve() {
  int n, m;
  cin >> n >> m;

  // A_i != A_j
  // A_i != B_i

  // approaches
  // 1. find the question asked
  // 2. find total - A_i == B_i - A_i == A_j + (A_i == B_i && A_i == A_j)
  //
  // approach 2

  // pie
  // 1. number of A_i == A_j
  // 2. derangements between A and B

  int derangements = 0;
  int sgn = 1;

  for(int i=0; i<=n; i++) {
    int eq = nCk(n, i); // choose i elements, A_i == B_i
    int neq = fact[n-i]; // the rest n-i elements
    // eq * neq is basic derangements

    // now, how to incorporate the A_i != A_j rule?
    eq = mul(eq, nCk(m, i)); // valid configuration of A_i is nCk(m, i) * fact[i] or nPk(m, i)
    eq = mul(eq, fact[i]); // order matters

    // valid B_i, same rules as A_i, except now we only have m-i colors left
    neq = nCk(m-i, n-i);
    neq = mul(neq, fact[n-i]);
    neq = mul(neq, neq); // because we have two arrays, A and B
    // A = [1, 2] B = [2, 1]
    // B = [1, 2] A = [2, 1]

    int cur = mul(eq, neq);

    derangements = add(derangements, mul(cur, MOD+sgn));

    sgn *= -1;
  }

  cout << derangements << en;
}

int main() {
  fast;
  pre();
  int t=1;
  //cin >> t;
  while(t--)
    solve();
}

