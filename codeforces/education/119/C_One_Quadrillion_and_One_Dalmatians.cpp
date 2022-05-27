#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;

  string ans;
  while (n) {
    n -= 1;
    ans += 'a' + (n % 26);
    n /= 26;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}