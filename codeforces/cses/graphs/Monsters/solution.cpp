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
dbg() << imie(k) imie(x) imie(row) imie(col);
*/

const int N = 1e3 + 5, INF = N * N;


const int dir[5] = {0, -1, 0, 1, 0};
const char c_dir[4] = {'L', 'U', 'R', 'D'};

char G[N][N];
int prv[N][N];

int n, m;

void bfs(vt<pii> V, vvi &dist, bool isHuman) {
  queue<pii> q;
  for(auto [i, j]: V) {
    q.push({i, j});
    dist[i][j] = 0;
  }

  while(!q.empty()) {
    auto [i, j] = q.front(); q.pop();
    for(int k=0; k<4; k++) {
      int r = i + dir[k];
      int c = j + dir[k+1];
      if(c < 0 || r < 0 || r >= n || c >= m || G[r][c] == '#' || dist[i][j] + 1 >= dist[r][c])
        continue;

      dist[r][c] = dist[i][j] + 1;
      if(isHuman) {
        prv[r][c] = k;
      }
      q.push({r, c});
    }
  }
}

int main() {
  fast;
  memset(prv, -1, sizeof(prv));
  cin >> n >> m;

  vt<pii> V;
  int r=-1, c=-1;
  FOR(n) { 
    FOR(j, m) {
      cin >> G[i][j];
      if(G[i][j] == 'M')
        V.pb({i, j});
      if(G[i][j] == 'A')
        r = i, c = j;
    }
  }


  vvi distM(n, vi(m, INF)), distA(n, vi(m, INF));

  bfs(V, distM, 0);
  bfs({{r,c}}, distA, 1);

  r = -1, c = -1;

  for(int i=0; i<n; i++) {
    if(distA[i][0] < distM[i][0])
      r = i, c = 0;
    if(distA[i][m-1] < distM[i][m-1])
      r = i, c = m-1;
  }

  for(int j=0; j<m; j++) {
    if(distA[0][j] < distM[0][j])
      r = 0, c = j;
    if(distA[n-1][j] < distM[n-1][j])
      r = n-1, c = j;
  }

  if(r == -1 || c == -1) {
    cout << "NO" << en;
    return 0;
  }

  string ans;
  dbg() << im(r) im(c);

  while(prv[r][c] != -1) {
    int k = prv[r][c];
    r = r - dir[k];
    c = c - dir[k+1];
    ans.pb(c_dir[k]);
  }
  reverse(all(ans));

  int len = sz(ans);

  cout << "YES" << en;
  cout << len << en;
  cout << ans << en;
}


