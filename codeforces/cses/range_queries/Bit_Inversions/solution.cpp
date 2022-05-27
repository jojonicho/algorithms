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

template <typename T>
struct Node {
  T sum, pref, suff, ans;
  int len;

  Node operator +(Node b) {
    T newPref = (sum == len ? len + b.pref : pref);
    T newSuff = (b.sum == b.len ? b.len + suff : b.suff);
    T newAns = max({ans, b.ans, suff + b.pref});
    return {
      sum + b.sum,
      newPref,
      newSuff,
      newAns,
      len + b.len
    };
  }
};

const int N = 2e5 + 5;

int n, q, x, A[N];
template <typename T>
struct SegTree {
  Node<T> tree[4 * N];

  int t;

  SegTree(int x) {
    t = x;
  }

  void build(int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].sum = A[l] == t;
      tree[i].pref = A[l] == t;
      tree[i].suff = A[l] == t;
      tree[i].ans = A[l] == t;
      tree[i].len = 1;
      return;
    }
    int m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
    tree[i].len = r - l + 1;
  }

  void upd(int idx, T x, int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].sum = x == t;
      tree[i].pref = x == t;
      tree[i].suff = x == t;
      tree[i].ans = x == t;
      tree[i].len = 1;
      return;
    }
    int m = (l + r) / 2;
    if (idx <= m)
      upd(idx, x, i * 2, l, m);
    else
      upd(idx, x, i * 2 + 1, m + 1, r);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }

  Node<T> qry(int a, int b, int i = 1, int l = 1, int r = n) {
    if (b < l || a > r) return {0, 0, 0, 0, 0};
    if (a <= l && r <= b) return tree[i];
    int m = (l + r) / 2;
    return qry(a, b, i * 2, l, m) + qry(a, b, i * 2 + 1, m + 1, r);
  }
};
SegTree<int> seg0(0), seg1(1);

string s;
int main() {
  fast;
  cin >> s;
  n = sz(s);
  for(int i=1; i<=n; i++)
    A[i] = s[i-1] - '0';

  seg0.build();
  seg1.build();

  cin >> q;
  int u;
  while(q--) {
    cin >> u;
    A[u] ^= 1;
    seg0.upd(u, A[u]);
    seg1.upd(u, A[u]);
    auto q0 = seg0.qry(1, n);
    auto q1 = seg1.qry(1, n);
    cout << max(q0.ans, q1.ans) << " ";
  }
  cout << en;
}

