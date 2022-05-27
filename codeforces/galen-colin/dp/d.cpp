#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
ll A[N], pref[N];  // prefix of non awake lecture notes
bool awake[N];

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;

  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) {
    cin >> awake[i];
    pref[i] = pref[i - 1];
    if (!awake[i])
      pref[i] += A[i];
    else
      ans += A[i];
  }

  ll mx = 0;
  for (int i = k; i <= n; i++) {
    mx = max(mx, pref[i] - pref[i - k]);
  }
  cout << ans + mx;
}