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
sum of product of subsets with size k
*/
const int M = 1e9 + 7;
typedef bitset<5> bs;

int main() {
  fast;
  int n, k;
  cin >> n >> k;  // Subset size should be k

  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];

  for (int mask = 0; mask < (1 << n); mask++) {
    ll prod = 1;
    vll cur;
    FOR(n) {
      if ((mask >> i) & 1) {
        cur.pb(A[i]);
        prod *= A[i];
      }
    }
    if (cur.size() % 2 == 0 && cur.size() == k)
      debug() << imie(bs(mask)) imie(cur) imie(prod);
    else
      debug() << imie(bs(mask));
  }

  ll dp[2][k + 1];
  // dp[0][i] -> count of odd element is even and size of the subset is i
  // dp[1][i]-> count of odd elements is odd and size of the subset is i

  for (int i = 0; i <= k; i++) dp[0][i] = dp[1][i] = 0;

  // Base case
  dp[0][0] = 1;
  // count of odd elements is even(i.e. equal to zero) and set size is 0

  for (int i = 0; i < n; i++) {     // i denotes the array element
    for (int j = k; j >= 1; j--) {  // j denotes the subset size
      if (A[i] & 1) {
        dp[0][j] += dp[1][j - 1] * A[i];
        dp[1][j] += dp[0][j - 1] * A[i];
      } else {
        dp[0][j] += dp[0][j - 1] * A[i];
        dp[1][j] += dp[1][j - 1] * A[i];
      }
      dp[0][j] %= M;
      dp[1][j] %= M;
    }
  }

  // cout << "Sum of products of subsets of size K with the frequency of odd
  // elements as even is: " << dp[0][k] << endl;
  cout << dp[0][k] << endl;
}