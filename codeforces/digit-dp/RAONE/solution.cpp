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

if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

const int D = 9, S = 9 * D, E = S/2, O = S/2;

ll dp[D+1][E+1][O+1][2]; // even, odd

ll f(int r) {
  string s = to_string(r);
  int n = sz(s);

  memset(dp, 0, sizeof(dp));
  dp[n][0][0][0] = dp[n][0][0][1] = 1;

  for(int i=n-1; i>=0; i--) {
    int x = s[i]-'0';
    // ok so indexing starts from right
    // also from starts from 1, so s.back is odd
    // stupid but wtv
    int isEven = (n-i)%2==0;

    for(int j=0; j<=E; j++) {
      for(int k=0; k<=O; k++) {
        for(int l=0; l<=9; l++) {
          int jj = j;
          int kk = k;
          if(isEven) {
            jj -= l;
          } else {
            kk -= l;
          }
          if(jj < 0 || kk < 0)
            continue;

          dp[i][j][k][0] += dp[i+1][jj][kk][0];

          if(l <= x)
            dp[i][j][k][1] += dp[i+1][jj][kk][l==x];
        }

      }
    }
  }

  ll ans = 0;
  for(int i=1; i<=E; i++)
    for(int j=0; j<=O; j++)
      if(i - j == 1)
        ans += dp[0][i][j][1];

  return ans;
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << f(r) - f(l-1) << en;
}

int main() {
  fast;
  int q;
  cin >> q;
  while(q--)
    solve();
}

