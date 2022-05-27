#include<bits/stdc++.h>
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

typedef long long ll;

const int N = 100;
const int MOD = 1e9 + 7;
ll iv[N + 1], fact[N + 1], ifact[N + 1];
ll nCk(int n, int k) { 
  if(k > n) return 0;
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD; }

void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= N; i++) {
    iv[i] = MOD - MOD / i * iv[MOD % i] % MOD;
    fact[i] = fact[i - 1] * i % MOD;
    ifact[i] = ifact[i - 1] * iv[i] % MOD;
  }
}

ll dp[N+5][N+5];

int A[10];

int n;

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll go(int curN, int idx) {
  if(idx == 10) return curN == 0;
  ll &ans = dp[curN][idx];
  if(ans != -1) return ans;

  ans = 0;

  for(int i=A[idx]; i<=curN; i++) {
    ll c = nCk(curN, i);
    if(idx == 0) c = nCk(curN-1, i);
    ll cur = mul(c, go(curN-i, idx+1));
    //debug() << im(idx) im(i) im(cur);
    ans = add(ans, cur);
  }
  return ans;
}

int main() {
  memset(dp, -1, sizeof(dp));
  pre();
  cin >> n;

  for(int i=0; i<10; i++) cin >> A[i]; // digit i appears at least A[i] times
  
  //cout << go(n, 0);

  ll ans = 0;
  for(int i=1; i<=n; i++) {
    debug() << im(go(i, 0));
    ans = add(ans, go(i, 0));
  }
  cout << ans;
}
