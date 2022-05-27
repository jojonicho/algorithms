#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

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
  string s;
  cin >> s;
  ll k;
  cin >> k;

  vi A;
  for (int i = 0; i < (int)s.size(); i++)
    if (s[i] == 'Y') A.push_back(i);

  int n = A.size();
  vi B(n);  // B[i] - B[i-1] is distance between Y's
  for (int i = 0; i < n; i++) B[i] = A[i] - i;

  vector<ll> pref(n + 1);
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + B[i - 1];

  int lo = 0, hi = n;  // bsta
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    bool ok = 0;
    for (int i = 0; i <= n - mid; i++) {
      ll left = pref[i] - pref[i + (mid + 1) / 2],
         right = pref[i + mid] - pref[i + mid / 2];
      if (left + right <= k) ok = 1;
    }

    if (ok)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  cout << hi;
}