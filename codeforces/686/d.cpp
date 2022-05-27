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
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
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
 *
 * given n
 * find A
 * where
 * prod(A) = n
 * A_1 > 1
 * A_i+1 % A_i == 0
 * len(A) is max
*/

ll n;

void solve() {
  cin >> n;

  vector<ar<ll, 2>> primeFact;
  for(ll i=2; i*i<=n; i++) {
    if(n % i) continue;
    int cnt = 0;
    while(n % i == 0) {
      cnt++;
      n /= i;
    }
    primeFact.pb({cnt, i});
  }

  if(n > 1)
    primeFact.pb({1, n});

  // 360 -> 2^3 * 3^2 * 5
  // notice A doesnt have to be sorted, just A_i+1 % A[i] == 0
  // multiply A[0] to all other A
  // cnt[A[0]]-= cntOther;
  // 180
  // 5^1 * 3^2 * 2^2
  // 2*5 * 2*3*3
  // 2*3*5 * 2*3
  // 30 * 6
  
  sort(all(primeFact));

  debug() << im(primeFact);
  int mxCnt = primeFact.back()[0];

  vll ans(mxCnt, 1);

  for(auto [cnt, x]: primeFact) {
    for(int i=0; i<cnt; i++) {
      ans[mxCnt - i - 1] *= x;
    }
  }


  cout << mxCnt << en;
  EACH(x, ans) cout << x << " ";
  cout << en;
}

int main() {
  fast;
  int t; cin >> t;
  while(t--) solve();
}
