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
  cin.tie(NULL);

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

/*
if WA:
  1. DON'T RETURN BEFORE READING ALL INPUT
  2. CHECK SMALL CASES (n == 1)
  3. CHECK ARRAY SIZE, dp[50], cout << dp[100]
*/

const int N = 1e5 + 5, S = 1e3+5;
const int X = 1001;

int n, s;

template <typename T, typename V> // T return type of operation, V type of input
struct Stack {
  vt<V> s;
  vt<T> sop;
  function<T (T, V)> f;
  Stack(T id, function<T (T, V)> f) : sop{id}, f(f) {}
 
  T op() {
    return sop.back();
  }
  void push(V x) {
    s.push_back(x);
    sop.push_back(f(op(), x));
  }
  V pop() {
    V x = s.back();
    s.pop_back();
    sop.pop_back();
    return x;
  }
  bool empty() {
    return s.empty();
  }
};
 
template <typename T, typename V>
struct Queue {
  Stack<T, V> s1, s2;
  function<T (T, V)> f;
  Queue(T id, function<T (T, V)> f) : s1(id, f), s2(id, f), f(f) {}
 
  void push(V x) {
    s2.push(x);
  };
  V pop() {
    if(s1.empty()) {
      while(!s2.empty()) {
        s1.push(s2.pop());
      }
    }
    return s1.pop();
  }
  bool empty() {
    return s1.empty() && s2.empty();
  }
  bool ok() {
    T bs1 = s1.op(), bs2 = s2.op();
    // how to determine that there is a subset inside segment [i, j] that has sum s?
    // using the two stacks
    for(int i=0; i<=s; i++)
      if(bs2[i] && bs1[s-i])
        return 1;
    return 0;
  }
};

bitset<X> add(bitset<X> x, int y) {
  // knapsack dp, for every reachable sum, add y to it
  return x |= x << y;
}

int main() {
  fast;
  cin >> n >> s;

  bitset<X> id;
  id.set(0);
  Queue<bitset<X>, int> q(id, add);

  int ans = n+1;
  int i=0;
  int x;
  for(int j=0; j<n; j++) {
    cin >> x;
    q.push(x);
    while(q.ok()) {
      ans = min(ans, j-i+1);
      q.pop();
      i++;
    }
  }

  if(ans == n+1)
    ans = -1;
  cout << ans << en;
}

