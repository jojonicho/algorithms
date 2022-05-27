#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int A[N];
int n;
int main() {
  cin >> n;

  for(int i=0; i<n; i++) cin >> A[i];

  vector<int> dp;
  for(int i=0; i<n; i++) {
    int x = A[i];
    // 3 8
    // 2 8
    // 1 8
    // find closest element larger than x
    int idx = upper_bound(all(dp), x) - dp.begin();
    if(idx == dp.size()) dp.push_back(x);
    else dp[idx] = x;
  }

  cout << (int)dp.size();
}

