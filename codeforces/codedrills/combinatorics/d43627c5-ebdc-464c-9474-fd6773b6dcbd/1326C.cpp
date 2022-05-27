#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const int MOD = 998244353;

int A[N];

int n, k;

ll mul(ll x, ll y) {
  return (x * y) % MOD;
}

int main() {
  cin >> n >> k;

  for(int i=0; i<n; i++) cin >> A[i];

  vector<int> pos;
  ll sm = 0;
  for(int i=0; i<n; i++) {
    if(A[i] > n-k) {
      sm += A[i];
      pos.push_back(i);
    }
  }

  ll ans = 1;
  for(int i=1; i<k; i++) {
    ans = mul(ans, pos[i] - pos[i-1]);
  }
  cout << sm << " " << ans;
}
