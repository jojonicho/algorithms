#include <bits/stdc++.h>

//#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py a.cpp

using namespace std;
//using namespace atcoder;
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

const int N = 1e3 + 5;

int G[N][N];

int n;
char c;

int prefH[N][N], prefV[N][N], prefD[N][N], prefD2[N][N];

int main() {
  fast;
  cin >> n;
  int m = n;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> c;
      int x = c == '#';
      G[i][j] = x;
      prefH[i][j] = prefH[i][j-1] + x;
    }
  }

  for(int j=1; j<=m; j++) {
    int i = 1;
    for(int k=0; j+k<=m; k++) {
      int i2 = i + k, j2 = j+k;
      int x = G[i2][j2];
      prefD[i2][j2] = prefD[i2-1][j2-1] + x;
    }
  }

  for(int i=2; i<=n; i++) {
    int j = 1;
    for(int k=0; i+k<=n; k++) {
      int i2 = i + k, j2 = j+k;
      int x = G[i2][j2];
      prefD[i2][j2] = prefD[i2-1][j2-1] + x;
    }
  }

// other diag

  for(int j=1; j<=m; j++) {
    int i = 1;
    for(int k=0; i+k<=n && j-k>0; k++) {
      int i2 = i + k, j2 = j-k;
      debug() << im(i2) im(j2);
      int x = G[i2][j2];
      prefD2[i2][j2] = prefD2[i2-1][j2+1] + x;
    }
  }

  for(int i=2; i<=n; i++) {
    int j = m;
    for(int k=0; i+k <= m && j-k > 0; k++) {
      int i2 = i + k, j2 = j-k;
      //debug() << im(i2) im(j2);
      int x = G[i2][j2];
      prefD2[i2][j2] = prefD2[i2-1][j2+1] + x;
    }
  }


  for(int j=1; j<=m; j++) {
    for(int i=1; i<=n; i++) {
      int x = G[i][j];
      prefV[i][j] = prefV[i-1][j] + x;
    }
  }

  bool ok = 0;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      // i, j be the endpoint
      // choose 2
      if(i >= 6) {
        int v = prefV[i][j] - prefV[i-6][j];
        if(v >= 4) ok = 1;
      }
      
      if(j >= 6) {
        int h = prefH[i][j] - prefH[i][j-6];
        if(h >= 4) ok = 1;
      }

      if(i >= 6 && j >= 6) {
        int d = prefD[i][j] - prefD[i-6][j-6];
        if(d >= 4) ok = 1;
      }
      if(i >= 6 && j + 5 <= m) {
        int d2 = prefD2[i][j] - prefD2[i-6][j+6];
        if(d2 >= 4) ok = 1;
      }
    }
  }

  cout << (ok ? "Yes" : "No");
}
