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

const int N = 2e3 + 5;

bool isPalindrome[N][N];
ll pref[N];

int n;
string s;

int main() {
  cin >> s;
  n = s.size();
  
  for(int i=0; i<n; i++) {
    int l=i, r=i;
    isPalindrome[l][r] = 1;

    while(r+1 < n && s[r+1] == s[l]) {
      r++;
      isPalindrome[l][r] = 1;
    }

    while(l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) {
      l--;
      r++;
      isPalindrome[l][r] = 1;
    }
  }

  ll ans = 0;
  for(int i=0; i<n; i++) {
    if(i) pref[i] = pref[i-1];
    for(int j=0; j<=i; j++) {
      pref[i] += isPalindrome[j][i];
      if(j) ans += isPalindrome[j][i] * pref[j-1];
    }
  }

  cout << ans;
}
