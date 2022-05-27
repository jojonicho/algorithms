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

const int N = 1e5 + 5, LOG = 17;

int A[N];
int dp[N][LOG];
vi G[N];

int n, q;
int s, k;


void solve() {
  int n, q;
  cin >> n >> q;

  FOR(n-1) cin >> A[i];

  vi prv(n, -1), nxt(n, -1);

  stack<int> st;
  // if we go left from i, how far will we go

  //  0  1  2  3
  //  90 30 40 60
  // 0  1  2  3  4
  st.push(0);
  for(int i=1; i<n-1; i++) {
    while(st.top() != 0 && A[st.top()-1] < A[i]) st.pop();
    prv[i] = st.top();
    st.push(i);
  }
  prv[n-1] = 0; // left and right edge go straight till the end
  prv[0] = 0;
  //dbg() << im(prv);

  st.pop();
  st.push(n-1);

  //  n = 5
  //  0  1  2  3
  //  90 30 40 60
  // 0  1  2  3  4
  for(int i=n-2; i>=1; i--) {
    while(st.top() != n-1 && A[i-1] > A[st.top()]) st.pop();
    nxt[i] = st.top();
    st.push(i);
  }
  nxt[0] = n-1;
  nxt[n-1] = n-1;
  //dbg() << im(nxt);

  vi dist(n);
  vi dir(n);
  FOR(n) {
    if(i==0 || i < n-1 && A[i] < A[i-1]) {
      dir[i] = 1;
      dist[i] = nxt[i] - i + 1;
    } else {
      dir[i] = 0;
      dist[i] = i - prv[i] + 1;
    }
  }

  auto binary_lift =[&]() {
    for(int u=0; u<n; u++) {
      dp[u][0] = (dir[u] ? nxt[u] : prv[u]);
    }
    for(int i=1; i < LOG; i++) { // value up to LOG-2
      for(int u=0; u<n; u++) {
        dp[u][i] = dp[ dp[u][i-1] ][i-1];
      }
    }
  };

  binary_lift();

  while(q--) {
    int u;
    cin >> u >> k, u--;
    for(int i=LOG-1; i>=0; i--) {
      int v = dp[u][i];
      if(dist[v] < k) u = v;
    }
    if(dist[u] < k)
      u = dp[u][0];

    int ans = -1;
    if(dir[u])
      ans = u + k - 1;
    else 
      ans = u - k + 1;
    cout << ans + 1 << " ";
  }
  cout << en;
}

int main() {
  fast;
  int t; cin >> t;
  FOR(t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}

