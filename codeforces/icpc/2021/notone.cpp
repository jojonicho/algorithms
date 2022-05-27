#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 5, X = 1e6 + 5;
int A[N];
vector<pii> G[X];  // graph for every factor

struct DSU {
  vi A;
  DSU(int n) : A(n, -1) {}

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

int main() {
  int n;
  cin >> n;

  int ans = 0;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] > 1) ans = 1;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    // A[u] < A[v]
    int _gcd = gcd(A[u], A[v]);
    for (int j = 1; j * j <= _gcd; j++) {
      if (_gcd % j == 0) {
        G[j].push_back({u, v});
        if (_gcd / j != j) G[_gcd / j].push_back({u, v});
      }
    }
  }

  DSU uf(N);
  for (int i = 2; i < X; i++) {  // loop for every factor, find the cardinality
    for (auto [u, v] : G[i]) {
      uf.join(u, v);
      ans = max(ans, uf.size(u));
    }
    for (auto [u, v] : G[i]) {
      uf.A[u] = -1;
      uf.A[v] = -1;
    }
  }
  cout << ans;
}