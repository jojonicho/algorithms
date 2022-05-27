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

const int INF = 1e9 + 5;

void solve() {
  string s, t;
  cin >> s;

  int k;
  cin >> k;

  vi G[26];
  vector<char> endpoints;

  set<char> st;
  for (char c : s) st.insert(c);
  if ((int)st.size() == 1) {
    cout << 0;
    return;
  }

  FOR(k) {
    cin >> t;
    int u = t[0] - 'A', v = t[1] - 'A';
    G[u].pb(v);
    endpoints.pb(t[1]);  // possible endpoint
  }

  int ans = INF;
  for (char endpoint : endpoints) {
    bool ok = 1;
    int curAns = 0;
    for (char c : s) {
      vi dist(26, INF);
      queue<int> q;
      q.push(c - 'A');
      dist[c - 'A'] = 0;

      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
          int newDist = dist[u] + 1;
          if (newDist < dist[v]) {
            dist[v] = newDist;
            q.push(v);
          }
        }
      }

      if (dist[endpoint - 'A'] == INF) {
        ok = 0;
        break;
      }
      curAns += dist[endpoint - 'A'];
    }

    if (ok) ans = min(ans, curAns);
  }
  if (ans == INF) ans = -1;
  cout << ans;
}

int main() {
  fast;
  freopen("consistency_chapter_2_input.txt", "r", stdin);
  freopen("consistency_chapter_2_output.txt", "w", stdout);
  int t;
  cin >> t;
  FOR(t) {
    cout << "Case #" << i + 1 << ": ";
    solve();
    cout << en;
  }
}
