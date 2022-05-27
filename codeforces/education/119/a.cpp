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

void solve() {
  string s;
  cin >> s;
  int n = s.size();

  int nComponents = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'N') {
      nComponents++;
    }
  }

  bool flag = nComponents == 1 && s.back() == 'N' ||
              nComponents == 2 && s.back() == 'E';
  bool ok = !flag;

  cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}