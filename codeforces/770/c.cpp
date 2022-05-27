#include <bits/stdc++.h>
using namespace std;

#define en '\n'

const int N = 505, K = 505;

int A[N][K];

int n, k;

void solve() {
  cin >> n >> k;
  int odd = 1, even = 1;

  for(int i=0; i<n; i++) {
    bool isEven = i%2 == 0;
    for(int j=0; j<k; j++) {
      if(isEven) {
        A[i][j] = 2 * odd - 1;
        odd++;
      } else {
        A[i][j] = 2 * even;
        even++;
      }
    }
  }

  bool ok = n % 2 == 0 || k == 1;

  if(!ok) {
    cout << "NO" << en;
    return;
  }

  cout << "YES" << en;
  for(int i=0; i<n; i++) {
    for(int j=0; j<k; j++) {
      cout << A[i][j] << " ";
    }
    cout << en;
  }
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
