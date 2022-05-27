#include <bits/stdc++.h>
using namespace std;

#define en '\n'
#define fast                   \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL);

const int N = 105, M = 105;

int G[N][M], H[N][M];

int n, m;

char c;

int main() {
  fast;
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
      cin >> c;
      G[i][j] = c == '*';
    }

  vector<array<int, 3>> ans;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int cur = -1;
      for(int k=1; k<=(min(n, m) / 2); k++) {
        if(i-k < 0 || i+k >= n || j-k < 0 || j+k >= m || !G[i-k][j] || !G[i+k][j] || !G[i][j-k] || !G[i][j+k]) break;
        cur = k;
      }
      if(cur == -1) continue;
      for(int k=0; k<=cur; k++) {
        H[i+k][j] = H[i-k][j] = H[i][j-k] = H[i][j+k] = 1;
      }
      ans.push_back({i, j, cur});
    }
  }

  bool ok = 1;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(G[i][j] != H[i][j]) ok = 0;

  if(!ok) {
    cout << -1 << en;
    return 0;
  }
  cout << (int)ans.size() << en;
  for(auto [r, c, k]: ans) {
    cout << r + 1 << " " << c + 1 << " " << k << en;
  }
}
