#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define en '\n'


int n, k; 

bool is_palindrome(string s) {
  for(int i=0; i<n/2; i++) {
    if(s[i] != s[n-i-1]) return false;
  }
  return true;
}

void solve() {
  cin >> n >> k;
  string s;
  cin >> s;
  
  if(is_palindrome(s) || !k) cout << 1;
  else cout << 2;
  cout << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}

