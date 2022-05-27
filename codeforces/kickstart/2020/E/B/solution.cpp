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

int n, a, b, c; // <= 100
void solve() {
  cin >> n >> a >> b >> c;
  /*
   * 4 1 3 1, A = 1, B = 3, C = 1
   *
   * A 4 1 3 2 S
   */

  // A=3 B=3 C=2
  // 2 1 5 5 3
  // ^   ^ ^   A = 3
  //     ^ ^ ^ B = 3
  //     ^ ^   C = 2


  // 1 2 3 2 1 -> A = 3 B = 3 C = 1
  // 1 3 3 2 1 -> A = 3 B = 4 C = 2
  // 1 3 3 3 1 -> A = 4 B = 4 C = 3
  // 3 3 3 3 3 -> A = 5 B = 5 C = 5
  // A + B - C = N

  // 2 1 5 5 3 -> A = 3 B = 3 C = 2
  // A + B - C = 4 < N

  // A + B - C <= N

  bool isSingleBuild = c == 1 && a == 1 && b == 1; // 1 -> only possible for n = 1

  if(a + b - c > n || (n > 1 && isSingleBuild)) {
    cout << "IMPOSSIBLE" << en;
    return;
  }
  int m = a + b - c;
  a -= c;
  b -= c;

  // where to hide the 1 s
  bool left = 0, middle = 0, right = 0;
  if(c >= 2)
    middle = 1;
  else if(c > 0 && a > 0)
    left = 1;
  else
    right = 1;

  auto printHidden = [&]() {
    FOR(n-m)
      cout << n-2 << " ";
  };

  FOR(a)
    cout << n-1 << " ";

  if(left)
    printHidden();

  if(middle) {
    cout << n << " ";
    printHidden();
    cout << n << " ";
    c -= 2;
  }
  FOR(c)
    cout << n << " ";

  if(right)
    printHidden();
  FOR(b)
    cout << n-1 << " ";

  cout << en;
}


int main() {
  fast;
  int t; cin >> t;
  FOR(t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}

