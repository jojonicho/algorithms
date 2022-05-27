#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 5, K = 2e3 + 5;
const ll INF = 1e18 + 10;
int A[N], B[K];
ll dp[N][K];  // min distance up to i person and up to j key

int n, k, p;

ll go(int curN, int curK) {
  ll &ans = dp[curN][curK];
  if (ans != -1) return ans;

  if (curN == n) return 0;
  if (curK == k) return INF;
  // take vs no take
  ll cur = A[curN], target = B[curK];
  ll take = max(go(curN + 1, curK + 1), abs(cur - target) + abs(target - p));
  ll notake = go(curN, curK + 1);
  return ans = min(take, notake);
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> k >> p;

  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < k; i++) cin >> B[i];

  sort(A, A + n);
  sort(B, B + k);

  // 01 knapsack
  cout << go(0, 0);
}