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
#define sz(x) (int)(x).size()
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
dbg() << imie(k) imie(x) imie(row) imie(col);
 *
 * p = [a, b, c, d]
 *
 * q = identity permutation
 * q = [1,2,3,4]
 *
 * q'[i] = q[p[i]]
 *
 * tc
 * q = [1,2,3,4]
 * ? 3
 * ans = 3
 * q'= [ q[p[1]], q[p[2]], q[p[3]], q[p[4]] ]
 *
 * ? 2
 * q'= 
*/

int ans;
int res;

int ask(int x) {
  cout << "? " << x << endl;
  cin >> res;
  return res;
}

void solve() {
  //vi P = {{4, 3, 2, 1}};
  //vi P = {{1, 2, 3, 4}};
  //vi P = {{4, 2, 1, 3}};
  //vi P = {{1, 3, 4, 2}};

  //vi Q = {{1, 2, 3, 4}};

  //int n = sz(P);
  //vi R(n);

  //while(next_permutation(all(P))) {
    //dbg() << im(P);
    //while(1) {
      //for(int i=0; i<n; i++) {
        //R[i] = Q[P[i]-1];
      //}
      //Q = R;
      //dbg() << im(Q);
      //if(is_sorted(all(Q))) break;
    //}
  //}

  int n;
  cin >> n;

  vi P(n, -1);
  ans = -1;
  int prev=0;

  for(int i=0; i<n; i++) {
    if(P[i] != -1) continue;
    prev = ask(i+1);
    prev--;
    while(P[prev] == -1) {
      int cur = ask(i+1); cur--;
      P[prev] = cur;
      prev = cur;
    }
  dbg() << im(P);
  }

  cout << "! ";
  FOR(n) {
    if(P[i] == -1) P[i] = i;
    cout << P[i] + 1 << " ";
  }
  cout << endl;
}

int main() {
  fast;
  int t; cin >> t;
  while(t--) solve();
}

