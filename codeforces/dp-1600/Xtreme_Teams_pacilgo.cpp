#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
const ll mo = 1e9 + 7;
ll F[NN], a[NN], n, m;

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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (ll i = 0; i < (1 << m); i++) F[i] = 0;
    for (ll i = 1; i <= n; i++) {
      ll jum = 0;
      for (ll j = 0; j < m; j++) {
        char ct;
        cin >> ct;
        jum += (1 << j) * (ct == 'y');
      }
      a[i] = jum;
      debug() << imie(a[i]);
      F[jum]++;
    }
    for (ll i = 0; i < m; i++)
      for (ll mask = ((1 << m) - 1); mask >= 0; mask--)
        if ((mask & (1 << i)) == 0) F[mask] += F[mask ^ (1 << i)];
    ll has = 0;
    for (ll i = 1; i <= n; i++)
      for (ll j = i + 1; j <= n; j++) {
        ll now = (a[i] | a[j]);
        now ^= ((1 << m) - 1);
        if (now == 0)
          has += (n - 2);
        else
          has += F[now];
      }
    has /= 3;
    cout << has << "\n";
  }
}