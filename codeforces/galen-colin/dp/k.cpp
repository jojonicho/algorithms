#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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

const int N = 2000, K = 2000;
vi factors[N + 5];

void pre() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j) continue;  // not a factor
      factors[i].push_back(j);
      if ((i / j) != j) factors[i].push_back(i / j);
    }
  }
}

mint dp[N + 1][K + 1];

int main() {
  pre();
  int n, k;
  cin >> n >> k;

  mint ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    for (int c = 1; c <= k; c++) {
      for (auto x : factors[i]) {
        // add i to it's factors
        dp[i][c] += dp[x][c - 1];
      }
    }
    ans += dp[i][k];
  }
  cout << ans;
}