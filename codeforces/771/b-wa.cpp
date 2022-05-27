#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

template <typename T>
struct binary_indexed_tree {
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N) : N(N), BIT(N + 1, 0) {}
  void add(int i, T x) {
    i++;
    while (i <= N) {
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i) {
    i++;
    T ans = 0;
    while (i > 0) {
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R) { return sum(R) - sum(L - 1); }
};
// sort(B, B + n);
// int r = unique(B, B + n) - B;

//int A[N], B[N], oddSuff[N], evenSuff[N]; 
int A[N], B[N];

int n;

void solve() {
  map<int, queue<int>> q;

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> A[i];
    B[i] = A[i];
  }
  if(is_sorted(A, A+n)) {
    cout << "YES" << '\n';
    return;
  }

  sort(B, B+n);
  binary_indexed_tree<int> ODD(n), EVEN(n);

  for(int i=n-1; i>=0; i--) {
    bool isOdd = A[i]&1;
    if(isOdd) ODD.add(i, 1);
    else EVEN.add(i, 1);
    //indexOf[B[i]] = i;
    q[B[i]].push(i);
  }

  bool ok = 1;
  for(int i=n-1; i>=0; i--) {
    int x = A[i];
    int idx = q[x].front(); q[x].pop();
    //int idx = indexOf[A[i]];
    bool isOdd = x&1;
    bool oddFlag = isOdd && idx > i && ODD.sum(i+1, idx) > 0;
    //bool oddFlag = isOdd && idx > i && oddSuff[i+1] - oddSuff[idx+1] > 0; 
    bool evenFlag = !isOdd && idx > i && EVEN.sum(i+1, idx) > 0;
    //bool evenFlag = !isOdd && idx > i && evenSuff[i+1] - evenSuff[idx+1] > 0;
    if(oddFlag || evenFlag) ok = 0;
    if(idx > i) {
      if(isOdd) ODD.add(idx-1, -1);
      else EVEN.add(idx-1, -1);
    }
    //oddSuff[i] = oddSuff[i+1] + isOdd;
    //evenSuff[i] = evenSuff[i+1] + !isOdd;
  }

  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
