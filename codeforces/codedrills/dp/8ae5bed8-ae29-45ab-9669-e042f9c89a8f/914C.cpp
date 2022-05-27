#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 1000;
const int MOD = 1e9 + 7;
ll iv[N + 1], fact[N + 1], ifact[N + 1];
ll nCk(int n, int k) { return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD; }

void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= N; i++) {
    iv[i] = MOD - MOD / i * iv[MOD % i] % MOD;
    fact[i] = fact[i - 1] * i % MOD;
    ifact[i] = ifact[i - 1] * iv[i] % MOD;
  }
}

string s;
int n, k;

int dp[N+5];

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

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

int main() {
  pre();
  cin >> s >> k;

  n = s.size();

  dp[1] = 1;
  for(int i=2; i<=N; i++) {
    dp[i] = dp[__builtin_popcount(i)] + 1;
  }

  ll ans = 0;
  if(dp[count(all(s), '1')] == k) {
    ans = 1;
  }
  if(k == 1) ans--;

  int nOne = 0;
  for(int i=0; i<n; i++) {
    if(s[i] == '0') continue;
    // fix turned on bit
    int spaces = n - i - 1;
    for(int j=0; j<=spaces; j++) {
      // s = 1 0 1
      // i = 0
      // j = 1
      // 2 choose 1 = 2
      // 0 1 0
      // 0 0 1
      // =====
      // j = 2
      // 2 choose 2 = 1;
      // 0 1 1
      if(dp[nOne + j] == k) {
        ans = add(ans, nCk(spaces, j));
      }
    }
    nOne++;
  }
  cout << ans;
}
