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
*/

int n, k;
void solve() {
  cin >> n >> k;
  // go to the lowest bank note, i
  // if k * 10^(A_i) > 1 * 10^(A_i+1) go to the next
  // until a * A_i + b * A_i+1 + ... + 1 is not reachable

  vt<ll> A(n);
  ll pw = 1;
  ll cnt = 0;
  FOR(n) {
    ll x;
    cin >> x;
    A[i] = pw;
    while(cnt < x) {
      A[i] *= 10;
      pw *= 10;
      cnt++;
    }
  }
  //dbg() << im(A);

  vi C(n);
  C[0] = k;

  //dbg() << im(C) im(n);
  bool flag = 1;

  for(int i=1; i<n; i++) {
    // we know A[i] % A[i-1] == 0
    // only question is if there is enough bank notesh=
    // C[0] = 13
    // A[1] = 10, A[0] = 1;

    int c = A[i] / A[i-1]; // how many of previous note needed to make tot his note
    // 1000
    // 1
    //if(C[i-1]
    //dbg() << im(c) im(C[i-1]);

    if(C[i-1] + flag < c) {
      flag = 0;
      break;
    }

    int kPrev = c - 1 - (flag);
    int kNow = C[i-1] - kPrev;
    C[i-1] = kPrev;
    C[i] = kNow;

    flag = 0;
    assert(C[i-1] + flag < c);
  }
  //dbg() << im(C);

  ll ans = 0;
  FOR(n) {
    ans += A[i] * C[i];
  }
  cout << ans + 1 << en;
}

int main() {
  fast;
  int t;
  cin >> t;
  while(t--)
    solve();
}

