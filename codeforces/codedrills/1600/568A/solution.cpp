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

if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

const int X = 1e7;

int lpf[X+1];
vi primes;

void sieve(int x) {
  for(int i=2; i<=x; i++) {
    if(lpf[i] == 0) {
      lpf[i] = i;
      primes.pb(i);
    }

    for(auto p: primes) {
      ll nxt = (ll) p * i;
      if(nxt > x || lpf[i] < p)
        break;
      lpf[nxt] = p;
    }
  }
}

bool is_palindrome(int x) {
  string s = to_string(x);
  string t = s;
  reverse(all(t));
  return s == t;
}

ll p, q;
int main() {
  fast;
  cin >> p >> q;

  int n = 2e6;
  sieve(n);

  for(int i=1; i<=1e9; i*=10) {
    dbg() << im(i) im((double)sqrt(i) / log2(i));
  }

  //dbg() << im(primes) im(sz(primes));

  int ans = -1;
  int prime = 0;
  int pal = 0;
  for(int i=1; i<=n; i++) {
    if(lpf[i] == i) {
      prime++;
    }
    if(is_palindrome(i)) {
      pal++;
    }
    if(q * prime <= p * pal)
      ans = i;
  }

  // q * prime <= p * pal
  // =
  // q * n / logn <= p * sqrt(n)
  // q * sqrt(n) <= p * logn
  // sqrt(n) / logn <= p / q
  // sqrt(n) / logn <= 42

  //dbg() << im(ans);
  //dbg() << im(prime) im(pal);

  if(ans == -1) {
    cout << "Palindromic tree is better than splay tree" << en;
    return 0;
  }
  cout << ans << en;
}

