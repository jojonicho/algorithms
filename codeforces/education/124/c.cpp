#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

const int N = 2e5 + 5;
const int INF = 1e9 + 5;

//int A[N], B[N];

int n;

void solve() {
  cin >> n;
  vi A(n), B(n);
  for(int i=0; i<n; i++) cin >> A[i];
  for(int i=0; i<n; i++) cin >> B[i];

  // min of 2*n or circle
  ll circle = (ll)abs(A[0] - B[0]) + abs(A[n-1] - B[n-1]);
  
  sort(all(A));
  sort(all(B));
  //sort(A, A+n);
  //sort(B, B+n);

  auto f = [&](vi &A, vi &B) {

  //set<int> st;
  //map<int, int> mp;
  vector<pii> edges;

  ll ans = 0;
  for(int i=0; i<n; i++) {
    int x = A[i];

    //int idx = lower_bound(B, B+n, x) - B;
    int idx = lower_bound(all(B), x) - B.begin();
    int chosenIdx = -1;
    int chosenX = 0;

    int cur = INF;

    auto f = [&](int idx) {
      if(idx < n && idx >= 0 && abs(B[idx] - x) < cur) {
        int cost = abs(B[idx] - x);
        chosenIdx = idx;
        cur = cost;
        chosenX = B[idx];
      }
    };
    f(idx);
    f(idx-1);
    f(idx+1);

    if(chosenX < x) swap(x, chosenX);
    edges.pb({x, chosenX});

    ans += cur;
    //mp[chosenX]++;
  }

  for(int i=0; i<n; i++) {
    int x = B[i];

    //if(mp[x] > 0) {
      //mp[x]--;
      //continue;
    //}

    //int idx = lower_bound(A, A+n, x) - A;
    int idx = lower_bound(all(A), x) - A.begin();
    int chosenIdx = -1;
    int chosenX = 0;

    int cur = INF;

    auto f = [&](int idx) {
      if(idx < n && idx >= 0 && abs(A[idx] - x) < cur) {
        int cost = abs(A[idx] - x);
        chosenIdx = idx;
        cur = cost;
        chosenX = A[idx];
      }
    };
    f(idx);
    f(idx-1);
    f(idx+1);

    if(chosenX < x) swap(x, chosenX);
    edges.pb({x, chosenX});

    ans += cur;
  }

  map<int, int> cnt;
  for(int i=0; i<n; i++) {
    cnt[A[i]]++;
    cnt[B[i]]++;
  }
  
  ans = 0;
  vi notTakenIdx;
  int idx = 0 ;
  sort(all(edges));

  for(auto [x, y]: edges) {
    if(cnt[y] > 0 && cnt[x] > 0) {
      ans += abs(x-y);
      cnt[y]--;
      cnt[x]--;
    } else {
      notTakenIdx.pb(idx);
    }
    idx++;
  }

  for(auto idx: notTakenIdx) {
    auto [x, y] = edges[idx];
    if(cnt[x] > 0 || cnt[y] > 0) {
      ans += abs(x-y);
      cnt[x]--;
      cnt[y]--;
    }
  }
  return ans;
  };

  ll ans1 = f(A, B);
  ll ans2 = f(B, A);
  ll ans = min(ans1, ans2);
  cout << min(circle, ans) << en;
}

int main() {
  fast;
  int t; cin >> t;
  while(t--) solve();
}
