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

const int N = 1e6;

int lpf[N+1];
vi primes;

void pre() {
  for(int i=2; i<=N; i++) {
    if(lpf[i] == 0) {
      lpf[i] = i;
      primes.pb(i);
    }

    for(auto p: primes) {
      if(lpf[i] < p || i*p > N)
        break;
      lpf[i*p] = p;
    }
  }
}

ll n;

vector<pii> primeFactorize(int x) {
  int prevP = lpf[x];
  vt<pii> res;

  int cnt = 0;
  while(x != 1) {
    int p = lpf[x];
    x /= p;

    if(p != prevP) {
      res.pb({prevP, cnt});
      cnt = 0;
      prevP = p;
    }
    cnt++;
  }

  res.pb({prevP, cnt});
  return res;
}


int main() {
  fast;
  pre();
  cin >> n;
  if(n == 1) {
    cout << 1 << " " << 0 << en;
    return 0;
  }

  // 20
  // 2^2 * 5 -> 10
  // 2^2 * 5^2 -> 100
  // 2 * 5 -> 10

  vt<pii> primeFacts = primeFactorize(n);
  ll target = 1;

  vi pws;
  for(auto [x, cnt]: primeFacts) {
    target *= x;
    pws.pb(cnt);
  }

  // 2^8 = 16*16
  // SQRT(2^8) = 2^4
  // 2^4 = 16
  //
  // 2^6 = 64
  // 2^3 = 8

  // 4 6
  // 2 3
  // 4 4
  // 2 2
  // 1 1

  int mx = *max_element(all(pws));

  int log2 = 0;
  ll pw = 1;
  while(pw < mx) {
    log2++;
    pw *= 2;
  }

  int ans = 1 + log2;
  if(count(all(pws), mx) == sz(pws) && mx == pw) {
    ans--;
  }

  cout << target << " " << ans << en;
}

