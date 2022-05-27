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

const int N = 1e5 + 5;

int A[N];
vi G[N];
int mx[N]; // max value up until node u

int n;
ll ans;

bool vis[N];

void dfs(int u) {
  mx[u] = A[u];
  for(auto v: G[u]) {
    dfs(v);
    chmax(mx[u], mx[v]);
  }
}

int dfs2(int u) {
  if(vis[u]) return 0;
  vis[u] = 1;

  if(!G[u].empty()) {
    int mnV = G[u].front();
    int mn = mx[mnV];
    for(auto v: G[u]) {
      int cur = mx[v];
      if(cur < mn) {
        mn = cur;
        mnV = v;
      }
    }
    dfs2(mnV);
  }
  return mx[u];
}

struct cmp {
  bool operator()(int &x, int &y) {
    return mx[x] > mx[y];
  }
};

void solve() {
  cin >> n;
  n++;

  FOR(n) {
    vis[i]=0;
    mx[i]=0;
    G[i].clear();
  }

  FOR(i, 1, n) cin >> A[i];

  FOR(i, 1, n) {
    //cin >> nxt[i], nxt[i]--; // nxt
    //G[nxt[i]].
    int u; cin >> u;
    G[u].pb(i);
  }

  FOR(i, 1, n) {
    debug() << im(i) im(A[i]);
  }

  ans = 0;
  dfs(0);

  priority_queue<int, vi, cmp> q;
  for(auto v: G[0]) {
    q.push(v);
  }

  while(!q.empty()) {
    int u = q.top(); q.pop();
    int cur = dfs2(u);
    debug() << im(A[u]) im(mx[u]) im(cur);
    ans += cur;

    for(auto v: G[u]) {
      q.push(v);
    }
  }
  cout << ans << en;
}

int main() {
  fast;
  int t; cin >> t;
  FOR(t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}

