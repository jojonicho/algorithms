#include <bits/stdc++.h>
using namespace std;
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

void solve() {
  int n;
  cin >> n;
  int A[n], B[n];
  ll sA = 0, sB = 0;
  FOR(n) {
    cin >> A[i];
    sA += A[i];
  }
  FOR(n) {
    cin >> B[i];
    sB += B[i];
  }
  if (sA != sB) {
    cout << -1 << en;
    return;
  }
  vector<ar<int, 2>> ans;
  FOR(n - 1) {
    while (A[i] > B[i]) {
      A[i + 1]++;
      A[i]--;
      ans.pb({i, i + 1});
    }
    // cout << i << " " << A[i] << " " << B[i] << en;
  }

  for (int i = n - 1; i >= 1; i--) {
    while (A[i] > B[i]) {
      A[i - 1]++;
      A[i]--;
      ans.pb({i, i - 1});
    }
    // cout << i << " " << A[i] << " " << B[i] << en;
  }
  FOR(n)
  cout << i << " " << A[i] << " " << B[i] << en;
  cout << ans.size() << en;
  for (auto x : ans) {
    cout << x[0] << " " << x[1] << en;
  }
}

int main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
