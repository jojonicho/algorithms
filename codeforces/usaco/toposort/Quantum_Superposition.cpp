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
const int N = 1005;

vi G1[N], G2[N];
int indeg1[N], indeg2[N];
set<int> dp1[N], dp2[N];
int dp[2*N];

int n1, n2, m1, m2;
int u, v;
int q;
int x;

int main() {
  fast;
  cin >> n1 >> n2 >> m1 >> m2;

  // DAG
  while(m1--) {
    cin >> u >> v, u--, v--;
    G1[u].pb(v);
    indeg1[v]++;
  }

  while(m2--) {
    cin >> u >> v, u--, v--;
    G2[u].pb(v);
    indeg2[v]++;
  }

  queue<int> q1, q2;
  for(int i=0; i<n1; i++)
    if(indeg1[i] == 0) q1.push(i);

  dp1[0].insert(0);
  dp2[0].insert(0);

  while(!q1.empty()) {
    u = q1.front(); q1.pop();
    debug() << im(u) im(dp1[u]);
    for(auto v: G1[u]) {
      for(auto x: dp1[u]) {
        dp1[v].insert(x+1);
      }
      if(--indeg1[v] == 0) q1.push(v);
    }
  }

  for(int i=0; i<n2; i++)
    if(indeg2[i] == 0) q2.push(i);

  while(!q2.empty()) {
    u = q2.front(); q2.pop();
    debug() << im(u) im(dp2[u]);
    for(auto v: G2[u]) {
      for(auto x: dp2[u]) {
        dp2[v].insert(x+1);
      }
      if(--indeg2[v] == 0) q2.push(v);
    }
  }

  //debug() << im(dp1[n1-1]) im(dp2[n2-1]);

  for(auto x: dp1[n1-1]) {
    for(auto y: dp2[n2-1]) {
      debug() << im(x) im(y);
      dp[x+y] = 1;
    }
  }
  
  cin >> q;
  while(q--) {
    cin >> x;
    cout << (x < 2*N && dp[x] ? "Yes" : "No") << en;
  }

}
