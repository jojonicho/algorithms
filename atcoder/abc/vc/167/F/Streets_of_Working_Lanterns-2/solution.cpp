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

/*
if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

ar<int, 2> score(string s, bool rev=0) {
  char opening = '(';
  if(rev) {
    opening = ')';
    reverse(all(s));
  }

  int bal=0;
  int mn = 0;
  for(auto c: s) {
    if(c==opening)
      bal++;
    else
      bal--;
    mn = min(mn, bal);
  }
  return {mn, bal};
}

void solve() {
  int n;
  cin >> n;
  vt<string> S(n);
  for(int i=0; i<n; i++) {
    cin >> S[i];
  }

  vt<ar<int, 3>> A, B;
  ll cur = 0;

  for(int i=0; i<n; i++) {
    string &s = S[i];
    auto [mn, bal] = score(s);
    cur += bal;
    if(bal >= 0) {
      A.pb({mn, bal, i});
    } else {
      auto [mn, bal] = score(s, 1);
      B.pb({mn, bal, i});
    }
  }
  if(cur != 0) {
    cout << "NO" << en;
    return;
  }

  sort(all(A), greater<ar<int,3>>());
  sort(all(B), greater<ar<int,3>>());

  vt<vt<int>> ans(2, vt<int>());
  for(auto &[C, k]: {make_pair(A, 0), make_pair(B, 1)}) {
    cur = 0;
    for(auto [mn, bal, i]: C) {
      if(cur + mn < 0) {
        cout << "NO" << en;
        return;
      }
      cur += bal;
      ans[k].pb(i);
    }
  }

  cout << "YES" << en;
  for(auto x: ans[0])
    cout << x + 1 << " ";
  reverse(all(ans[1]));
  for(auto x: ans[1])
    cout << x + 1 << " ";
  cout << en;
}

int main() {
  fast;
  int t=1;
  //cin >> t;
  while(t--)
    solve();
}



