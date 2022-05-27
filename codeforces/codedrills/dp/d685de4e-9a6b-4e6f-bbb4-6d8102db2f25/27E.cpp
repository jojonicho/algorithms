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

#define pb push_back

typedef long long ll;
typedef vector<int> vi;

const int N = 1e3;

vi G[N+5];

int n;
//ll ans; // <= 1e18

void pre() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j*j<=i; j++) {
      if(i % j) continue;
      G[i].pb(j);
      if(i/j != j) G[i].pb(i/j);
    }
  }
}

int main() {
  pre();
  cin >> n;
  for(int i=1; i<=n; i++) {
    debug() << im(i) im(G[i]);
  }
}
