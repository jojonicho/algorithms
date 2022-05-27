#include <bits/stdc++.h>
using namespace std;

#define en '\n'

const int N = 2e5 + 5;

int mp[4];
int A[N];

int n;

void solve() {
  memset(mp, 0, sizeof(mp));
  string s;
  cin >> s;
  n = s.size();

  for(int i=0; i<n; i++) A[i] = s[i] - '0';

  int l = 0, r = 0;
  int ans = n + 1;

  while(l < n) {
    auto ok = [&]() {
      return mp[1] && mp[2] && mp[3];
    };
    while(r < n && !ok()) {
      mp[A[r]]++;
      r++;
    }

    while(l < r && ok()) {
      ans = min(ans, r - l);
      mp[A[l]]--;
      l++;
    }
    mp[A[l]]--;
    l++;
  }

  cout << (ans == n+1 ? 0 : ans) << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}

