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
*/
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll dp[N], A[N];
ll pref[N];

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

ll bin_pow(ll x, ll p) {
  if(p == 0) return 1;
  if(p&1) return mul(x, bin_pow(x, p-1));
  return bin_pow(mul(x, x), p/2);
}

int n, p;
int main() {
  fast;
  cin >> n >> p;

  //for(int i=1; i<=n; i++) {
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }

  sort(A, A+n);
  set<int> st;
  for(int i=0; i<n; i++) {
    int x = A[i];
    // check if x can be made from previous numbers
    bool ok = 1;
    while(x) {
      if(st.find(x) != st.end()) {
        ok = 0;
        break;
      }
      if(x&1) x = (x-1) / 2; // 2x+1
      else if(x % 4 == 0) x /= 4;
      else break;
    }
    if(ok) st.insert(A[i]);
  }

  //debug() << im(st);

  dp[0] = 1;
  dp[1] = 1;

  for(int i=2; i<=p; i++) {
    dp[i] = add(dp[i-1], dp[i-2]);
    //debug() << im(i) im(dp[i]);
  }

  pref[0] = dp[0];
  for(int i=1; i<=p; i++) pref[i] = add(pref[i-1], dp[i]);

  ll ans = 0;
  for(auto x: st) {
    int nBits = 0;
    while(x) {
      x/=2;
      nBits++;
    }
    if(nBits > p) continue;
    //debug() << im(x) im(nBits) im(pref[p-nBits]);
    ans = add(ans, pref[p - nBits]); // fibo numbers from p to nBits
  }
  cout << ans;
}
