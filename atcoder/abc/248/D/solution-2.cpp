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

/*
DEBUG: -D LOCAL
dbg() << imie(k) imie(x) imie(row) imie(col);
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 1;

int n, q, x, A[N];

template <typename T>
struct SegTree {
  ordered_set<T> tree[4 * N];

  void build(int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].insert(A[l]);
      return;
    }
    int m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);

    if(sz(tree[2*i]) < sz(tree[2*i+1])) {
      tree[i] = tree[2*i+1];
      for(auto &x: tree[2*i])
        tree[i].insert(x);
    } else {
      tree[i] = tree[2*i];
      for(auto &x: tree[2*i+1])
        tree[i].insert(x);
    }
  }

  T qry(int a, int b, T x, int i = 1, int l = 1, int r = n) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[i].order_of_key(x);
    int m = (l + r) / 2;
    return qry(a, b, x, i * 2, l, m) + qry(a, b, x, i * 2 + 1, m + 1, r);
  }
};
SegTree<int> seg;

int main() {
  fast;
  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> A[i];
  }

  seg.build();
  cin >> q;

  int l, r;
  while(q--) {
    cin >> l >> r >> x;

    cout << seg.qry(l, r, x+1) - seg.qry(l, r, x) << en;
  }
}


