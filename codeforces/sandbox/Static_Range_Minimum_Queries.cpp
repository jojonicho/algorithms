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
#include <vector>

template <typename T, typename IdempotentBinaryOperation =
                          const T &(*)(const T &, const T &)>
struct sparse_table {
  int SZ;
  IdempotentBinaryOperation TT;
  std::vector<std::vector<T>> data;

  sparse_table() {}

  sparse_table(IdempotentBinaryOperation _TT) : TT(_TT) {}

  template <typename Function>
  sparse_table(int _SZ, IdempotentBinaryOperation _TT, Function fn) : TT(_TT) {
    construct(_SZ, fn);
  }

  template <typename Function>
  void construct(int _SZ, Function fn) {
    SZ = _SZ;

    const int L = 32 - __builtin_clz(std::max(SZ - 1, 1));
    data.assign(L, std::vector<T>(SZ));

    for (int i = 0; i < SZ; i++) data[0][i] = fn(i);

    for (int l = 0; l + 1 < L; l++)
      for (int i = 0; i + (2 << l) <= SZ; i++)
        data[l + 1][i] = TT(data[l][i], data[l][i + (1 << l)]);
  }

  // Accumulates the elements at indices in [i, j) in O(1)
  T accumulate(int first, int last) const {
    assert(0 <= first && first < last && last <= SZ);
    int l = last - first > 1 ? 31 - __builtin_clz(last - first - 1) : 0;
    return TT(data[l][first], data[l][last - (1 << l)]);
  }
};

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

/*
1. move this down to solve function
2. use vector instead of array
*/
// initialize with 2 * N for wrap-around problems

int main() {
  fast;
  int n, q;
  cin >> n >> q;

  vi A(n);
  FOR(n) { cin >> A[i]; }
  auto f = L2(u, v, min(u, v));  // idempotent function
  sparse_table<int, decltype(f)> st(n, f, L1(u, A[u % n]));

  FOR(q) {
    int l, r;
    cin >> l >> r;
    cout << st.accumulate(l - 1, r) << en;
  }
}