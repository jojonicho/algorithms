#include <bits/stdc++.h>

#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py e.cpp

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

constexpr long long MOD = /**/ 998244353;  //*/ 998244353;

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

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/
const int K = 1e6 + 5;
mint dp[K][2][2];  // k, same row, same col

int n, m, k;
int a, b, c, d;

int main() {
  fast;
  cin >> n >> m >> k;
  cin >> a >> b >> c >> d, a--, b--, c--, d--;

  dp[0][a == c][b == d] = 1;

  for (int i = 1; i <= k; i++) {
    // same row
    dp[i][1][0] += dp[i - 1][0][0];
    dp[i][1][1] += dp[i - 1][0][1];
    // diff row
    dp[i][0][0] += dp[i - 1][0][0] * (n - 2) + dp[i - 1][1][0] * (n - 1);
    dp[i][0][1] += dp[i - 1][0][1] * (n - 2) + dp[i - 1][1][1] * (n - 1);
    // same col
    dp[i][0][1] += dp[i - 1][0][0];
    dp[i][1][1] += dp[i - 1][1][0];
    // diff col
    dp[i][0][0] += dp[i - 1][0][0] * (m - 2) + dp[i - 1][0][1] * (m - 1);
    dp[i][1][0] += dp[i - 1][1][0] * (m - 2) + dp[i - 1][1][1] * (m - 1);
  }

  // for (int i = 0; i < k; i++) {
  //   for (int j : {0, 1}) {    // sameRow
  //     for (int k : {0, 1}) {  // sameCol
  //       if (j)
  //         dp[i + 1][0][k] += dp[i][j][k] * (n - 1);
  //       else {
  //         dp[i + 1][0][k] += dp[i][j][k] * (n - 2);
  //         dp[i + 1][1][k] += dp[i][j][k];
  //       }

  //       if (k)
  //         dp[i + 1][j][0] += dp[i][j][k] * (m - 1);
  //       else {
  //         dp[i + 1][j][0] += dp[i][j][k] * (m - 2);
  //         dp[i + 1][j][1] += dp[i][j][k];
  //       }
  //     }
  //   }
  // }

  cout << dp[k][1][1];
}