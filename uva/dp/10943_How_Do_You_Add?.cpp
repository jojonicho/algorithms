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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

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

Larry is very bad at math — he usually uses a calculator, which
worked well throughout college. Unforunately, he is now struck in
a deserted island with his good buddy Ryan after a snowboarding
accident.
They’re now trying to spend some time figuring out some good
problems, and Ryan will eat Larry if he cannot answer, so his fate
is up to you!
It’s a very simple problem — given a number N, how many ways
can K numbers less than N add up to N?
For example, for N = 20 and K = 2, there are 21 ways:
0+20
1+19
2+18
3+17
4+16
5+15
...
18+2
19+1
20+0

approach 1.
solution is stars and bars,

x1 + x2 + ⋯ + xk = n

how many ways to put n to k boxes?
n + k - 1 C k - 1

approach 2.
solution is dynamic programming

dp[n][k]
transition is i=[0, n], add go(n-i, k-1) to answer
why? just like knapsack dp
*/

const int N = 100, K = 100, M = 1e6;
int dp[N + 5][K + 5];
int go(int n, int k) {
  if (k == 1) return 1;
  if (dp[n][k] != -1) return dp[n][k];
  int cur = 0;
  for (int i = n; ~i; i--) cur = (cur + go(n - i, k - 1)) % M;
  return dp[n][k] = cur;
}

int main() {
  fast;
  memset(dp, -1, sizeof(dp));

  while (1) {
    int n, k;
    cin >> n >> k;
    if (!n && !k) {
      break;
    }
    cout << go(n, k) << en;
  }
  return 0;
}
