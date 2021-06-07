#include <bits/stdc++.h>

#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py a.cpp

using namespace std;
using namespace atcoder;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

const int M = 1e9 + 7;

int mul(const int v1, const int v2) { return (int)((1LL * v1 * v2) % M); }

int mod_pow(int a, int p) {
  int res = 1;
  while (p != 0) {
    if (p & 1) res = mul(res, a);
    p >>= 1;
    a = mul(a, a);
  }
  return res;
}

const int N = 5e5;
ll iv[N + 1], fact[N + 1], ifact[N + 1];
ll nCk(int n, int k) { return fact[n] * ifact[k] % M * ifact[n - k] % M; }
ll nPk(int n, int k) { return fact[n] * ifact[n - k] % M; }

void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

  for (int i = 2; i <= N; i++) {
    iv[i] = M - M / i * iv[M % i] % M;
    fact[i] = fact[i - 1] * i % M;
    ifact[i] = ifact[i - 1] * iv[i] % M;
  }
}

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

ll n, k;
ll bnm2(ll x) {
  if (x <= 0) return 0;
  return (x * (x - 1)) / 2;
}

ll calc2(ll x) {
  return bnm2(x - 1) - 3 * bnm2(x - n - 1) + 3 * bnm2(x - 2 * n - 1) -
         bnm2(x - 3 * n - 1);
}

ll bnm1(ll x) {
  if (x <= 0) return 0;
  return x;
}

ll calc1(ll x) {
  return bnm1(x - 1) - 2 * bnm1(x - n - 1) + bnm1(x - 2 * n - 1);
}

int main() {
  cin >> n >> k;
  // (i, j, k) 1 <= i,j,k <= n
  ll sum;
  /**
   * first we find the sum corresponding to k
   * e.g (1,2,2) sum = 5 (-3) = 1
   * we do this in zero based (-3)
   *
   * stars and bars with n = i for i in [0, 3*(n-1)]
   * k = 3
   * (i+2 C 2) - 0 indexed OR (i-3 + 2 C 2) - 1 indexed
   * -3 comes from the least sum being 3 (1, 1, 1)
   */
  for (ll i = 3; i <= 3 * n; i++) {
    if (calc2(i) >= k) {
      sum = i;
      break;
    }
    k -= calc2(i);
  }
  debug() << imie(sum) imie(k);

  /**
   * now after we have the sum, time to find x from (x,y,z)
   *
   * for every fixed i, find out how many ways we can put
   * sum - i into 2 spots -> stars and bars
   * n = sum - i, k = 2
   *
   */
  ll x = 1;
  for (ll i = 1; i <= n; i++) {
    if (calc1(sum - i) >= k) {
      x = i;
      break;
    }
    k -= calc1(sum - i);
  }

  debug() << imie(n) imie(sum) imie(x) imie(k);

  ll y = k - 1 + max(1ll, sum - x - n);
  ll z = sum - x - y;
  cout << x << " " << y << " " << z << en;
}