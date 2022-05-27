#include <bits/stdc++.h>
using namespace std;
/*
The less-than operator on strings does a lexicographical comparison on the
strings. This compares strings in the same way that they would be listed in
dictionary order, generalized to work for strings with non-letter characters.
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> S(n);
  for (int i = 0; i < n; i++) cin >> S[i];

  auto cmp = [&](string &a, string &b) { return a + b < b + a; };
  sort(S.begin(), S.end(), cmp);
  vector<vector<string>> dp(n + 1, vector<string>(k + 1, "{"));  // take or not
  dp[n][0] = "";  // "{ is 1 greater than z in ascii"
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = min(dp[i][j], dp[i + 1][j]);
      if (j) dp[i][j] = min(dp[i + 1][j], S[i] + dp[i + 1][j - 1]);
    }
  }
  cout << dp[0][k];
}