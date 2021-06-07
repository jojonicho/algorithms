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

const int M = 1e9 + 7;

int mul(const int v1, const int v2) { return (int)((1LL * v1 * v2) % M); }

int bin_pow(int a, int p) {
  int res = 1;
  while (p != 0) {
    if (p & 1) res = mul(res, a);
    p >>= 1;
    a = mul(a, a);
  }
  return res;
}

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

#define M2 1000000014000000049L

void add(ll &a, ll b) { a = (a + b) % M; }

ll sub(ll a, ll b) {
  a -= b;
  if (a < 0) a += M;
  return a;
}

void mult(vector<vll> &a, vector<vll> &b) {
  vector<vll> c(a.size(), vll(b[0].size(), 0ll));
  for (int r = 0; r < a.size(); ++r) {
    for (int x = 0; x < b.size(); ++x) {
      for (int j = 0; j < b[0].size(); ++j) {
        c[r][j] += a[r][x] * b[x][j];
        if (c[r][j] >= M2) c[r][j] -= M2;
      }
    }
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      a[i][j] = c[i][j] % M;
    }
  }
}

void pow(vector<vll> &arr, ll n) {
  if (n <= 1) return;

  if (n & 1) {
    vector<vll> temp(arr.size(), vll(arr[0].size()));
    for (int i = 0; i < arr.size(); i++) {
      for (int j = 0; j < arr[0].size(); j++) {
        temp[i][j] = arr[i][j];
      }
    }
    pow(arr, n / 2ll);
    mult(arr, arr);
    mult(arr, temp);
  } else {
    pow(arr, n / 2ll);
    mult(arr, arr);
  }
}

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

  vector<vll> dp(m, vll(m));
  dp[0][0] = 1;
  dp[0][m - 1] = 1;
  for (int i = 1; i < m; i++) {
    dp[i][i - 1] = 1;
  }

  pow(dp, n);
  cout << dp[0][0] << en;
}