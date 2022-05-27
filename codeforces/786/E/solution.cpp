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
  cin.tie(NULL); 

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

int main() {
  fast;
  int n;
  cin >> n;
  vt<int> A(n);
  FOR(n)
    cin >> A[i];

  vt<int> B = A;
  sort(all(B));

  int ans = (B[0] + 1) / 2 + (B[1]+1)/2; // shoot two smallest elements

  // 3 6 5
  // 3
  // shoot middle 3 times

  for(int i=0; i<n-1; i++) {
    int mn = A[i], mx = A[i+1];
    if(mn > mx)
      swap(mn, mx);

    // if mx == mn
    // shoot mx
    // • mx -= 2
    // • mn -= 1
    // vice versa

    int cur = max((mx+1)/2, (mn+mx+2)/3); // (mx+1)/2 is case where mx >= 2*mn
    ans = min(ans, cur);
  }

  for(int i=0; i<n-2; i++) {
    int mn = A[i], mx = A[i+2];
    if(mn > mx)
      swap(mn, mx);
    // shoot mn -> mn -= 2
    // shoot mx -> mx -= 2
    // shoot middle -> mn -= 1, mx -= 1
    // so shoot middle mn times, and then shoot mx (mx - mn) / 2 times
    ans = min(ans, mn + (mx-mn+1)/2);
  }
  cout << ans << en;
}

