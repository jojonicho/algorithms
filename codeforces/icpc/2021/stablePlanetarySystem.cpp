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
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
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
*/

const int N = 2e5 + 5;
const int HALF_ROTATION = 180000;

int R[N], theta[N], T[N];

int n;
double ans;
vector<pair<double, double>> A;

double getDist(double x, double y, double a, double b) {
  double distX = x-a;
  double distY = y-b;
  return sqrt(distX * distX + distY * distY);
}


void go(int l, int r) {
  if(l == r) return ; // no pair for [l, l]
  int mid = l + (r-l) / 2;
  go(l, mid);
  go(mid+1, r);

  vector<pair<double, double>> strip;
  auto [x, y] = A[mid];

  for(int i=l; i<=r; i++) {
    auto [a, b] = A[i];
    //debug() << im(x) im(a) im(abs(x-a));
    if(abs(x-a) < ans) {
      strip.pb({b, a}); // sort by y coordinate
    }
  }

  sort(all(strip));
  int sz = strip.size();

  // O(n), reference from https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
  // check at most 7 points
  for(int i=0; i<sz; i++) {
    auto [y, x] = strip[i];
    for(int j=i+1; j<sz; j++) {
      auto [b, a] = strip[j];
      if(b-y >= ans) break;
      double curAns = getDist(x, y, a, b);
      ans = min(ans, curAns);
    }
  }
}

double degToRad(int deg) {
  // Because a full rotation equals 2*pi radians
  // one degree is equivalent to pi/180 radians. 
  return deg * M_PI / HALF_ROTATION;
}

int main() {
  fast;
  cin >> n;

  map<int, int> mp;
  bool collision = 0;
  for(int i=0; i<n; i++) {
    cin >> R[i] >> theta[i] >> T[i];

    if(mp.find(R[i]) == mp.end()) mp[R[i]] = T[i];
    if(T[i] != mp[R[i]]) collision = 1;

    // transform to x y coordinates
    // Convert θ from degrees to radian as θ(in radian) = θ (in degrees) * (3.14159 / 180).
    // one degree is equivalent to pi/180 radians. 

    double rad = degToRad(theta[i]);
    double x = R[i] * cos(rad);
    double y = R[i] * sin(rad);
    A.pb({x, y});
  }

  if(collision) {
    cout << 0;
    return 0;
  }

  sort(all(A));
  ans = INT_MAX;
  go(0, n-1);

  for(auto it = mp.begin(); it != prev(mp.end()); it++) {
    auto nxt = next(it);
    auto t1 = (*it).second;
    auto t2 = (*nxt).second;
    if(t1 == t2) continue;
    ans = min(ans, (double) (*nxt).first - (*it).first);
  }

  cout << fixed << setprecision(12) << ans;
}
