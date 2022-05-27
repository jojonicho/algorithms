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

const int N = 1e5;
const int SQRT_N = 316;

ll A[N + 5], ans[N + 5], sum[N + 5];
vi generators[N + 5], lz[N + 5];

void update(int i, int x) {  // applianceIdx, value
  ans[i] += sum[i] * x;      // 1 * (2 + 3) + 2 * (3)
  sum[i] += x;               // 1 * 3 + 2 * 3 = 3 * (1+2)
}

int main() {
  fast;
  int n, m;  // nGenerators, nAppliances
  cin >> n >> m;

  for (int i = 1; i <= n; i++) cin >> A[i];

  for (int i = 1; i <= m; i++) {  // applianceIdx
    int c;
    cin >> c;

    FOR(j, c) {
      int x;
      cin >> x;
      generators[i].pb(x);
    }

    if (c >= SQRT_N) {
      for (auto j : generators[i]) {  // for generatorIdx: generators
        lz[j].pb(i);  // keep track of applianceIdx containing the 'j' generator
        update(i, A[j]);
      }
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int j, x;  // generatorIdx
      cin >> j >> x;
      // to update a generator, we need to notify the appliances using this
      // certain generator as well
      for (int i : lz[j]) {       // for applianceIdx
        sum[i] -= A[j];           // move A[j] as the last appliance, since
        ans[i] -= A[j] * sum[i];  // order doesnt change score
        update(i, x);
      }
      A[j] = x;

    } else {
      int i;  // applianceIdx
      cin >> i;
      if (generators[i].size() < SQRT_N) {
        ans[i] = sum[i] = 0;
        for (auto j : generators[i]) {
          update(i, A[j]);
        }
      }
      cout << ans[i] << en;
    }
  }
}