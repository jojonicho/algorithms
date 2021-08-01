#include <bits/stdc++.h>

using namespace std;

int n, x;
int cnt;
long long m = 1e9 + 7;
string s;

const int M = 1e9 + 7;
const int N = 1000;
long long iv[N + 1], fact[N + 1], ifact[N + 1];

void pre() {
  iv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= N; i++) {
    iv[i] = M - M / i * iv[M % i] % M;
    fact[i] = fact[i - 1] * i % M;
    ifact[i] = ifact[i - 1] * iv[i] % M;
  }
}

long long mul(long long a, long long b) { return (((a % m) * (b % m)) % m); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  long long sum = 0;
  long long res = 1;
  while (scanf("%d", &x) != EOF) {
    res = res * ifact[x];
    if (res >= m) res -= m;
    sum += x;
  }
  for (int i = 1; i <= sum; i++) {
    res = res * i;
    if (res >= m) {
      res -= m;
    }
  }

  cout << res << endl;
}