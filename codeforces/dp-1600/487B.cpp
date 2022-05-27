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

g[i + 1] <  = g[i] + 1 so it's also a sliding window minimum problem.
*/
const int N = 1e5 + 5;

int A[N], dp[N];
deque<int> q, qmax, qmin;  // dp, maxValues, minValues
int n, s, l;               // s = max-min, l = groupLen

int main() {
  cin >> n >> s >> l;
  const int INF = n + 1;

  int j = 0;
  FOR(i, 1, n + 1) {
    cin >> A[i];
    dp[i] = INF;

    int x = A[i];
    while (!qmax.empty() && A[qmax.back()] <= x) qmax.pop_back();  // decreasing
    qmax.push_back(i);
    while (!qmin.empty() && A[qmin.back()] >= x) qmin.pop_back();  // increasing
    qmin.push_back(i);

    // valid qmin and qmax, find minimum j where A[qmax[0]] - A[qmin[0]] <= s
    while (j < i && !qmax.empty() && !qmin.empty() &&
           A[qmax[0]] - A[qmin[0]] > s) {
      // we have processed j before
      while (!qmin.empty() && qmin[0] <= j) qmin.pop_front();
      while (!qmax.empty() && qmax[0] <= j) qmax.pop_front();
      j++;
    }
    // [j,i-L] is the longest segment now
    // debug() << imie(i) imie(j) imie(qmin) imie(qmax);

    // process q
    if (i >= l) {  // cur idx at least required size
      while (!q.empty() && dp[q.back()] + 1 > dp[i - l])
        q.pop_back();  // g[i + 1] <= g[i] + 1
      q.push_back(i - l);
    }
    // j - 1 <= k <= i - L
    while (!q.empty() && q[0] < j - 1) q.pop_front();

    if (!q.empty()) dp[i] = dp[q[0]] + 1;
  }

  if (dp[n] >= INF) dp[n] = -1;
  cout << dp[n];
}