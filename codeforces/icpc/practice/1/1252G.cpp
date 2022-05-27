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

const int N = 1e5 + 5;
vi R[N];

template <typename T>
struct Node {
  T lz, mn;
};

int n, q, A[N];
template <typename T>
struct SegTree {
  Node<T> tree[4 * N];
  SegTree() { memset(tree, 0, sizeof(tree)); }

  void build(int i = 0, int l = 0, int r = n - 1) {
    if (l == r) {
      tree[i].mn = A[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i].mn = min(tree[2 * i + 1].mn, tree[2 * i + 2].mn);
  }

  void app(int i, T x, int l, int r) {
    tree[i].mn += x;
    tree[i].lz += x;
  }

  void psh(int i, int l, int m, int r) {
    if (tree[i].lz) {
      app(2 * i + 1, tree[i].lz, l, m);
      app(2 * i + 2, tree[i].lz, m + 1, r);
      tree[i].lz = 0;
    }
  }

  void upd(int idx, T x, int i = 0, int l = 0, int r = n - 1) {
    if (l == r) {
      tree[i].mn = x;
      return;
    }
    int m = (l + r) / 2;
    psh(i, l, m, r);
    if (idx <= m)
      upd(idx, x, i * 2 + 1, l, m);
    else
      upd(idx, x, i * 2 + 2, m + 1, r);
    tree[i].mn = min(tree[i * 2 + 1].mn, tree[i * 2 + 2].mn);
  }

  void upd2(int a, int b, T x, int i = 0, int l = 0, int r = n - 1) {
    if (b < l || a > r) return;
    if (a <= l && r <= b) {
      app(i, x, l, r);
      return;
    }
    int m = (l + r) / 2;
    psh(i, l, m, r);
    if (a <= m) upd2(a, b, x, 2 * i + 1, l, m);
    if (m < b) upd2(a, b, x, 2 * i + 2, m + 1, r);
    tree[i].mn = min(tree[2 * i + 1].mn, tree[2 * i + 2].mn);
  }

  T qry(int a, int b, int i = 0, int l = 0, int r = n - 1) {
    if (b < l || a > r) return LLONG_MAX;
    if (a <= l && r <= b) return tree[i].mn;
    int m = (l + r) / 2;
    psh(i, l, m, r);
    return min(qry(a, b, i * 2 + 1, l, m), qry(a, b, i * 2 + 2, m + 1, r));
  }
};
SegTree<int> seg;

int main() {
  fast;
  int nEmployees;
  cin >> nEmployees >> n >> q;  // n is years

  int RANDALL;
  cin >> RANDALL;

  int nWorse = 0;  // rank
  FOR(nEmployees - 1) {
    int x;
    cin >> x;
    if (x < RANDALL) nWorse++;
  }

  FOR(n) {  // 1 if for every m there is sz people worse than Randall
    int sz;
    cin >> sz;  // R_i, sum(R_i) <= 1e6
    R[i].resize(sz);

    nWorse -= sz;
    A[i] = nWorse;  // if (W[i] < 0) fired

    FOR(j, sz) {
      cin >> R[i][j];
      if (R[i][j] < RANDALL) nWorse++;
    }
  }

  seg.build();

  FOR(q) {
    int x, y, z;
    cin >> x >> y >> z, x--, y--;

    int &target = R[x][y];

    // debug() << imie(idx) imie(W[idx]) imie(target) imie(scores);

    // if B_xy && z < A[0] || B_xy && z > A[0] -> nothing changes
    // B_xy < A[0] && z > A[0] && W[i] == sz -> stay -> fired
    // B_xy > A[0] && z < A[0] && W[i] == sz -> fired -> stay
    if (target < RANDALL && z > RANDALL) {
      seg.upd2(x + 1, n - 1, -1);
      //   debug() << imie("-1") imie(seg.tree[0].mn);
    }
    if (target > RANDALL && z < RANDALL) {
      seg.upd2(x + 1, n - 1, 1);
      //   debug() << imie("+1") imie(seg.tree[0].mn);
    }
    target = z;
    cout << (seg.tree[0].mn >= 0) << en;
  }
}