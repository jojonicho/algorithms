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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

/*
DEBUG: -D LOCAL
dbg() << imie(k) imie(x) imie(row) imie(col);
*/

// A_i <= 70

const int X = 70, N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll iv[N + 1], fact[N + 1], ifact[N + 1];
ll nCk(int n, int k) { 
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}
void factorials(int n) {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= n; i++) {
    iv[i] = MOD - MOD / i * iv[MOD % i] % MOD;
    fact[i] = fact[i - 1] * i % MOD;
    ifact[i] = ifact[i - 1] * iv[i] % MOD;
  }
}

vi primes;
int lpf[X+1], mu[X+1];
void sieve(int x) {
  mu[1] = 1; // 1 has 0 (even) prime factors
  for(int i=2; i<=x; i++) {
    if(lpf[i] == 0) {
      lpf[i] = i;
      mu[i] = -1;
      primes.pb(i);
    }

    for(auto p: primes) {
      ll nxt = (ll)p * i;
      if(nxt > x || lpf[i] < p)
        break;
      lpf[nxt] = p;

      if(lpf[i] == p)
        mu[nxt] = 0;
      else
        mu[nxt] = -mu[i];
    }
  }
}

vt<pii> primeFactorize(int x) {
  if(x == 1) {
    return {};
  }
  vt<pii> res;
  int prv = lpf[x], cnt = 0;
  while(x > 1) {
    int p = lpf[x];
    if(p != prv) {
      res.pb({prv, cnt});
      cnt = 0;
      prv = p;
    }
    cnt++;
    x /= p;
  }
  res.pb({prv, cnt});

  return res;
}

int n;

int cnt[X+1];
const int K = 19, MASK = 1 << K;
int dp[X+5][MASK];

int main() {
  fast;
  cin >> n;
  vi A(n);
  FOR(n) {
    cin >> A[i];
    cnt[A[i]]++;
  }

  int mx = *max_element(all(A));

  sieve(mx);
  factorials(n);

  int nPrimes = sz(primes);
  int MASK = 1 << nPrimes;

  int idx = 0;
  map<int, int> idxOf;
  for(int i=0; i<nPrimes; i++) {
    idxOf[primes[i]] = i;
  }

  dp[1][0] = 1;
  FOR(i, 1, mx + 1) {
    vt<pii> primeFactors = primeFactorize(i);
    int mask2 = 0;
    for(auto [p, cntP]: primeFactors) {
      if(cntP&1)
        mask2 |= 1 << idxOf[p];
    }

    ll cOdd = 0, cEven = 0;

    for(int j=0; j<=cnt[i]; j+=2) {
      cEven = add(cEven, nCk(cnt[i], j));
    }
    for(int j=1; j<=cnt[i]; j+=2) {
      cOdd = add(cOdd, nCk(cnt[i], j));
    }

    FOR(mask, MASK) {
      dp[i+1][mask^mask2] = add(dp[i+1][mask ^ mask2], mul(cOdd, dp[i][mask]));
      dp[i+1][mask] = add(dp[i+1][mask], mul(cEven, dp[i][mask]));
    }
  }

  cout << add(dp[mx+1][0], MOD - 1) << en;
}

