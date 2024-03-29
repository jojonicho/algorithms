#include <bits/stdc++.h>

#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py c.cpp

using namespace std;
using namespace atcoder;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL);
#define F_OR(i, a, b, s) \
  for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)     \
  F_ORC(__VA_ARGS__) \
  (__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...)     \
  E_ACHC(__VA_ARGS__) \
  (__VA_ARGS__)
/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/
const int N = 8, M = N * (N - 1) / 2;
bool G[N][N], H[N][N];

int main() {
  fast;
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a][b] = 1;
    G[b][a] = 1;
  }

  for (int i = 0; i < m; i++) {
    int c, d;
    cin >> c >> d, c--, d--;
    H[c][d] = 1;
    H[d][c] = 1;
  }

  vector<int> P(n);
  iota(all(P), 0);

  bool ok = 0;

  while (1) {
    bool ok2 = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (G[i][j] ^ H[P[i]][P[j]]) ok2 = 0;

    if (ok2) {
      ok = 1;
      break;
    }
    if (!next_permutation(all(P))) break;
  }

  cout << (ok ? "Yes" : "No");
}