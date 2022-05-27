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

const int N = 55;
const int dir[5] = {0, -1, 0, 1, 0};

int G[N][N];
bool vis[N][N];

int n, m;
char c;

void solve() {
  cin >> n >> m;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> c;
      int x = 0;
      if(c=='.') x = 0;
      if(c=='G') x = 1;
      if(c=='B') x = 2;
      if(c=='#') x = 3;
      G[i][j] = x;
      vis[i][j] = 0;
    }
  }

  bool ok = 1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(G[i][j] == 2) {
        for(int k=0; k<4; k++) {
          int r = i+dir[k], c = j+dir[k+1];
          if(r < 0 || c < 0 || r >= n || c >= m || G[r][c] == 2) continue;
          if(G[r][c] == 1) {
            ok = 0;
          }
          G[r][c] = 3;
        }
      } 
    }
  }

  if(!ok) {
    cout << "No" << en;
    return;
  }

  queue<pii> q;
  if(G[n-1][m-1] == 0)
    q.push({n-1, m-1});


  while(!q.empty()) {
    auto [i, j] = q.front(); q.pop();
    if(vis[i][j]) continue;
    vis[i][j] = 1;
    for(int k=0; k<4; k++) {
      int r = i+dir[k], c = j+dir[k+1];
      if(r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || G[r][c]==3) continue;
      q.push({r, c});
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(G[i][j] == 1 && !vis[i][j] || G[i][j] == 2 && vis[i][j]) ok = 0;
    }
  }

  cout << (ok ? "Yes" : "No") << en;
}

int main() {
  fast;
  int t; cin >> t;
  while(t--) solve();
}
