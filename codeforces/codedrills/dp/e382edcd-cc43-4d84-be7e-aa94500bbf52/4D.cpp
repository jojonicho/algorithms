#include<bits/stdc++.h>
using namespace std;

#define ar array
#define en '\n'
#define all(x) (x).begin(), (x).end()

const int N = 5e3 + 5;

array<int, 3> A[N];
int prv[N];

int n, w, h;
int cw, ch;

int main() {
  cin >> n >> w >> h;
  int cnt = 0;
  for(int i=0; i<n; i++) {
    cin >> cw >> ch;
    if(cw <= w || ch <= h) continue;
    A[cnt] = {cw, ch, i};
    cnt++;
  }

  n = cnt;
  //auto cmp = [](array<int, 2> &x, array<int, 2> &y) {
  auto cmp = [](const auto &x, const auto &y) {
    if(x[0] == y[0]) return x[1] > y[1]; // because we always use the latest, best to keep the smallest as late as possible
    return x[0] < y[0];
  };
  sort(A, A+n, cmp);
  vector<ar<int, 2>> dp; // because w is sorted, just need to keep track of h
  
  int ans = 0, ansIdx = -1;

  memset(prv, -1, sizeof(prv));
  for(int i=0; i<n; i++) {
    ar<int,2> cur = {A[i][1], A[i][2]}, leq = {A[i][1], -1};
    int idx = lower_bound(all(dp), leq) - dp.begin();
    if(idx == dp.size()) {
      dp.push_back(cur);
      if(dp.size() > ans) {
        ans = dp.size(); 
        ansIdx = cur[1];
      }
    } else {
      dp[idx] = cur;
    }
    if(idx > 0) prv[cur[1]] = dp[idx-1][1];
  }

  cout << ans << en;

  vector<int> B;
  while(ansIdx != -1) {
    B.push_back(ansIdx);
    ansIdx = prv[ansIdx];
  }
  reverse(all(B));

  for(auto x: B) cout << x+1 << " ";
}
