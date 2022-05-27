#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

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

const long long M30 = ((long long)1 << 30) - 1;
const long long M31 = ((long long)1 << 31) - 1;
const long long MOD = ((long long)1 << 61) - 1;
long long BASE;
unsigned long long modulo(unsigned long long x) {
  unsigned long long xu = x >> 61;
  unsigned long long xd = x & MOD;
  unsigned long long res = xu + xd;
  if (res >= MOD) {
    res -= MOD;
  }
  return res;
}
unsigned long long mul(unsigned long long a, unsigned long long b) {
  unsigned long long au = a >> 31;
  unsigned long long ad = a & M31;
  unsigned long long bu = b >> 31;
  unsigned long long bd = b & M31;
  unsigned long long mid = au * bd + ad * bu;
  unsigned long long midu = mid >> 30;
  unsigned long long midd = mid & M30;
  return modulo(au * bu * 2 + midu + (midd << 31) + ad * bd);
}
struct rolling_hash {
  vector<long long> S;
  vector<long long> POW;

  rolling_hash(string s) {
    int n = s.size();
    S = vector<long long>(n + 1);
    for (int i = 1; i <= n; i++) {
      S[i] = modulo(mul(S[i - 1], BASE) + s[i - 1] - 'a');
    }
    POW = vector<long long>(n + 1);
    POW[0] = 1;
    for (int i = 1; i <= n; i++) {
      POW[i] = mul(POW[i - 1], BASE);
    }
  }

  long long hs(int L, int R) {
    return modulo(S[R + 1] - mul(S[L], POW[R + 1 - L]) + MOD);
  }
};
// move to main
// endmove

const int N = 1e6 + 5;

string s;
int n;
int main() {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  BASE = mt() % 10000000 + 10000000;

  fast;
  cin >> s;
  n = sz(s);

  rolling_hash R(s);

  for (int i = 0; i < n - 1; i++) {
    if (R.hs(0, i) == R.hs(n - i - 1, n - 1)) {
      cout << i + 1 << " ";
    }
  }
  cout << en;
}