#include <bits/stdc++.h>

#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py c.cpp

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

const int M = 1e9 + 7;

int mul(const int v1, const int v2) { return (int)((1LL * v1 * v2) % M); }

int mod_pow(int a, int p) {
  int res = 1;
  while (p != 0) {
    if (p & 1) res = mul(res, a);
    p >>= 1;
    a = mul(a, a);
  }
  return res;
}

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);

The i-th line should contain the ID number of the player who ranks i-th at the
end of the M-th round.


*/

const char R = 'G', P = 'P', S = 'C';
char A[105][105];

auto cmp = [](ar<int, 2> x, ar<int, 2> y) {
  if (x[0] == y[0]) {
    return x[1] < y[1];
  }
  return x[0] > y[0];
};

int main() {
  fast;
  int n, m;  // 2n players, m rounds
  cin >> n >> m;

  ar<int, 2> standings[2 * n];  // nWins, idx;
  // vector<ar<int, 2>> standings(2 * n);  // nWins, idx;

  FOR(2 * n) {
    standings[i] = {0, i};
    FOR(j, m) { cin >> A[i][j]; }
  }

  auto play = [&](int rank1, int rank2, int roundNumber) {
    int player1 = standings[rank1][1];
    int player2 = standings[rank2][1];

    char move1 = A[player1][roundNumber];
    char move2 = A[player2][roundNumber];
    if (move1 == move2) return -1;
    if (move1 == P && move2 == R || move1 == R && move2 == S ||
        move1 == S && move2 == P)
      return rank1;
    return rank2;
  };

  // i=0 -> id = 1 vs id = 2

  for (int i = 0; i < m; i++) {           // roundNumber
    for (int j = 0; j < 2 * n; j += 2) {  // rank
      int winnerRank = play(j, j + 1, i);
      if (winnerRank == -1) continue;

      standings[winnerRank][0]++;
    }
    sort(standings, standings + 2 * n, cmp);
  }

  for (auto [x, y] : standings) {
    cout << y + 1 << en;
  }
}