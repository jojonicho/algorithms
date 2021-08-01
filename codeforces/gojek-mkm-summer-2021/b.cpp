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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
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
Input:

The first line is the number of test cases T. Each test case will have two
numbers N and M, each on their own line given in that order. Following that is N
lines of M lowercase letters each representing the grid of letters. Lastly, a
word W is given that you must look for.

Output:

For each test case, output one line of the form “Case C: X” (without the
quotes), where C is the case number (starting from 1), and X is how many times
the word W appeared in the grid.
*/

const int N = 100;

void solve() {
  int n, m;
  cin >> n >> m;
  string S[n];

  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  string t;
  cin >> t;
  int len = t.size();

  ll ans = 0;
  FOR(n) {
    FOR(j, m) {
      // right
      int k = 0;
      for (k = 0; j + k < m && k < len; k++) {
        if (S[i][j + k] != t[k]) break;
      }
      ans += k == len;
      // down
      for (k = 0; i + k < n && k < len; k++) {
        if (S[i + k][j] != t[k]) break;
      }
      ans += k == len;
      // right down
      for (k = 0; i + k < n && j + k < m && k < len; k++) {
        if (S[i + k][j + k] != t[k]) break;
      }
      ans += k == len;
      // right up
      for (k = 0; i - k >= 0 && j + k < m && k < len; k++) {
        if (S[i - k][j + k] != t[k]) break;
      }
      ans += k == len;

      // left
      for (k = 0; j - k >= 0 && k < len; k++) {
        if (S[i][j - k] != t[k]) break;
      }
      ans += k == len;
      // up
      for (k = 0; i - k >= 0 && k < len; k++) {
        if (S[i - k][j] != t[k]) break;
      }
      ans += k == len;
      // left up
      for (k = 0; i - k >= 0 && j - k >= 0 && k < len; k++) {
        if (S[i - k][j - k] != t[k]) break;
      }
      ans += k == len;
      // left down
      for (k = 0; i + k < n && j - k >= 0 && k < len; k++) {
        if (S[i + k][j - k] != t[k]) break;
      }
      ans += k == len;
    }
  }
  cout << ans << en;
}

int main() {
  fast;
  freopen("input.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ": ";
    solve();
  }
}