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

const int M = 1e9 + 7, N = 60;  // 2^60 > 1e18

ll fact[N + 1];

ll binpow(ll a, ll b) {
  if (a == 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b /= 2;
  }
  return res;
}

ll iv(int x) { return binpow(x, M - 2); }

void pre() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= N; i++) {
    fact[i] = fact[i - 1] * i % M;
  }
}

int main() {
  pre();

  ll n;
  cin >> n;

  int atas = 0;
  ll ans = 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;

    int cnt = 0;
    while (n % i == 0) {
      // 2 * 2 * 3 = 12
      cnt++;
      n /= i;
    }
    if (cnt > 1) ans = (ans * iv(fact[cnt])) % M;
    atas += cnt;
  }
  // handle prime
  if (n > 1) atas++;
  ans = (ans * fact[atas]) % M;
  cout << ans;
  // atas! / bawah1! * bawah2!
  // combinatorics with repetition
}