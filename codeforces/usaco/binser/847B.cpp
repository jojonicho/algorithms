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
const int N = 2e5 + 5;
const int INF = 1e9 + 5;

int n, q, x, A[N];

template <typename T>
struct Node {
  T mx;
};

template <typename T>
struct SegTree {
  Node<ll> tree[4 * N];
  SegTree() { memset(tree, 0, sizeof(tree)); }

  void build(int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].mx = A[l];
      return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    tree[i].mx = max(tree[i * 2].mx, tree[i * 2 + 1].mx);
  }

  void upd(int a, T x, int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].mx = x;
      return;
    }
    int m = (l + r) / 2;
    if (a <= m)
      upd(a, x, i * 2, l, m);
    else
      upd(a, x, i * 2 + 1, m + 1, r);
    tree[i].mx = max(tree[i * 2].mx, tree[i * 2 + 1].mx);
  }

  T qry(int a, int b, int i = 1, int l = 1, int r = n) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[i].mx;
    int m = (l + r) / 2;
    return max(qry(a, b, i * 2, l, m), qry(a, b, i * 2 + 1, m + 1, r));
  }

  T bs(int target) {
    int lo = 1, hi = n;
    // because we qry from [1, mid], it is monotonically increasing
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (qry(1, mid) >= target)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    return lo;
  }
};
SegTree<ll> seg;

int prv[N];

int main() {
  fast;
  cin >> n;

  map<int, int> indexOf;
  for(int i=1; i<=n; i++) {
    cin >> A[i];
    indexOf[A[i]] = i;
  }

  seg.build();

  // find largest at every step
  int prv = INF, prvIdx = n+1;

  vvi ans;
  vi cur;
  while(1) {
    int x = seg.qry(1, prvIdx - 1);
    int idx = indexOf[x];
    if(x == -1 || idx < 1) {
      if(!cur.empty()) {
        reverse(all(cur));
        ans.pb(cur);
        cur.clear();
      }
      x = seg.qry(1, n);
      if(x == -1) break;
      idx = indexOf[x];
    }
    cur.pb(x);

    debug() << im(cur);
    seg.upd(idx, -1);
    prvIdx = idx;
  }

  EACH(cur, ans) {
    EACH(x, cur) cout << x << " ";
    cout << en;
  }
}
