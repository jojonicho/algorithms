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

const int N = 5e5;

ll iv[N + 1], fact[N + 1], ifact[N + 1];
ll nCk(int n, int k) { return fact[n] * ifact[k] % M * ifact[n - k] % M; }

void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

  for (int i = 2; i <= N; i++) {
    iv[i] = M - M / i * iv[M % i] % M;
    fact[i] = fact[i - 1] * i % M;
    ifact[i] = ifact[i - 1] * iv[i] % M;
  }
}

/*
TRIE
*/
struct TrieNode {
  TrieNode *children[27];
  int idx;
  TrieNode() {
    idx = 0;
    memset(children, 0, sizeof(children));
  }

  void insert(string word, int idx) {
    TrieNode *cur = this;
    for (char &c : word) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new TrieNode();
      }
      cur = cur->children[c - 'a'];
      cur->idx = idx;
    }
  }

  int find(string word) {
    TrieNode *cur = this;
    for (char c : word) {
      if (!cur->children[c - 'a']) {
        return -1;
      }
      cur = cur->children[c - 'a'];
    }
    return cur->idx;
  }
};

struct DSU {
  vi A;
  DSU(int n) : A(n, -1) {}

  int find(int x) {
    if (A[x] < 0) return x;
    return A[x] = find(A[x]);
  }

  bool is_same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;
    if (x > y) swap(x, y);
    if (A[x] > A[y]) swap(x, y);

    A[x] += A[y];
    A[y] = x;

    return true;
  }

  int size(int x) { return -A[find(x)]; }
};

/*
Let's call an array 𝑎 consisting of 𝑛 positive (greater than 0) integers
beautiful if the following condition is held for every 𝑖 from 1 to 𝑛: either
𝑎𝑖=1, or at least one of the numbers 𝑎𝑖−1 and 𝑎𝑖−2 exists in the array as well.

For example:

the array [5,3,1] is beautiful: for 𝑎1, the number 𝑎1−2=3 exists in the array;
for 𝑎2, the number 𝑎2−2=1 exists in the array; for 𝑎3, the condition 𝑎3=1 holds;
the array [1,2,2,2,2] is beautiful: for 𝑎1, the condition 𝑎1=1 holds; for every
other number 𝑎𝑖, the number 𝑎𝑖−1=1 exists in the array; the array [1,4] is not
beautiful: for 𝑎2, neither 𝑎2−2=2 nor 𝑎2−1=3 exists in the array, and 𝑎2≠1; the
array [2] is not beautiful: for 𝑎1, neither 𝑎1−1=1 nor 𝑎1−2=0 exists in the
array, and 𝑎1≠1; the array [2,1,3] is beautiful: for 𝑎1, the number 𝑎1−1=1
exists in the array; for 𝑎2, the condition 𝑎2=1 holds; for 𝑎3, the number 𝑎3−2=1
exists in the array. You are given a positive integer 𝑠. Find the minimum
possible size of a beautiful array with the sum of elements equal to 𝑠.

Input
The first line contains one integer 𝑡 (1≤𝑡≤5000) — the number of test cases.

Then 𝑡 lines follow, the 𝑖-th line contains one integer 𝑠 (1≤𝑠≤5000) for the
𝑖-th test case.

Output
Print 𝑡 integers, the 𝑖-th integer should be the answer for the 𝑖-th testcase:
the minimum possible size of a beautiful array with the sum of elements equal to
𝑠.
*/

void solve() {
  int n;
  cin >> n;
}

int main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
