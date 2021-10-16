#include <bits/stdc++.h>

#include <atcoder/fenwicktree>
using namespace std;
using namespace __detail;
using namespace atcoder;

typedef long long ll;
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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

/** inversions => number of elements before it
 * that are greater than it
 **/

int main() {
  fast;
  int n;
  cin >> n;

  int A[n];
  fenwick_tree<ll> fw(n);
  ll ans = 0;
  FOR(n) {
    cin >> A[i];
    fw.add(A[i], 1);
    ans += fw.sum(A[i] + 1, n);
    // if fw[i+1]...fw[n] > 0 then there is A[j] > A[i] && j < i
  }

  FOR(n) {
    cout << ans << en;
    // ex: 3 2 1 0
    // moving 3 to back, ans = ans - 3 + (n-1) - 3
    ans = ans - A[i] + n - A[i] - 1;
  }
}