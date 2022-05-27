#include <bits/stdc++.h>
using namespace std;
#define en '\n';

const int T = 105;
int dp[T][3];  // up stay or down
int A[T];

int main() {
  memset(A, -1, sizeof A);
  int u, v;
  cin >> u >> v;
  int t, d;
  cin >> t >> d;

  A[0] = u, A[t - 1] = v;
  // two pointers
  int i = 0, j = t - 1;
  while (i + 1 < j) {
    int curD = abs(A[i] - A[j]);
    if (j - i == 2) {  // one element left
      A[i + 1] = min(A[i] + d, A[j] + d);
      i++;
      j--;
    } else if (curD > d && A[i] < A[j]) {
      A[i + 1] = A[i] + d;
      i++;
    } else if (curD > d && A[j] < A[i]) {
      A[j - 1] = A[j] + d;
      j--;
    } else {
      A[i + 1] = A[i] + d;
      A[j - 1] = A[j] + d;
      i++;
      j--;
    }
  }

  int ans = A[0];
  for (int i = 1; i < t; i++) {
    if (abs(A[i] - A[i - 1]) > d) {
      cout << -1;
      return 0;
    }
    ans += A[i];
  }
  cout << ans;
}