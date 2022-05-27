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

const int N = 205, M = 205;
const int dir[5] = {0, 1, 0, -1, 0};
const string YES = "YES", NO = "NO";

int A[N][M];

int n, m;

int main() {
  fast;
  cin >> n >> m;

  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) {
      cin >> A[i][j];
    }
  // dist of every same number must be even
  // (3, 3) 3 0 0 3 -> 0 -3 -3 0 -> 0 0 0 0
  pii missingCoor = {-1, -1};

  map<int, set<pii>> mp;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      int x = A[i][j];
      if(x == 0) continue;
      if(x == -1) {
        missingCoor = {i, j};
        continue;
      }
      bool found = 0;
      for(auto [r, c]: mp[x]) {
        if((abs(i - r) + abs(j - c) - 1) % 2 == 0) {
          mp[x].erase({r, c});
          found = 1;
          break;
        }
      }
      if(!found)
        mp[x].insert({i, j});
    }
  }

  debug() << im(missingCoor);
  debug() << im(mp);
  for(auto &[x, st]: mp) {
    if(st.empty()) mp.erase(x);
  }

  int sz = mp.size();
  if(sz == 0) {
    cout << YES << en;
    cout << 0;
    return 0;
  }
  if(sz != 1) {
    cout << NO;
    return 0;
  }

  //for(auto &[x, st]: mp) {
  auto [x, st] = *mp.begin();
  debug() << im(x) im(st);
    if((int)st.size() != 1) {
      cout << NO;
      return 0;
    }
    auto [r, c] = *st.begin();
    auto [i, j] = missingCoor;
    if((abs(i - r) + abs(j - c) - 1) % 2 == 0) {
      cout << YES << en;
      cout << x;
      return 0;
    }
  //}
  cout << NO;
}
