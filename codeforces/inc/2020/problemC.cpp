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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y <<
// ")"; return dd; }

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

const int N = 1e5 + 5, K = 13;

template <typename T>
struct Node {
  T sm, lz;
};

ll n, q, x, A[N];
template <typename T>
struct SegTree {
  Node<T> tree[4 * N];
  SegTree() { memset(tree, 0, sizeof(tree)); }

  void build(int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].sm = A[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tree[i].sm = tree[2 * i].sm + tree[2 * i + 1].sm;
  }

  void upd(int idx, T x, int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].sm = x;
      return;
    }
    int m = (l + r) / 2;
    if (idx <= m)
      upd(idx, x, i * 2, l, m);
    else
      upd(idx, x, i * 2 + 1, m + 1, r);
    tree[i].sm = tree[i * 2].sm + tree[i * 2 + 1].sm;
  }

  T qry(int a, int b, int i = 1, int l = 1, int r = n) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[i].sm;
    int m = (l + r) / 2;
    return qry(a, b, i * 2, l, m) + qry(a, b, i * 2 + 1, m + 1, r);
  }
};
SegTree<ll> seg[K];  // seg[subsequence length]

ll dp[K];

int main() {
  fast;
  int k;
  cin >> n >> k, k++;
  FOR(i, 1, n + 1) cin >> A[i];

  //   FOR(k + 1) seg[i].build();
  // dont need to build it

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[1] = 1;
    for (int j = 2; j <= k; j++) {
      dp[j] = 0;
      dp[j] = seg[j - 1].qry(1, A[i] - 1);  // count elements less than A[i]
    }
    for (int j = 1; j < k; j++) seg[j].upd(A[i], dp[j]);
    // for (int j = 1; j < i; j++)
    //   for (int l = 2; l <= k; l++)
    //     if (A[i] > A[j]) dp[i][l] += dp[j][l - 1];
    ans += dp[k];
  }
  cout << ans;
}