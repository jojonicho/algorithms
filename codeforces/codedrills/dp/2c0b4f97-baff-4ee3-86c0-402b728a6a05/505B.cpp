#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define en '\n'

typedef vector<int> vi;

const int N = 105, M = 105;

struct DSU {
  vi A ;
  DSU() : A(N, -1) {}
  //DSU(int n) : A(n, -1) {}

  int find(int x) {
    if (A[x] < 0) return x;
    return A[x] = find(A[x]);
  }

  bool is_same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;
    if (x > y) swap(x, y);
    if (A[x] > A[y]) swap(x, y);

    A[x] += A[y];
    A[y] = x;

    return true;
  }

  int size(int x) { return -A[find(x)]; }
};


DSU dsu[M];

int n, m, q;
int u, v, c;

int main() {
  cin >> n >> m;

  for(int i=0; i<m; i++) {
    cin >> u >> v >> c, u--, v--, c--;
    dsu[c].join(u, v);
  }

  cin >> q;
  while(q--) {
    cin >> u >> v, u--, v--;
    int ans = 0;
    for(int i=0; i<m; i++) if(dsu[i].is_same(u, v)) ans++;
    cout << ans << en;
  }
}
