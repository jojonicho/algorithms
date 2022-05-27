#include<bits/stdc++.h>
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

#define pb push_back
#define en '\n'

typedef vector<int> vi;

const int N = 1e5 + 5;

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

vi G[N];

int n, m;
int u, v;

int main() {
  cin >> n >> m;
  DSU dsu(n);

  int ans = n - 1;

  while(m--) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
    if(dsu.join(u, v)) ans--;
  }

  cout << ans << en;
  set<int> components;
  for(int i=0; i<n; i++) {
    components.insert(dsu.find(i));
  }
  vector<int> A(components.begin(), components.end());
  int sz = A.size();
  for(int i=1; i<sz; i++) cout << A[i-1]+1 << " " << A[i]+1 << en;
}
