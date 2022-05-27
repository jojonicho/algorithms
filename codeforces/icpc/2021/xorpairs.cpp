#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int banned[N];
int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    banned[x] = 1;
  }

  long long ans = 0, cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (__builtin_popcount(i) == 1) {  // power of two
      cnt = 0;
    }
    if (!banned[i]) ans += cnt;
    cnt += 2;
  }
  cout << ans;
}