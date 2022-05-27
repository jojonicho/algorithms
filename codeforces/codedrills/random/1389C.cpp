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

int is_substr(string s, string t) {
  int n = s.size(), m = t.size();
  int i=0, j = 0;
  int cost = 0;
  while(i < n) {
    while(j < m && s[i] != t[j]) {
      j++;
      cost++;
    }
    if(j == m) break;
    j++;
    i++;
  }
  if(i != n)
    return -1;
  return cost + m-j;
}

string s;
int n;
void solve() {
  cin >> s;
  n = s.size();

  // s[n-1] + s[0 : n-2]
  // =
  // s[1:n-1] + s[0]
  //
  // s[1] = s[n-1]
  // s[0] = s[n-2]
  //
  // s[2:n-1] = s[0:n-3]
  // s[2] = s[0]
  // s[n-1] = s[n-3]
  // s[3] = s[1]
  // s[n-2] = s[n-4]
  // s[4] = s[2]
  // s[5] = s[3]

  // s[odd] = s[odd]
  // s[even] = s[even]
  
  // n&1 -> n=3, s[1] = s[n-1] = s[2]
  // odd -> all same character

  //map<int, int> mp;
  //int mx = 0;
  //for(char c: s)
    //mx = max(mx, ++mp[c]);

  //if(n&1) {
    //cout << n - max(2, mx) << en;
    //return;
  //}

  // dp?
  // generate all pairs [0,9] and [0,9]
  
  int ans = 0;
  for(char c='0'; c<='9'; c++)
    for(char d='0'; d<='9'; d++) {
      //int cost = is_substr(t, s);
      //if(cost == -1) continue;
      //ans = min(cost, ans);

      bool same = c == d;
      int i=0;
      int len = 0;

      while(i < n) {
        while(i < n && s[i] != c)
          i++;
        if(i == n) break;
        i++;
        len++;

        while(i < n && s[i] != d)
          i++;
        if(i == n) break;
        i++;
        len++;
      }

      if(!same && len&1)
        len--;
      ans = max(ans, len);
    }

    cout << n - ans << en;
}

int main() {
  fast;
  int t; cin >> t;
  while(t--) solve();
}
