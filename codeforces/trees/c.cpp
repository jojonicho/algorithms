#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 1e9 + 5;
int P[N], S[N], A[N];
vector<int> G[N];

int n;
long long ans;
bool ok = 1;

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> P[i], P[i]--;
    G[P[i]].push_back(i);
  }

  P[0] = -1;
  for (int i = 0; i < n; i++) cin >> S[i];

  queue<int> q;
  q.push(0);

  ans = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    int parentS = (u ? S[P[u]] : 0);

    int mn = G[u].empty() ? parentS : INF;
    for (auto v : G[u]) {
      q.push(v);
      if (S[v] == -1) continue;
      mn = min(mn, S[v]);
    }

    if (S[u] == -1) {
      //   assert(mn != INF);
      S[u] = mn;
    }

    int cur = S[u] - parentS;
    ans += cur;
    if (u && S[u] < parentS) ok = 0;
  }

  if (!ok)
    cout << -1;
  else
    cout << ans;
}