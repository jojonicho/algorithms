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
const int N = 2e5 + 5;
ll pref[N];
ll dp[N], L[N], R[N];

int n, q, x, A[N];

template <typename T>
struct Node {
  T mn;
};

template <typename T>
struct SegTree {
  Node<ll> tree[4 * N];
  SegTree() { memset(tree, 0, sizeof(tree)); }

  void build(int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].mn = A[l];
      return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    tree[i].mn = min(tree[i * 2].mn, tree[i * 2 + 1].mn);
  }

  void upd(int a, T x, int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].mn = x;
      return;
    }
    int m = (l + r) / 2;
    if (a <= m)
      upd(a, x, i * 2, l, m);
    else
      upd(a, x, i * 2 + 1, m + 1, r);
    tree[i].mn = min(tree[i * 2].mn, tree[i * 2 + 1].mn);
  }

  T qry(int a, int b, int i = 1, int l = 1, int r = n) {
    if (b < l || a > r) return INT_MAX;
    if (a <= l && r <= b) return tree[i].mn;
    int m = (l + r) / 2;
    return min(qry(a, b, i * 2, l, m), qry(a, b, i * 2 + 1, m + 1, r));
  }

  T bs(int x, int i = 1, int l = 1, int r = n) {
    if (l == r) return (tree[i].mn < x ? l : -1);  // we want the index
    int m = (l + r) / 2;
    if (tree[i * 2].mn < x) return bs(x, i * 2, l, m);
    if (tree[i * 2 + 1].mn < x) return bs(x, i * 2 + 1, m + 1, r);
    return -1;
  }
};
SegTree<ll> seg;

int main() {
  fast;
  memset(dp, 0x3f, sizeof(dp));
  cin >> n;

  FOR(i, 1, n + 1) {
    cin >> A[i];
    pref[i] = pref[i - 1] + A[i];
  }

  seg.build();

  FOR(i, 2, n + 1) { cin >> L[i] >> R[i]; }

  dp[1] = 0;
  dp[2] = pref[2];

  seg.upd(1, 0);
  seg.upd(2, dp[2] - pref[1]);

  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i], seg.qry(L[i], R[i]) + pref[i]);
    seg.upd(i, dp[i] - pref[i - 1]);
    // for (int j = L[i]; j <= R[i]; j++)
    //   dp[i] = min(dp[i], dp[j] + pref[i] - pref[j - 1]);
  }
  FOR(i, 1, n + 1) cout << dp[i] << " ";
}