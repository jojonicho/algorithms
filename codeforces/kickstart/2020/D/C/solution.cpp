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

const int N = 5e5 + 5;
const int LOG = 17;

vi G[N];

int n;
int a, b;
int p;

// expected values -> number of success events / all events
// sum / n^2
// binary lifting -> nLogn

int mpA[N], mpB[N];
long double ans;

void dfs(int u, int d=0) {
  // because for each node, we want to propagate it to the root
  // compute first, then dfs;

  // a = 3
  // 1 d = 0
  // |
  // 1
  // |
  // 1 d = 2, cnt = 1
  // |
  // 1 d = 3, cnt = 2
  int remA = d%a, remB = d%b;

  int prevCntA = mpA[remA];
  int prevCntB = mpB[remB];

  mpA[remA]++;
  mpB[remB]++;

  //ans += 1. - (long double)ca * cb / n / n;

  for(auto v: G[u]) {
    dfs(v, d+1);
  }
  // if node u is beautiful, (all node until root with remVA == remUA || remVB == remUB as well)
  // then, count all pair (va, vb) where it is beautiful
  // contribution technique
  // if it's hard, count bad ones instead (because of overlapping count)
  // count all pair (va, vb) where it is not beautiful
  
  // find nodes that will make node u beautiful.
  int goodA = mpA[remA] - prevCntA;
  int goodB = mpB[remB] - prevCntB;
  // ans += goodA + goodB - (goodA ^ goodB)
  int badA = n - goodA;
  int badB = n - goodB;

  //dbg() << im(u) im(badA) im(badB);
  //dbg() << im(goodA) im(goodB);
  //dbg() << im(mpA[remA]) im(na);
  //dbg() << im(mpB[remB]) im(nb);


  // number of pairs which doesn't make node u beautiful
  long double bad = (long double) badA * badB / n / n; // n^2 events (choose n nodes for A, choose n nodes for B)
  ans += 1. - bad;
}


void solve() {
  cin >> n >> a >> b;
  ans=0;
  FOR(n) {
    G[i].clear();
    mpA[i]=0;
    mpB[i]=0;
  }

  for(int i=1; i<n; i++) {
    cin >> p, p--;
    G[p].pb(i);
  }

  dfs(0);
  cout << fixed << setprecision(12);
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

