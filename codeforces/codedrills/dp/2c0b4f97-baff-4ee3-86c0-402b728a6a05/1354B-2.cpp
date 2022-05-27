#include <bits/stdc++.h>
using namespace std;

#define en '\n'
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int A[N];
int lastOccur[4];

int n;
string s;

void solve() {
  memset(lastOccur, -1, sizeof(lastOccur));
  cin >> s;
  n = s.size();

  for(int i=0; i<n; i++) A[i] = s[i] - '0';

  auto ok = [&](int x) {
    return lastOccur[x] >= 0;
  };

  //int lasts[3] = {-1, -1, -1};
  vector<int> lasts{-1, -1, -1};

  auto getLasts = [&]() {
    lasts = {lastOccur[1], lastOccur[2], lastOccur[3]};
  };

  int ans = n + 1;
  for(int i=0; i<n; i++) {
    lastOccur[A[i]] = i;
    if(ok(1) && ok(2) && ok(3)) {
      getLasts();
      ans = min(ans, *max_element(all(lasts)) - *min_element(all(lasts)) + 1);
    }
  }
  cout << (ans == n+1 ? 0 : ans) << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}

