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

const int N = 2e5 + 5;
int n, l, r, x, q;

vi mp[N];

int main() {
  fast;
  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> x;
    mp[x].pb(i);
  }

  cin >> q;

  int l, r;
  while(q--) {
    cin >> l >> r >> x, l--, r--;

    auto &p = mp[x];
    int b = upper_bound(all(p), r) - p.begin() - 1;
    int a = lower_bound(all(p), l) - p.begin();
    cout << b - a + 1 << en;
  }
}


