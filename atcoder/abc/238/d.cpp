#include <bits/stdc++.h>
using namespace std;

#define en '\n';

typedef long long ll;

const string YES = "Yes", NO = "No";

void solve() {
  ll a, s;
  cin >> a >> s;

  ll target = s - 2*a;
  cout << (target >= 0 && !(target&a) ? YES : NO) << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
