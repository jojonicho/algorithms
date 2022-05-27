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
const int N = 10005;
const string YES = "YES", NO = "NO";

int C[N], c;
ar<int,2> A[N];

int main() {
  fast;
  int n;
  cin >> n;

  auto cmp = [&](ar<int, 2> x, ar<int,2> y) {
    if(x[1] == y[1]) return x[0] < y[0];
    return x[1] > y[1];
  };

  set<ar<int, 2>, cmp> st; // C[i], freq
  for(int i=1; i<=n; i++) {
    cin >> c;
    st.insert({i, c});
    //st.insert({c, i});
  }
  
  int last = -1;

  while((int)st.size() >= 2) {
    debug() << im(st);
    auto [x, cntX] = *st.begin();
    st.erase(st.begin());
    auto it = st.end();
    it--;
    auto [y, cntY] = *it;
    st.erase(it);

    // y x y x y
    int mn = min(cntX, cntY);
    last = x;
    cntX -= mn; cntY -= mn;
    if(cntX) st.insert({x, cntX});
    if(cntY) st.insert({y, cntY});

    debug() << im(x) im(y);
  }

  debug() << im(st) im(last);
  if(st.empty()) {
    cout << YES;
    return 0;
  }
  auto [x, cnt] = *st.begin();
  if(cnt > 1) {
    cout << NO;
    return 0;
  }
  if(last == -1) {
    cout << YES;
    return 0;
  }
  // last is in even position
  // last < x
  cout << (last < x ? YES : NO);


  //if(n==1) {
    //cout << YES;
    //return 0;
  //}

  //map<int, int> mp;
  //for(int i=1; i<=n; i++) mp[i] = A[i];

  //for(int i=1; i<=n; i++) {
  ////for(auto [x, cnt]: mp) {
    //int x = i, cnt = C[i];
    //bool isEven = x % 2 == 0;
    //if(isEven) {
      ////bool ok = A[i-1] > A[i];
    //} else {
      ////bool ok = A[i-1] < A[i];
    //}
  //}
  //cout << YES;
}
