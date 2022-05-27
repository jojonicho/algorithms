#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 5;

int A[N], B[N], C[N];

int n;

int main() {
  cin >> n;
  for(int i=0; i<n; i++) cin >> A[i];

  ll ans = 0;

  for(int i=0; i<n; i++) {
    ll cur = A[i]; // apex
    C[i] = A[i];
    int mx = A[i];

    for(int j=i-1; j>=0; j--) {
      C[j] = min(mx, A[j]);
      cur += C[j]; 
      mx = min(mx, A[j]);
    }
    mx = A[i];
    for(int j=i+1; j<n; j++) {
      C[j] = min(mx, A[j]);
      cur += C[j];
      mx = min(mx, A[j]);
    }
    if(cur > ans) {
      ans = cur;
      for(int j=0; j<n; j++) B[j] = C[j];
    }
  }

  for(int i=0; i<n; i++) cout << B[i] << " ";
}
