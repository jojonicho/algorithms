#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;
int frek[30];

int main() {
  cin >> n >> s >> t;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      mx = max(mx, ++frek[s[i] - 'a']);
    } else {
      mx = max({mx, ++frek[s[i] - 'a'], ++frek[t[i] - 'a']});
    }
  }
  cout << mx << endl;
}