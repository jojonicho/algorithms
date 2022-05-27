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

template<typename T>
struct Fenwick {
  int n;
  vt<T> tree;
  Fenwick(int n) : tree(n+1, 0), n(n) {}

  void add(int i, T x) {
    i++;
    for(; i<=n; i+=i&-i)
      tree[i] += x;
  }
  T qry(int i) {
    i++;
    T res = 0;
    for(; i>0; i-=i&-i)
      res += tree[i];
    return res;
  }
  T qry(int i, int j) {
    return qry(j) - qry(i-1);
  }
};

int main() {
  fast;
  int n;
  cin >> n;

  vt<ar<int, 2>> A(n);
  vt<int> B(n);

  FOR(n)
    cin >> A[i][0];
  FOR(n) {
    cin >> A[i][1];
    B[i] = A[i][1];
  }

  sort(all(A));
  sort(all(B));
  // when you completely don't know how to do something
  // most likely you're missing an observation
  //
  // if X_i < X_j && V_i > V_j -> dist = 0
  // if X_i < X_j && V_i <= V_j -> dist keeps increasing, minimal distance is on t0

  Fenwick<ll> ft1(n), ft2(n); // sum of V, count
  vt<int> C(n); // coordinate compression
  FOR(n) {
    int v = A[i][1];
    int idx = lower_bound(all(B), v) - B.begin();
    C[i] = idx;
  }

  for(int i=0; i<n; i++) {
    auto [x, v] = A[i];
    int idx = C[i];
    ft1.add(idx, x);
    ft2.add(idx, 1);
  }

  ll ans = 0;
  for(int i=0; i<n; i++) {
    auto [x, v] = A[i];
    int idx = C[i];
    ft1.add(idx, -x);
    ft2.add(idx, -1);
    ll sum = ft1.qry(idx, n-1);
    ll cnt = ft2.qry(idx, n-1);
    ll cur = sum - cnt * x;
    ans += cur;
  }

  cout << ans << en;
}

