#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int A[N], indexOf[N];

void solve() {
  int n; cin >> n;
  for(int i=0; i<n; i++) {
    cin >> A[i];
    indexOf[A[i]] = i;
  }

  for(int k=1; k<=n; k++) {
    int i = indexOf[k];
    int j=i;
    for(; j-1>=0 && A[j-1] > A[i]; j--);
      
    if(j != i) {
      reverse(A+j, A+i+1);
      break;
    }
  }

  for(int i=0; i<n; i++) cout << A[i] << " ";
  cout << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
