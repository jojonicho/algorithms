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

int add(ll x, ll y) {
  return (x + y) % MOD;
}

int mul(ll x, ll y) {
  return (x * y) % MOD;
}

int binpow(ll x, int p) {
  if(p==0) return 1;
  if(p&1) return mul(x, binpow(x, p-1));
  return binpow(mul(x, x), p/2);
}

int inverse(ll x) {
  return binpow(x, MOD-2);
}

int nC2(ll n) {
  return mul(mul(n, n-1), inverse(2));
}

void solve() {
  int n; cin >> n;
  vt<ar<ll,2>> A(n);
  for(int i=0; i<n; i++) {
    cin >> A[i][0] >> A[i][1];
  }

  int nZero = 0;

  map<pair<ll, ll>, int> mp;
  for(int i=0; i<n; i++) {
    auto &[x, y] = A[i];
    if(x == 0 && y == 0) {
      nZero++;
      continue;
    }
    if(x < 0) {
      x = -x;
      y = -y;
    }
    if(x == 0) {
      y = 1; // gcd(0, y), where y is positive is fine
      // but when y is negative, gcd(0, y) = POSITIVE
      // making y /= g still negative
      // basically we want the gcd be = y
    }

    ll g = gcd(x, y);
    x /= g;
    y /= g;

    mp[{x, y}]++;
  }

  int ans = 1;

  for(auto [p, cx]: mp) {
    auto [a, b] = p;
    int sx = binpow(2, cx);

    //pll q = {b, a}; // we find -b/a
    if(b < 0) {
      b = -b;
    } else {
      a = -a;
    }
    pll q = {b, a};

    if(!mp.count(q)) {
      ans = mul(ans, sx);
      continue;
    }

    int cy = mp[q];
    mp.erase(q);

    // any set containing x and y is bad
    // so separate the sets
    int sy = binpow(2, cy);
    int s = add(add(sx, sy), MOD-1);

    ans = mul(ans, s);
  }

  // handle 0/0 case
  // since 0 * a = 0 * b
  // any set with |set| > 1 will be bad
  // so add only set of |set| = 1 to the answer
  ans = add(ans, nZero);

  // decrement the initial ans=1
  ans = add(ans, MOD-1);

  cout << ans << en;
}

int main() {
  fast;
  int t=1;
  //cin >> t;
  while(t--)
    solve();
}

