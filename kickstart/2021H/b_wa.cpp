#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

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

unordered_map<char, int> mp;  // level
unordered_map<char, vector<vector<char>>> composition;
unordered_map<char, vector<vector<char>>> ban;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  n = unique(all(s)) - s.begin();
  s.resize(n);

  vi cost(n);
  FOR(n) {
    cost[i] = mp[s[i]];
    ans += cost[i];
  }
  debug() << imie(cost);

  vi last(128, -1);

  FOR(n) {
    char c = s[i];
    bool ok = 0;

    for (auto compositionList : composition[c]) {
      bool cur = 1;
      for (auto d : compositionList) {
        if (last[d] == -1) cur = 0;
        for (auto banlist : ban[c]) {
          for (char e : banlist)
            if (last[e] > last[d]) cur = 0;
        }
      }
      ok |= cur;
    }
    if (ok) cost[i] -= 1;
    last[c] = i;
  }

  last = vector<int>(128, n);
  for (int i = n - 1; i >= 0; i--) {
    char c = s[i];
    bool ok = 0;

    for (auto compositionList : composition[c]) {
      bool cur = 1;
      for (auto d : compositionList) {
        if (last[d] == n) cur = 0;
        for (auto banlist : ban[c]) {
          for (char e : banlist)
            if (last[e] > last[d]) cur = 0;
        }
      }
      ok |= cur;
    }
    last[c] = i;
  }

  //   debug() << imie(composition);
  cout << accumulate(all(cost), 0) << en;
}

void setup() {
  mp['U'] = 0;
  mp['R'] = 1;
  mp['Y'] = 1;
  mp['B'] = 1;
  mp['O'] = 2;
  mp['P'] = 2;
  mp['G'] = 2;
  mp['A'] = 3;

  composition['G'] = {{'B', 'Y'}};
  composition['O'] = {{'R', 'Y'}};
  composition['P'] = {{'R', 'B'}};
  composition['A'] = {{'R', 'G'}, {'Y', 'P'}, {'B', 'O'}};

  ban['G'] = {{'R', 'O', 'P', 'A'}};
  ban['O'] = {{'B', 'G', 'P', 'A'}};
  ban['P'] = {{'Y', 'G', 'O', 'A'}};  // we cannot extend from these colors

  ban['A'] = {composition['G'][0], composition['P'][0], composition['O'][0]};
}

int main() {
  fast;
  setup();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}