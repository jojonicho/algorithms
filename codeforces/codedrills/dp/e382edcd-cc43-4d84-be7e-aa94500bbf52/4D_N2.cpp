#include<bits/stdc++.h>
using namespace std;

#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<( \
            c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) cerr << boolalpha << i;
  ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
  sim dor(const c &) { ris; }
#endif
}
;
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y <<
// ")"; return dd; }

#define ar array
#define en '\n'
#define all(x) (x).begin(), (x).end()

const int N = 5e3+5;

ar<int, 3> A[N];
int prv[N];
int dp[N];

int n, w, h;
int cw, ch;

int main() {
  cin >> n >> w >> h;
  for(int i=0; i<n; i++) {
    cin >> cw >> ch;
    A[i] = {cw, ch, i};
  }

  auto cmp = [](const auto &x, const auto &y) {
    if(x[0] == y[0]) return x[1] > y[1];
    return x[0] < y[0];
  };
  sort(A, A+n, cmp);

  memset(prv, -1, sizeof(prv));

  int ans = 0, ansIdx = -1;

  for(int i=0; i<n; i++) {
    auto x = A[i];
    if(x[0] <= w || x[1] <= h) continue;
    dp[i] = 1;
    if(dp[i] >= ans) {
      ans = dp[i];
      ansIdx = i;
    }
    for(int j=0; j<i; j++) {
      auto y = A[j];
      if(x[0] <= y[0] || x[1] <= y[1]) continue;
      if(dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        if(dp[i] >= ans) {
          ans = dp[i];
          ansIdx = x[2];
        }
        debug() << im(i) im(dp[i]);
        prv[x[2]] = y[2];
      }
    }
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
