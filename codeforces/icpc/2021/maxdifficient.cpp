#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef long long ll;

int main() {
  int n;
  cin >> n;

  ll A[n + 1];
  for (int i = 1; i <= n; i++) cin >> A[i];

  vll mnPref(n + 1), mxPref(n + 1), mnSuf(n + 1), mxSuf(n + 1);

  ll mn = A[1], mx = A[1];
  mnPref[1] = mn;
  mxPref[1] = mx;

  for (int i = 2; i <= n; i++) {
    mn = min(mn + A[i], A[i]);
    mx = max(mx + A[i], A[i]);
    mnPref[i] = min(mn, mnPref[i - 1]);
    mxPref[i] = max(mx, mxPref[i - 1]);
  }

  mn = A[n], mx = A[n];
  mnSuf[n] = mn;
  mxSuf[n] = mx;

  for (int i = n - 1; i >= 1; i--) {
    mn = min(mn + A[i], A[i]);
    mx = max(mx + A[i], A[i]);
    mnSuf[i] = min(mn, mnSuf[i + 1]);
    mxSuf[i] = max(mx, mxSuf[i + 1]);
  }

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ll x = abs(mxPref[i] - mnSuf[i + 1]), y = abs(mnPref[i] - mxSuf[i + 1]);
    ans = max({ans, x, y});
  }
  cout << ans;
}