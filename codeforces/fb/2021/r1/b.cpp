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
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/
void solve() {
  int n;
  cin >> n;

  char G[n][n];
  bool double_count[n] = {};
  FOR(n) {
    FOR(j, n) { cin >> G[i][j]; }
  }

  int cnt = 0;

  ar<int, 2> ans = {n + 1, -1};

  FOR(n) {  // row
    bool ok = 1;
    cnt = 0;
    int last = 0;
    FOR(j, n) {
      char c = G[i][j];
      if (c == 'O') {
        ok = 0;
        break;
      }
      if (c == '.') {
        cnt++;
        last = j;
      }
    }
    if (!ok) continue;
    if (cnt < ans[0]) {
      ans[0] = cnt;
      ans[1] = 1;
    } else if (cnt == ans[0])
      ans[1]++;

    if (cnt == 1) {
      double_count[last] = 1;
    }
  }

  FOR(n) {
    if (double_count[i]) continue;
    bool ok = 1;
    cnt = 0;
    FOR(j, n) {
      char c = G[j][i];
      if (c == 'O') {
        ok = 0;
        break;
      }
      if (c == '.') cnt++;
    }
    if (!ok) continue;
    if (cnt < ans[0]) {
      ans[0] = cnt;
      ans[1] = 1;
    } else if (cnt == ans[0])
      ans[1]++;
  }

  if (ans[1] == -1)
    cout << "Impossible";
  else
    cout << ans[0] << " " << ans[1];
}

int main() {
  fast;
  freopen("xs_and_os_input.txt", "r", stdin);
  freopen("xs_and_os_output.txt", "w", stdout);
  int t;
  cin >> t;
  FOR(t) {
    cout << "Case #" << i + 1 << ": ";
    solve();
    cout << en;
  }
}
