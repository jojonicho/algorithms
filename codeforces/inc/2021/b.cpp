#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v1, v2;

bool findPartiion(int n, vector<int> A) {
  int sum = 0;

  for (int i = 0; i < n; i++) sum += A[i];

  if (sum & 1) {
    return 0;
  }
  sum /= 2;
  vector<int> dp(sum + 1);
  dp[0] = 1;
  for (int n : A) {
    for (int i = sum - n; i >= 0; i--) {
      dp[i + n] |= dp[i];
    }
  }
  return dp[sum];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    v1.push_back(x);
  }
  bool yes = findPartiion(n, v1);
  if (yes) {
    cout << "YES" << endl;
    return 0;
  }

  bool isTwo = 0;
  for (auto x : v1) {
    if (x == 2) {
      isTwo = 1;
    } else {
      v2.push_back(x);
    }
  }

  if (!isTwo) {
    cout << "NO" << endl;
    return 0;
  }
  
  yes = findPartiion(n - 1, v2);
  if (yes) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}