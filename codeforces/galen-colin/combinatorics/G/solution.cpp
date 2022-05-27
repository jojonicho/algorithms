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
#define eni(x) \
  sim > typename enable_if<sizeof dud<c>(0) x 1, dbg &>::type operator<<(c i) {
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
}
;

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

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int X = 1e5;

int cnt[N], lpf[N], mu[N];

int n;

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

ll bin_pow(ll x, ll p) {
  if(p==0) return 1;
  if(p&1) return mul(x, bin_pow(x, p-1));
  return bin_pow(mul(x, x), p/2);
}

vi primes;
void pre() {
  mu[1] = 1; // 1 has 0 (even) number of prime factors;
  for(int i=2; i<=X; i++) {
    if(lpf[i] == 0) {
      lpf[i] = i;
      mu[i] = -1;
      primes.pb(i);
    }

    for(auto p: primes) {
      ll nxt = (ll) p * i;
      if(nxt > X || lpf[i] < p)
        break;
      lpf[nxt] = p;
      // mobius function
      if(p < lpf[i])
        mu[nxt] = -mu[i];
      else // p == lpf[i]
        mu[nxt] = 0;
    }
  }
}

int main() {
  fast;
  pre();

  cin >> n;
  vi A(n);
  FOR(n)
    cin >> A[i];

  for(auto x: A)
    cnt[x]++;

  // if gcd(x, y) = 1, gcd(x, y, ..., z) = 1;
  // if x = 1, gcd(x, y, ..., z) = 1
  // gcd(x, y, ... , z) == 1 -> at least one element doesnt share a prime

  ll ans = 0;
  int mx = *max_element(all(A));

  for(int i=mx; i>0; i--) {
    int c = 0;
    for(int j=i; j<=mx; j+=i) {
      c += cnt[j];
    }
    // mu(i) = 1 -> i has even number of prime factors;
    // mu(i) = -1 -> i has odd number of prime factors;
    //int mu = (sv.nums[i].mu + MOD) % MOD;
    ll cur = bin_pow(2, c) - 1;
    dbg() << im(i) im(mu[i]) im(cur);
    ans = (ans + mul(cur, MOD + mu[i])) % MOD;
  }
  cout << ans << en;
}
