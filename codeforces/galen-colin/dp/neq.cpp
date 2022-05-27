#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

const int N = 5e5;
mint fact[N + 5];
mint nCk(ll n, ll k) { return fact[n] / fact[k] / fact[n - k]; }
mint nPk(ll n, ll k) { return fact[n] / fact[n - k]; }

void pre() {
  fact[0] = fact[1] = 1;
  for (ll i = 2; i <= N; i++) {
    fact[i] = fact[i - 1] * i;
  }
}

int main() {
  pre();
  int n, m;
  cin >> n >> m;
  // conditions
  // A_i != A_j
  // A_i != B_i

  // number of pairs without any restrictions
  mint ans = 0;

  int sgn = 1;

  // derangements, IEP A_i = B_i
  for (int i = 0; i <= n; i++) {
    // fix i positions with A_i = B_i
    // n choose i slots, m permutate i elements
    mint fixed = nCk(n, i) * nPk(m, i);

    // rest n - i positions can be whatever, but use IEP to avoid overcounting
    mint not_fixed = nPk(m - i, n - i);
    not_fixed *= not_fixed;

    ans += fixed * not_fixed * (mint)sgn;
    sgn *= -1;
  }
  cout << ans;
}