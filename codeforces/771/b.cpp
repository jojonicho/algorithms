#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int n, x;

void solve() {
  cin >> n;
  vector<int> odd, even;
  for(int i=0; i<n; i++) {
    cin >> x;
    if(x&1) odd.push_back(x);
    else even.push_back(x);
  }

  bool ok = is_sorted(all(even)) && is_sorted(all(odd));
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
