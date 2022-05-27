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

// mo algorithm

const int N = 2e5 + 5;

int A[N], B[N], C[N];
int cnt[N], cur;

int sq;
int n, q;
int m;

struct Query {
  int l, r, idx;
  bool operator<(Query b) {
    if(l/sq == b.l/sq) // same block
      return r < b.r;
    return l < b.l;
  };
};

void add(int i) {
  int idx = C[i];
  int &c = cnt[idx]; // coordinate compress this
  if(c == 0)
    cur++;
  c++;
}

void remove(int i) {
  int idx = C[i];
  int &c = cnt[idx];
  c--;
  if(c == 0)
    cur--;
}

// for A[i] <= 1e9
void coord_compression() {
  sort(B, B+n);
  m = unique(B, B+n) - B;
  FOR(n) {
    int x = A[i];
    int idx = lower_bound(B, B+m, x) - B;
    C[i] = idx;
  }
}


int main() {
  fast;
  cin >> n >> q;
  sq = sqrt(n);

  FOR(n) {
    cin >> A[i], A[i]--;
    B[i] = A[i];
  }

  // move to main
  coord_compression();
  vt<Query> queries(q);
  FOR(q) {
    cin >> queries[i].l >> queries[i].r, queries[i].l--, queries[i].r--;
    queries[i].idx = i;
  }

  sort(all(queries));
  int l = 0, r = -1; cur = 0; // curLeft, curRight, curAns
  vt<int> ans(q);
  for(auto qq: queries) {
    while(l > qq.l) add(--l);
    while(r < qq.r) add(++r);
    while(l < qq.l) remove(l++);
    while(r > qq.r) remove(r--);
    ans[qq.idx] = cur;
  }
  // endmove

  for(auto x: ans)
    cout << x << en;
}

