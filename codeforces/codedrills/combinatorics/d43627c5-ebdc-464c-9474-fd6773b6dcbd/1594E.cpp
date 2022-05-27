#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int k;

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

ll bin_pow(ll x, ll p) {
  if(p==0) return 1;
  if(p&1) return mul(x, bin_pow(x, p-1));
  return bin_pow(mul(x, x), p/2);
}

int main() {
  cin >> k;

  ll nNodes = (1LL << k) - 1;

  cout << mul(6, bin_pow(4, nNodes-1));
}
