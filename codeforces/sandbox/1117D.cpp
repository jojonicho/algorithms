#include <bits/stdc++.h>
using namespace std;
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

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

const int MOD = 1e9 + 7;
namespace modOp {
int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
int mul(int a, int b, int mod = MOD) { return (ll)a * b % mod; }

int AD(int &a, int b, int mod = MOD) { return a = ad(a, b, mod); }
int SUB(int &a, int b, int mod = MOD) { return a = sub(a, b, mod); }
int MUL(int &a, int b, int mod = MOD) { return a = mul(a, b, mod); }

int po(int b, int p, int mod = MOD) {
  return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod);
}
int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

int invGeneral(int a, int b) {  // 0 < a < b, gcd(a,b) = 1
  if (a == 0) return b == 1 ? 0 : -1;
  int x = invGeneral(b % a, a);
  return x == -1 ? -1 : ((1 - (ll)b * x) / a + b) % b;
}
}

using namespace modOp;

template <class T>
struct Mat {
  T **d;
  int a, b;

  Mat() { a = b = 0; }

  Mat(int _a, int _b) {
    a = _a, b = _b;
    d = new T *[a];
    FOR(i, a) {
      d[i] = new T[b];
      FOR(j, b) d[i][j] = 0;
    }
  }

  Mat(const vector<vector<T>> &v) : Mat(sz(v), sz(v[0])) {
    FOR(i, a) FOR(j, b) d[i][j] = v[i][j];
  }

  vector<vector<T>> toVec() {
    auto ret = vector<vector<T>>(a, vector<T>(b));
    FOR(i, a) FOR(j, b) ret[i][j] = d[i][j];
    return ret;
  }

  Mat operator+(const Mat &m) {
    Mat r(a, b);
    FOR(i, a) FOR(j, b) r.d[i][j] = ad(d[i][j], m.d[i][j]);
    return r;
  }

  Mat operator*(const Mat &m) {
    Mat r(a, m.b);
    FOR(i, a) FOR(j, b) FOR(k, m.b) AD(r.d[i][k], mul(d[i][j], m.d[j][k]));
    return r;
  }

  Mat operator^(ll p) {
    Mat r(a, a), base(*this);
    FOR(i, a) r.d[i][i] = 1;

    for (; p; p /= 2) {
      if (p & 1) r = r * base;
      base = base * base;
    }

    return r;
  }
};

int main() {
  fast;
  ll n, m;
  cin >> n >> m;
  // take 1 or m
  // answer(n-1) + answer(n-m)
  if (n - m < 0) {
    cout << "1\n";
    return 0;
  }
  Mat<int> A(m, m);

  A.d[0][0] = 1;
  A.d[0][m - 1] = 1;
  for (int i = 1; i < m; i++) {
    A.d[i][i - 1] = 1;
  }

  A = A ^ n;
  cout << A.d[0][0] << en;
}