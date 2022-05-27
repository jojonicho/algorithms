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
const int N = 11;
const int dir[5] = {0, 1, 0, -1, 0};
int n, m;

int G[N][N]; // 0 -> empty, 1 -> pig, 2 -> wolf
bool vis[N][N];

char c;
int nAdjWolfs, nAdjPigs;

void dfs(int r, int c) {
  vis[r][c] = 1;
  bool isWolf = G[r][c] == 2;

  int curAdjPigs = 0;
  for(int k=0; k<4; k++) {
    int r2 = r + dir[k], c2 = c + dir[k+1];
    if(r2 < 0 || c2 < 0 || r2 >= n || c2 >= m || G[r2][c2] == 0) continue;
    if(isWolf && G[r2][c2] == 1) {
      curAdjPigs++;
      G[r2][c2] = 0;
    }
    if(vis[r2][c2]) continue;
    dfs(r2, c2);
  }
  nAdjPigs += curAdjPigs;
  if(curAdjPigs > 0) nAdjWolfs++;
}

int main() {
  fast;
  cin >> n >> m;

  nAdjWolfs = 0; nAdjPigs = 0;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
      cin >> c;
      int x = 0;
      if(c == 'P') x = 1;
      else if(c == 'W')  x = 2;
      G[i][j] = x;
    }

  int ans = 0;
  //// count number of pigs adjacent
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(vis[i][j] || G[i][j] == 0) continue;
      nAdjWolfs = 0; nAdjPigs = 0;
      dfs(i, j);
      ans += min(nAdjWolfs, nAdjPigs);
    }
  }

  cout << ans;
}
