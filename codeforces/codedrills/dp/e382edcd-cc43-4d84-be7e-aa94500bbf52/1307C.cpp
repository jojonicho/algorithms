#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;

string s;
int n;

map<char, ll> mp;
ll dp[26][26];

int main() {
  cin >> s;
  n = s.size();

  ll ans = 0;
  for(char c: s) {
    for(char d='a'; d<='z'; d++) {
      dp[d-'a'][c-'a'] += mp[d];
      ans = max(ans, dp[d-'a'][c-'a']);
    }
    ans = max(ans, ++mp[c]);
  }
  cout << ans;
}
