#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int A[N], prv[N], nxt[N], last[N];

int n;

bool is_unique(int i, int l, int r) {  // A[i] is unique for A[l..r]
  return prv[i] < l && nxt[i] > r;
}

bool check(int l, int r) {
  if (l >= r) return true;

  int idx = -1;
  for (int i = 0; idx == -1 && i <= (r - l) / 2; i++) {
    if (is_unique(l + i, l, r)) {
      idx = l + i;
    }
    if (is_unique(r - i, l, r)) {
      idx = r - i;
    }
  }
  if (idx == -1) return false;
  return check(l, idx - 1) && check(idx + 1, r);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; i++) {
    int x = A[i];
    prv[i] = last[x];
    last[x] = i;
  }

  for (int i = 0; i < N; i++) last[i] = n;
  for (int i = n - 1; i >= 0; i--) {
    int x = A[i];
    nxt[i] = last[x];
    last[x] = i;
  }

  cout << (check(0, n - 1) ? "YES" : "NO");
}