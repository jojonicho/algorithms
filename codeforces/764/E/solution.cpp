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

void solve() {
  int n, m;
  cin >> n >> m;
  vt<string> S(n);
  FOR(n) {
    cin >> S[i];
    S[i] = '$' + S[i];
  }

  string s; cin >> s;
  s = "#" + s;

  map<string, ar<int,3>> mp;
  for(int i=0; i<n; i++) {
    for(int j=2; j<=m; j++) {
      for(int k=2; k<=3; k++) {
        int l = j-k+1;
        if(l == 0)
          break;
        string t = S[i].substr(l, k);
        mp[t] = {l, l+k-1, i+1};
      }
    }
  }

  vt<ar<int,3>> dp(m+1, {-1, -1, -1});
  dp[0] = {0, 0, 0};
  vt<int> prv(m+1, -1);

  for(int i=2; i<=m; i++) {
    for(int k=2; k<=3; k++) {
      int l = i - k + 1;
      if(l==0)
        break;
      string t = s.substr(l, k);
      if(dp[i-k][0] != -1 && mp.find(t) != mp.end()) {
        dp[i] = mp[t];
        prv[i] = i-k;
      }
    }
  }

  //dbg() << im(dp);
  if(dp[m][0] == -1) {
    cout << -1 << en;
    return;
  }
  int idx = m;
  vt<ar<int,3>> ans;
  while(idx != 0) {
    ans.pb(dp[idx]);
    idx = prv[idx];
  }
  reverse(all(ans));
  cout << sz(ans) << en;
  for(auto [a,b,c]: ans)
    cout << a << " " << b << " " << c << " " << en;
}

int main() {
  fast;
  int t=1;
  cin >> t;
  string s;
  while(t--) {
    getline(cin, s);
    solve();
  }
}
