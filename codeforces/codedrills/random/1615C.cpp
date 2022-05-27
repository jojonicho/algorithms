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

const int INF = 2e5 + 5;

int n;
string s,t;

void solve() {
  cin >> n;
  cin >> s;
  cin >> t;

  if(s == t) {
    cout << 0 << en;
    return;
  }

  int nOnes = 0;
  int targetOnes = 0;
  for(int i=0; i<n; i++) {
    if(s[i] == '1') nOnes++;
    if(t[i] == '1') targetOnes++;
  }
  int nZeros = n - nOnes;
  int targetZeros = n - targetZeros;

  // 1 operation -> nOnes = nZeros + 1;

  // XOR everything except 1 lit candle
  //
  // 01 -> 11
  // 11
  //
  // 100010111
  // 101101100
  // ---------
  // 100010111 -- notice we swapped this 1 at index 7
  //       ^
  // 011101100
  //  ^
  // 110010011 -- to the originally 0 at index 2
  // ^
  // 101101100

  int ans = INF;

  if(nOnes == targetOnes) {
    int cnt = 0;
    for(int i=0; i<n; i++) {
      //if(s[i] != t[i]) cnt++;
      if(s[i] == '1' && t[i] == '0') cnt+=2; // swapping costs two operations
    }
    ans = min(ans, cnt); // move all i, where s[i] == 1 && t[i] != 1
  }

  if(nZeros + 1 == targetOnes) {
    // after reverse, nOnes = nZeros + 1
    // reversed except one

    int cnt = 1; // flip
    for(int i=0; i<n; i++) {
      // zeros become one now
      if(s[i] == '0' && t[i] == '0') cnt+=2;
    }

    ans = min(ans, cnt);
  }

  if(ans == INF) ans = -1;
  cout << ans << en;
}

int main() {
  fast;
  int t;
  cin >> t;
  while(t--) solve();
}
