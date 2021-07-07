#include <bits/stdc++.h>

// python $AC_LIBRARY_PATH/expander.py e.cpp

using namespace std;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
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

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

enum DIVISOR_TYPE { ALL, SQUARE_FREE };
template <int MAXV>
struct sieve {
  vi primes;
  struct num {
    int least_prime;       // least prime divisor
    int div_least_prime;   // num divided by least_prime
    char lp_multiplicity;  // multiplicity of the least prime divisor
    char mu;               // mobius function
    int phi;               // euler's totient function

    static num ONE() { return {INT_MAX, 1, 0, 1, 1}; }

    num prod(int my_value, int p) const {
      if (p < least_prime) return {p, my_value, 1, char(-mu), phi * (p - 1)};
      assert(p == least_prime);
      return {p, my_value, char(lp_multiplicity + 1), 0, phi * p};
    }
  };
  vector<num> nums;
  const num &operator[](int i) { return nums[i]; }

  sieve() : nums(MAXV) {
    nums[1] = num::ONE();
    for (int v = 2; v < MAXV; v++) {
      num &n = nums[v];
      if (!n.least_prime) {
        n = nums[1].prod(1, v);
        primes.pb(v);
      }
      for (int p : primes) {
        if (p > n.least_prime || v * p >= MAXV) break;
        nums[v * p] = n.prod(v, p);
      }
    }
  }

  bool is_prime(int v) const {
    assert(0 < v && v < MAXV);
    return nums[v].least_prime == v;
  }

  int eliminate_least_prime(int v) const {
    assert(1 < v && v < MAXV);
    for (int m = nums[v].lp_multiplicity; m > 0; m--)
      v = nums[v].div_least_prime;
    return v;
  }

  const vpii &factor(int v) const {
    assert(0 < v && v < MAXV);
    static vpii res;
    res.clear();
    for (; v > 1; v = eliminate_least_prime(v))
      res.emplace_back(nums[v].least_prime, nums[v].lp_multiplicity);
    reverse(all(res));
    return res;
  }

  template <typename F>
  void for_each_divisor_unordered(int v, F f, DIVISOR_TYPE t = ALL,
                                  int d = 1) const {
    assert(0 < v && v < MAXV);
    if (v == 1) {
      f(d);
      return;
    }
    int w = eliminate_least_prime(v);
    char M = min(nums[v].lp_multiplicity, char(t == ALL ? CHAR_MAX : 1));
    for (int m = 0; m <= M; m++, d *= nums[v].least_prime) {
      for_each_divisor_unordered(w, f, t, d);
    }
  }

  const vi &unordered_divisors(int v, DIVISOR_TYPE t = ALL) const {
    assert(0 < v && v < MAXV);
    static vi res;
    res.clear();
    for_each_divisor_unordered(
        v, [&](int d) { res.pb(d); }, t);
    return res;
  }
};

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);

where μ(x) is the Möbius function, which is multiplicative and satisfies
f(1) = 1, f(p) =  - 1, f(p^k) = 0 for any prime number p and any integer k ≥ 2.
(It is worth noting that you can pre-compute all values of the Möbius function
from 1 to n using the linear sieve. )

https://codeforces.com/blog/entry/53925
*/
constexpr long long MOD = /**/ 1e9 + 7;  //*/ 998244353;

template <int mod>
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }

  static constexpr int get_mod() { return mod; }
};
using mint = ModInt<MOD>;
using vm = vector<mint>;

const int N = 2e5 + 5;
sieve<N> sv;
int n, k;

/*
gcd(x,y) is a multiple of k
if and only if both x and y are multiples of k

The number of multiples of k between L and R (inclusive)
*/
int n_coprime(int d) { return k / d; }

int main() {
  fast;
  cin >> n >> k;

  mint ans = 0;
  vm cnt(k + 1);

  for (int i = 1; i <= k; i++) {
    cnt[i] = mint(n_coprime(i)).pow(n);
  }

  for (auto p : sv.primes) {
    // mobius, remove duplicates
    FOR(i, 1, n_coprime(p) + 1) cnt[i] -= cnt[i * p];
  }

  FOR(i, 1, k + 1) {
    // sum = count * i;
    ans += cnt[i] * i;
  }
  cout << ans;
}