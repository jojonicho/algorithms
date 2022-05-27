#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll add(ll x, ll y) {
  return (x + y) % MOD;
}

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

ll bin_pow(ll x, ll p) {
	if(p==0) return 1;
	if(p & 1) return mul(x, bin_pow(x, p-1));
	return bin_pow(mul(x,x), p/2);
}

ll inv(ll x) { 
  return bin_pow(x, MOD - 2);
}

ll f(ll x) {
  return mul(mul(x, x+1), inv(2));
}

int main() {
  ll n; cin >> n;

  ll digit = 1;
  ll ans = 0;
  while(digit <= n) {
    ll x;
    if(digit * 10 > n) {
      x = n % (digit * 10) - digit + 1;
    } else x = digit * 10 - digit;
    ans = add(ans, f(x % MOD));
    digit *= 10;
  }
  cout << ans % MOD;
}
