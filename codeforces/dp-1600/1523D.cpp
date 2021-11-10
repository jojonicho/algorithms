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

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/
typedef bitset<15> bs;
int n, m, p;  // nPeople, nCurrencies, p <= 15
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vll A;
int dp[1 << 15];

ll solve(int idx) {
  ll person = A[idx];  // compress to A[idx]'s liking (p <= 15)

  vi bitIdx;
  FOR(m) if ((person >> i) & 1) bitIdx.pb(i);

  int nBits = bitIdx.size();
  int MASK = (1 << nBits);

  FOR(n) {
    ll curPerson = A[i];
    int cur = 0;
    FOR(j, nBits) {
      if ((curPerson >> bitIdx[j]) & 1) cur |= (1 << j);  // bit compression
    }
    dp[cur]++;
  }

  FOR(nBits) {
    FOR(mask, MASK) {
      if (!((mask >> i) & 1)) dp[mask] += dp[mask ^ (1 << i)];
    }
  }

  int thresh = (n + 1) / 2;
  int ansCompressed = 0;
  FOR(mask, MASK) {
    if (dp[mask] >= thresh &&
        __builtin_popcount(mask) > __builtin_popcount(ansCompressed)) {
      ansCompressed = mask;
    }
  }

  memset(dp, 0, sizeof(dp));
  // uncompress
  ll ans = 0;
  FOR(nBits) {
    if ((ansCompressed >> i) & 1) ans |= (1ll << bitIdx[i]);  // bit compression
  }
  return ans;
}

int main() {
  fast;
  cin >> n >> m >> p;
  A.resize(n, 0);

  FOR(n) {
    FOR(j, m) {
      char c;
      cin >> c;
      if (c == '1') A[i] |= (1ll << j);
    }
  }
  shuffle(all(A), rng);

  ll ans = 0;
  FOR(min(30, n)) {  // error of 2^-30
    ll cur = solve(i);
    if (__builtin_popcountll(cur) > __builtin_popcountll(ans)) ans = cur;
  }

  FOR(m) { cout << ((ans >> i) & 1); }
}