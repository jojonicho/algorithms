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

#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int A[N], prv[N];

int n;

int main() {
  memset(prv, -1, sizeof(prv));
  cin >> n;
  for(int i=0; i<n; i++) cin >> A[i];
  
  map<int, int> mp, dp;

  int ans = 0, ansIdx = -1;
  for(int i=0; i<n; i++) {
    int x = A[i];
    if(dp[x-1] + 1 >= dp[x]) {
      dp[x] = dp[x-1] + 1;
      if(i && mp.find(x-1) != mp.end())
        prv[i] = mp[x-1];
    }
    if(dp[x] > ans) {
      ansIdx = i;
      ans = dp[x];
    }
    mp[x] = i;
  }

  cout << ans << '\n';
  //debug() << im(ansIdx);
  vector<int> B;
  while(ansIdx != -1) {
    B.push_back(ansIdx);
    ansIdx = prv[ansIdx];
  }

  reverse(all(B));
  for(auto x: B) cout << x + 1 << " ";
}
