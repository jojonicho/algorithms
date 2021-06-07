#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

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

/*
sum = xor product of entire element
if sum == 0, YES
else we need to check if sum occurs 3 times or more

ex: sum = 6
(brackets noting the xor product of a subsequence)
valid -> [6] [6] [6] -> 6
not valid -> [6] [0] -> 6 (sum == 6 but only appear once)

actually we only need to check if sum appears 2 times or more, because if it
appears 2 times, i claim that it will always appear 3 times or more, because of
the known fact that it's final xor product will be sum, so it will eventually
meet another A[i] with A[i] = sum

Time Complexity: O(N)
*/

void solve() {
  ll n;
  cin >> n;
  int pre[n + 1] = {};
  int A[n + 1];

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    A[i] = x;
    sum ^= x;
    pre[i] = sum;
  }

  if (!sum) {
    cout << "YES" << en;
    return;
  } else {
    int cur = 0, cnt = 0;
    for (int i = 1; cnt <= 1 && i <= n; i++) {
      cur ^= A[i];
      if (cur == sum) {
        cnt++;
        cur = 0;
      }
    }
    if (cnt >= 2) {
      cout << "YES" << en;
      return;
    }
  }
  cout << "NO" << en;
}
int main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}