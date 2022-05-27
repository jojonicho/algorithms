#include<bits/stdc++.h>
using namespace std;

int n, x;
string s;

int main() {
  cin >> n;
  
  x = n;
  int len = 0;
  while(x) {
    x /= 10;
    len++;
  }

  int ans = 0;

  for(int i=1; i<len; i++) ans += (1<<i);
  
  int pw = 0;
  while(n) {
    x = n%10;
    if(x == 7) ans += (1<<pw);
    pw++;
    n/=10;
  }

  cout << ans + 1;
}
