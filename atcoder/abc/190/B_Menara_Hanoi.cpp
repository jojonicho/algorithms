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
template <typename T>
struct fenwick {
  int N;
  vector<T> BIT;
  fenwick(int n) {
    N = 1;
    while (N < n) {
      N *= 2;
    }
    BIT = vector<T>(N + 1, 0);
  }
  void add(int i, T x) {
    i++;
    while (i <= N) {
      BIT[i] = max(BIT[i], x);
      i += i & -i;
    }
  }
  T sum(int i) {
    T ans = 0;
    i++;
    while (i > 0) {
      ans = max(ans, BIT[i]);
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R) { return (sum(R) - sum(L)); }
};

int main() {
  fast;
  int n;
  cin >> n;

  int A[n], B[n];
  FOR(n) {
    cin >> A[i];
    B[i] = A[i];
  }

  sort(B, B + n, greater<int>());
  int r = unique(B, B + n) - B;
  fenwick<int> fw(r);

  auto binary_search = [&](int lo, int hi, int target) {
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (B[mid] > target)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return lo;
  };

  int ans = 0;
  FOR(n) {
    int pos = binary_search(0, r - 1, A[i]);
    int x = fw.sum(pos - 1);
    fw.add(pos, x + 1);
    ans = max(ans, x + 1);
  }

  cout << ans << en;
}