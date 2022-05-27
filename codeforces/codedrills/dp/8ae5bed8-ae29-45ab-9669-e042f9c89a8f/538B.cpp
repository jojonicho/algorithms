#include <bits/stdc++.h>
using namespace std;

#define en '\n'

const int N = 7;

int A[N];
int k, n;

int main() {
  cin >> k;
  int mx = 0;

  string s = to_string(k);
  n = s.size();

  int x = k;
  int c = 0;
  while(x) {
    A[n-c-1] = x%10;
    mx = max(mx, x%10);
    x /= 10;
    c++;
  }
  cout << mx << en;

  // 6^9 <= 1e8
  while(mx--) {
    int x = 0;
    for(int i=0; i<n; i++) {
      if(A[i]) {
        x = x * 10 + 1;
        A[i]--;
      } else {
        x = x * 10;
      }
    }
    cout << x << " ";
  }
}
