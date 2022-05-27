#include <bits/stdc++.h>
using namespace std;

#define en '\n'

typedef long long ll;

const ll INF = 1e18 + 5;

template <typename T>
struct binary_indexed_tree {
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N) : N(N), BIT(N + 1, 0) {}
  void add(int i, T x) {
    i++;
    while (i <= N) {
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i) {
    i++;
    T ans = 0;
    while (i > 0) {
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R) { return sum(R) - sum(L - 1); }
};
// sort(B, B + n);
// int r = unique(B, B + n) - B;

int n;
string s, t;

void solve() {
  cin >> n;
  cin >> s >> t;

  binary_indexed_tree<ll> BIT(n + 1);
  queue<int> q[26]; // track index of characters in s

  for(int i=1; i<=n; i++) {
    q[s[i-1] - 'a'].push(i);
    BIT.add(i, 1);
  }

  ll ans = INF, prefCost = 0;

  for(char d: t) {
    int dInt = d-'a';
    int closestIdx = n + 1;
    for(int i=0; i<dInt; i++) { // win now
      if(q[i].empty()) continue;
      closestIdx = min(closestIdx, q[i].front());
    }
    if(closestIdx != n + 1) {
      ll winNow = prefCost + BIT.sum(closestIdx-1);
      ans = min(ans, winNow);
    }

    // tie
    if(q[dInt].empty()) break;
    int idx = q[dInt].front(); q[dInt].pop();

    prefCost += BIT.sum(idx-1);
    BIT.add(idx, -1);
  }

  cout << (ans == INF ? -1 : ans) << en;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
} 
