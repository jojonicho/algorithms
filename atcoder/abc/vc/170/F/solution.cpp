#include <bits/stdc++.h>
using namespace std;

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
  cin.tie(NULL);

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
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, dbg &>::type operator<<( \
            c i) {
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
};

#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/*
if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

const int dir[5] = {0, 1, 0, -1, 0};

void solve() {
  int h, w, d;
  cin >> h >> w >> d;

  int x1, y1, x2, y2;
  cin >> x1 >> y1, x1--, y1--;
  cin >> x2 >> y2, x2--, y2--;

  int INF = w * h + 5;
  vt<vt<int>> G(h, vt<int>(w)), dist(h, vt<int>(w, INF));
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      char c; cin >> c;
      G[i][j] = (c == '.');
    }
  }

  queue<ar<int, 2>> q;
  q.push({x1, y1});
  dist[x1][y1] = 0;

  while(!q.empty()) {
    auto [i, j] = q.front(); q.pop();
    for(int k=0; k<4; k++) {
      int r = i + dir[k], c = j + dir[k+1];
      for(int l=0; l<d; l++) {
        if(r < 0 || c < 0 || r >= h || c >= w || G[r][c] == 0 || dist[i][j] + 1 > dist[r][c])
          break;

        if(dist[i][j] + 1 < dist[r][c]) {
          q.push({r, c});
          dist[r][c] = dist[i][j] + 1;
        }

        r += dir[k];
        c += dir[k+1];
      }
    }
  }

  int ans = dist[x2][y2];
  if(ans == INF)
    ans = -1;
  cout << ans << en;
}

int main() {
  fast;
  int t=1;
  //cin >> t;
  while(t--)
    solve();
}

