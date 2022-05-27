#include <bits/stdc++.h>
using namespace std;

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
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y <<
// ")"; return dd; }

#define en '\n'

typedef long long ll;

const int N = 5e4 + 5, X = 1e5 + 5;
const ll INF = 1e10 + 5;

int A[N];
ll S[N];

int n, x;

void solve() {
  cin >> n;
  for(int i=1; i<=n; i++) cin >> A[i];
  cin >> x;
  // average? subtract x from everything
  for(int i=1; i<=n; i++) A[i] -= x;
  for(int i=1; i<=n; i++) S[i] = S[i-1] + A[i];

  int ans = n;
  ll mx = -INF;
  for(int i=2; i<=n; i++) {
    // non positive subsequence
    mx = max(mx, S[i-2]);
    if(S[i] - mx < 0) {
      ans--;
      mx = -INF; 
      i++; // exclude S[i]
    }
  }

  cout << ans << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
