#include <bits/stdc++.h>
using namespace std;

int n, x;

void solve() {
  cin >> n;
  set<int> st;

  int mx = 0;
  for(int i=0; i<n; i++) {
    cin >> x;
    if(x > mx) {
      st.insert(x);
      mx = x;
    } else {
      auto it = st.lower_bound(x);
      while(it != st.end() && *it != mx) {
        it = st.erase(it);
      }
    }
  }

  cout << (int)st.size() << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
