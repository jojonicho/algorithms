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

typedef pair<int, vt<int>> State;

void solve() {
  int n;
  cin >> n;

  vt<vt<int>> A(n);
  vt<int> C(n);

  for(int i=0; i<n; i++) {
    int m;
    cin >> m;
    C[i] = m;
    A[i] = vt<int>(m);
    for(int j=0; j<m; j++)
      cin >> A[i][j]; // given in sorted order, so no need to sort again
  }

  //dbg() << im(A);
  int m;
  cin >> m;

  set<vt<int>> banned; // banned
  for(int i=0; i<m; i++) {
    vt<int> v(n);
    for(int j=0; j<n; j++)
      cin >> v[j], v[j]--;
    banned.insert(v);
  }

  int s = 0;
  vt<int> v(n);
  for(int i=0; i<n; i++) {
    int sz = C[i];
    s += A[i][C[i]-1];
    v[i] = sz-1;
  }

  priority_queue<State> pq;
  set<vt<int>> vis;
  pq.push({s, v});
  vis.insert(v);

  while(!pq.empty()) {
    auto [s, v] = pq.top(); pq.pop();

    if(!banned.count(v)) {
      //dbg() << im(v);
      for(auto x: v)
        cout << x+1 << " ";
      cout << en;
      return;
    }

    // take second largest for every build
    for(int i=0; i<n; i++) {
      if(v[i] == 0)
        continue;
      vt<int> w = v;
      w[i]--;
      if(vis.count(w))
        continue;

      int diff = A[i][v[i]] - A[i][v[i]-1];
      int t = s - diff;

      pq.push({t, w});
      vis.insert(w);
    }
  }
}

int main() {
  fast;
  int t=1;
  //cin >> t;
  while(t--)
    solve();
}

