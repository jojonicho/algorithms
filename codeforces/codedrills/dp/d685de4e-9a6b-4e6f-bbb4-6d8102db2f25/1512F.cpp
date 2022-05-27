#include <bits/stdc++.h>
using namespace std;

#define en '\n'

typedef long long ll;

const int N = 2e5 + 5;

int A[N], B[N];
// nPromotions, number of days
ll rem[N], nDaysForUpgrade[N];

int n,c;

int ceil_div(int a, int b) {
  return (a + b - 1) / b;
}


void solve() {
  cin >> n >> c;
  for(int i=1; i<=n; i++) cin >> A[i];
  for(int i=2; i<=n; i++) cin >> B[i];

  ll ans = ceil_div(c, A[1]);
  for(int i=2; i<=n; i++) {
    nDaysForUpgrade[i] = ceil_div(B[i] - rem[i-1], A[i-1]);
    rem[i] = nDaysForUpgrade[i] * A[i-1] - B[i] + rem[i-1];
    nDaysForUpgrade[i] += nDaysForUpgrade[i-1];

    ll cur = ceil_div(c - rem[i], A[i]) + nDaysForUpgrade[i] + i-1;
    //debug() << im(nDaysForUpgrade[i]) im(rem[i]) im(dp[i]);
    ans = min(ans, cur);
  }

  cout << ans << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
