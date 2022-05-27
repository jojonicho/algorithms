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

const int N = 1005, K = 1005;
const ll INF = 1e10;
const int N_BITS = 6, MASK = (1 << N_BITS) - 1, UPPER_ROW = 56,
          N_UPPER_BITS = 3;

// mask corresponding to the combination of 2x1 dominoes (horizontal & vertical
// placements) 1 means available to take, 0 means already taken
const int MASK_A[] = {1, 2, 1, 2, 4};
const int MASK_B[] = {2, 4, 8, 16, 32};

const int ROW_A[] = {0, 0, 0, 0, 0};
const int COL_A[] = {0, 1, 0, 1, 2};

const int ROW_B[] = {0, 0, 1, 1, 1};
const int COL_B[] = {1, 2, 0, 1, 2};

int n, m = 3, k;
int A[N][K];
ll dp[N][K][MASK];

ll go(int row, int token, int mask) {
  if (row == n) {
    if (token != 0) return -INF;
    return 0;
  }
  if (token == 0) return 0;

  ll &ans = dp[row][token][mask];
  if (ans != -1) return ans;
  ans = go(row + 1, token,
           (mask >> N_UPPER_BITS) + (row + 1 < n ? UPPER_ROW : 0));  // no take;

  FOR(5) {
    if (mask & MASK_A[i] && mask & MASK_B[i])
      ans = max(ans, A[row + ROW_A[i]][COL_A[i]] + A[row + ROW_B[i]][COL_B[i]] +
                         go(row, token - 1, mask ^ MASK_A[i] ^ MASK_B[i]));
  }
  return ans;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  FOR(n) {
    FOR(j, m) { cin >> A[i][j]; }
  }
  cout << go(0, k, MASK) << en;
}