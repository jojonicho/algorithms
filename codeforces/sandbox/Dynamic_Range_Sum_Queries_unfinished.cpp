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

#include <cassert>

template <typename T, typename AssociativeOperation>
struct segment_tree {
  int SZ;
  T identity;
  AssociativeOperation TT;
  std::vector<T> data;

  segment_tree() {}

  segment_tree(int _SZ, T _identity, AssociativeOperation _TT)
      : SZ(_SZ), identity(_identity), TT(_TT) {
    data.resize(2 * SZ, identity);
  }

  // Returns the value at index i
  const T &operator[](int i) const {
    assert(0 <= i && i < SZ);
    return data[SZ + i];
  }

  // Assigns fn(i) at index i for each i in [0, SZ)
  template <typename Function>
  void assign(Function fn) {
    for (int i = 0; i < SZ; i++) data[SZ + i] = fn(i);
    for (int i = SZ - 1; i; i--) data[i] = TT(data[2 * i], data[2 * i + 1]);
  }

  // Assigns v at index i
  void assign(int i, T v) {
    assert(0 <= i && i < SZ);
    data[i += SZ] = v;
    for (i /= 2; i; i /= 2) data[i] = TT(data[2 * i], data[2 * i + 1]);
  }

  // Returns the result of a left fold of the elements at indices in [first,
  // last) over TT
  T accumulate(int first, int last) const {
    assert(0 <= first && last <= SZ);
    T left = identity, right = identity;
    for (first += SZ, last += SZ; first < last; first /= 2, last /= 2) {
      if (first & 1) left = TT(left, data[first++]);
      if (last & 1) right = TT(data[--last], right);
    }
    return TT(left, right);
  }
};

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

int main() {
  fast;
  int n, q;
  cin >> n >> q;

  vi A(n);
  FOR(n) { cin >> A[i]; }

  auto f = L2(u, v, min(u, v));  // idempotent function
  //   sparse_table<int, decltype(f)> st(n, f, L1(u, A[u % n]));
  segment_tree<int64_t, plus<int64_t>> st(n, 0, plus<int64_t>());

  FOR(q) {
    int x, l, r;
    cin >> x >> l >> r;
    x--;
    if (x)
      cout << st.accumulate(l - 1, r) << en;
    else {
      A[l - 1] = r;
      st.assign(l - 1, r);
    }
  }
}