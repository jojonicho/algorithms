#include <bits/stdc++.h>
using namespace std;

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

typedef long long ll;

const int N = 15;

const int MOD = 1e9 + 7;
ll iv[N + 1], fact[N + 1], ifact[N + 1];
ll nCk(int n, int k) { return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD; }

void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= N; i++) {
    iv[i] = MOD - MOD / i * iv[MOD % i] % MOD;
    fact[i] = fact[i - 1] * i % MOD;
    ifact[i] = ifact[i - 1] * iv[i] % MOD;
  }
}

int A[N], B[N];

string s, t;
int n, target, cur;

int main() {
  pre();
  cin >> s >> t;
  n = s.size();

  int qCnt = 0;
  for(int i=0; i<n; i++) {
    if(s[i] == '+') A[i] = 1;
    else A[i] = -1;
    target += A[i];

    if(t[i] == '+') B[i] = 1;
    else if(t[i] == '-') B[i] = -1;
    else qCnt++;
    cur += B[i];
  }

  for(int i=0; i<=qCnt; i++) {
    if(cur+i - (qCnt-i) == target) {
      cout << fixed << setprecision(18) << (nCk(qCnt, i) *1. / (1<<qCnt));
      return 0;
    }
  }
  cout << fixed << setprecision(18) << 0.;
}
