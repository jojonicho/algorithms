#include <bits/stdc++.h>

#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py d.cpp

using namespace std;
using namespace atcoder;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
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
const int N = 8;
const int M = 2 * N - 1;
  set<ll> st;
  map<ll, ll> mp;
  //ll B[M];
  vll B(M);

  vll A[M];

  int n, m;
  ll ans;
void dfs(int idx) {
    if(idx == m) {
      // check the pairs
      ll cur = 0;
      for(int i=0; i<m; i++) cur ^= B[i];
      debug() << imie(B);
      debug() << imie(st);
      ans = max(ans, cur);
      return;
    }
    if(st.count(idx)) {
        dfs(idx+1);
        return;
    }
    for(int i=0; i<m-idx; i++) {
      if(st.count(idx+i+1)) continue;
      B[idx] = A[idx][i];
      st.insert(idx+i+1);
      dfs(idx+1);
      B[idx] = 0;
      st.erase(idx+i+1);
    }
    //dfs(idx + 1);
  }

int main() {
  fast;
  // bitmask
  cin >> n;
  //int MASK = 1 << n;
  
  //for(int mask=0; mask<MASK; mask++) {

  //}
  //while (1) {
    //bool ok2 = 1;
    //for (int i = 0; i < n; i++)
      //for (int j = 0; j < n; j++)
        //if (G[i][j] ^ H[P[i]][P[j]]) ok2 = 0;

    //if (ok2) {
      //ok = 1;
      //break;
    //}
    //if (!next_permutation(all(P))) break;
  //}
  m = 2*n-1;
  for(int i=0; i<m; i++) {
    A[i] = vector<ll>(m-i);
    for(int j=0; j<m-i; j++) cin >> A[i][j];
    debug() << imie(A[i]);
  }

  dfs(0);
  //for(int i=0; i<m; i++) {

  //}
  cout << ans;
}
