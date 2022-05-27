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

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);

As part of your Day 1 Orientation at Amazon, you've been invited to participate
in a programming challenge. Please represent your team by completing the
following challenge:

Given an array of binary digits, 0 and 1, sort the array so that all zeros are
at one end and all the ones are at the other end. Which end does not matter. To
sort the array, swap any two adjacent elements. Determins the minimum number of
swaps to sort the array.

Example: arr[0, 1,0,1]

with 1 move, switching elements 1 and 2, yields [0,0,1,1], a sorted array.

Complete the function minMoves
input: int arr[n]
output: int: minimum number of moves necessary
*/

int main() {
  fast;
  int n;
  cin >> n;

  vi A(n);
  int nOnes = 0;
  FOR(n) {
    cin >> A[i];
    if (A[i] & 1) nOnes++;
  }
  int nZeros = n - nOnes;
  // try both configuration 000111 and 111000

  auto minSwitch = [&](bool isDecreasing = 0) {
    int ans = 0;
    // 010101
    // 000111
    int midPoint = isDecreasing ? nOnes : nZeros;
    int i = 0, j = midPoint;

    int LEFT_ELEM = isDecreasing ? 1 : 0;
    int RIGHT_ELEM = isDecreasing ? 0 : 1;

    while (i < midPoint) {
      while (A[i] == LEFT_ELEM) i++;
      while (A[j] == RIGHT_ELEM) j++;
      // move zero to left/right
      ans += j - i;
      i++;
      j++;
    }
    return ans;
  };

  cout << min(minSwitch(0), minSwitch(1));
}