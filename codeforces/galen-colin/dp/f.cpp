#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4;

ll D[N + 1];
void pre() {
  D[0] = 1;
  D[1] = 0;
  D[2] = 1;
  for (ll i = 3; i <= N; i++) D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
}

/**
 * go horizontally in pascal's triangle
 */
ll nCr(int n, int r) {
  if (n < 0 || r < 0 || r > n) return 0;
  ll ans = 1;
  for (int i = 1; i <= r; i++) {
    ans *= (n + 1 - i);
    ans /= i;
  }
  return ans;
}

int main() {
  pre();
  int n, k;
  cin >> n >> k;
  ll ans = 1;  // sorted
               // atleast n-k integers where p_i = i
               // at most k derangements
  // derangements -> in a sorted manner, A[i] is not in it's sorted position

  if (k >= 2) ans += nCr(n, 2) * D[2];
  if (k >= 3) ans += nCr(n, 3) * D[3];
  if (k >= 4) ans += nCr(n, 4) * D[4];
  cout << ans;
}