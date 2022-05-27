#include <bits/stdc++.h>
using namespace std;

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

#define pb push_back
#define en '\n'
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;

const int N = 5e3+5, M = 5e3+5;
const int INF = 1e9 + 5;

//bool vis[N];
pair<int,vi> dp[N];
vector<array<ll, 2>> G[N];

int n, m;
ll t, c;
int u, v;

pair<ll, vi> dfs(int u, ll t) {
  auto [cst, ans] = dp[u];
  //debug() << im(u) im(cst) im(ans);
  if(t >= cst) return {cst, ans};
  //if(vis[u]) return vi(); 
  //vis[u] = 1;
  if(t < 0) return {INF, vi()};

  int mx = 0;
  int curCst = 0;

  for(auto [v, c]: G[u]) {
    auto [bob,cur] = dfs(v, t-c);
    if((int)cur.size() > mx) {
      mx = cur.size();
      ans = cur;
      cst = bob;
      curCst = c;
    }
  }
  //debug() << im(u) im(t) im(mx);
  if(ans.empty()) {
    if(u == n-1) {
      ans.pb(u);
      cst = 0;
    } else cst = INF;
  } else {
    ans.pb(u);
  }
  return dp[u] = {cst + curCst, ans};
}

int main() {
  cin >> n >> m >> t;
  for(int i=0; i<n; i++) dp[i] = {INF, vi()};
  for(int i=0; i<m; i++) {
    cin >> u >> v >> c, u--, v--;
    G[u].pb({v, c});
    //G[v].pb({u, c});
  }

  //cout << dfs(0, t);
  auto [cst, ans] = dfs(0, t);
  //debug() << im(cst);
  cout << (int) ans.size() << en;
  reverse(all(ans));
  for(auto x: ans) cout << x + 1 << " ";
}
