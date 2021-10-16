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

template <typename T>
struct Node {
  T sm, lz;
};

int n, q, x;
template <typename T>
struct SegTree {
  Node<T> tree[4 * N];
  SegTree() { memset(tree, 0, sizeof(tree)); }

  void app(int i, T x, int l, int r) {
    tree[i].sm += (r - l + 1) * x;
    tree[i].lz += x;
  }

  void psh(int i, int l, int m, int r) {
    if (tree[i].lz) {
      app(2 * i, tree[i].lz, l, m);
      app(2 * i + 1, tree[i].lz, m + 1, r);
      tree[i].lz = 0;
    }
  }

  void upd(int idx, T x, int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].sm = x;
      return;
    }
    int m = (l + r) / 2;
    psh(i, l, m, r);
    if (idx <= m)
      upd(idx, x, i * 2, l, m);
    else
      upd(idx, x, i * 2 + 1, m + 1, r);
    tree[i].sm = tree[i * 2].sm + tree[i * 2 + 1].sm;
  }

  void upd2(int a, int b, T x, int i = 1, int l = 1, int r = n) {
    if (a <= l && r <= b) {
      app(i, x, l, r);
      return;
    }
    int m = (l + r) / 2;
    psh(i, l, m, r);
    if (a <= m) upd2(a, b, x, 2 * i, l, m);
    if (m < b) upd2(a, b, x, 2 * i + 1, m + 1, r);
    tree[i].sm = tree[2 * i].sm + tree[2 * i + 1].sm;
  }

  T qry(int a, int b, int i = 1, int l = 1, int r = n) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[i].sm;
    int m = (l + r) / 2;
    psh(i, l, m, r);
    return qry(a, b, i * 2, l, m) + qry(a, b, i * 2 + 1, m + 1, r);
  }
};
SegTree<ll> seg;

int main() {
  cin >> n >> q;
  FOR(i, 1, n + 1) {
    cin >> x;
    seg.upd(i, x);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      seg.upd2(a, b, u);
    } else {
      int k;
      cin >> k;
      cout << seg.qry(k, k) << en;
    }
  }
}