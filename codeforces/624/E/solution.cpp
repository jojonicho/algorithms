#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define vt vector
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back

#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);

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

#define sim template <class c
#define ris return *this
#define dor > dbg &operator<<
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, dbg &>::type operator<<( \
            c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct dbg {
#ifdef LOCAL
  ~dbg() { cerr << endl; }
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
};

#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/*
if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

int n, d;
void solve() {
  cin >> n >> d;

  vt<int> A(n+1, 1);

  int sum = n * (n-1) / 2 - d;
  
  for(int i=2, j=n; sum>0 && i<j; j--) {
    // sum + i - j < 0 means that we only need to move this node, and then we're done
    while(i<j && A[i] == A[i-1] * 2) // no more than two children
      i++;
    if(sum + i - j < 0)
      i = j-sum;

    if(i>=j)
      break;

    sum -= j-i;

    A[i]++;
    A[j]--;
  }

  if(sum != 0) {
    cout << "NO" << en;
    return;
  }

  cout << "YES" << en;
  queue<ar<int, 3>> q; // node, capacity
  int node=1;
  q.push({node++, 2, 1});

  for(int i=2; !q.empty() && i<=n; i++) {
    while(!q.empty() && get<2>(q.front()) != i-1)
      q.pop();
    if(q.empty())
      break;

    auto u = q.front(); q.pop();
    for(int j=0; j<A[i]; j++) {
      if(get<1>(u) == 0) {
        u = q.front(); q.pop();
      }

      auto &[p, c, l] = u;
      cout << p << " ";
      q.push({node++, 2, i});
      c--;
    }
  }

  cout << en;
}

int main() {
  fast;
  int t; cin >> t;
  while(t--)
    solve();
}

