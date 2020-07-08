#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define fork(i, n) for (ll i = 0; i < (n); i++)
#define forn for (ll i = 0; i < (n); i++)
#define fori(i, k, n) for (ll i = k; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back
#define fast                     \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL);

template <typename A, typename B>
inline void chmin(A &a, B b)
{
	if (a > b)
		a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b)
{
	if (a < b)
		a = b;
}
template <typename T>
void print(vector<T> &a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template <typename T>
void print(deque<T> &a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template <typename T>
void print(vector<vector<T>> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << en;
	}
}
const int mxn = 5e5;
const int M = 1e9 + 7;

ll pw(ll b, ll e)
{
	ll res = 1;
	while (e)
	{
		if (e % 2)
			res = (res * b) % M;
		b = (b * b) % M;
		e >>= 1; // e/=2;
	}
	return res;
}

ll iv[mxn + 1], f1[mxn + 1], f2[mxn + 1];
ll nck(int n, int k)
{
	return f1[n] * f2[k] % M * f2[n - k] % M;
}

int main()
{
	fast;
	iv[1] = 1;
	for (int i = 2; i <= mxn; ++i)
		iv[i] = M - M / i * iv[M % i] % M;
	f1[0] = f2[0] = 1;
	for (int i = 1; i <= mxn; ++i)
	{
		f1[i] = f1[i - 1] * i % M;
		f2[i] = f2[i - 1] * iv[i] % M;
	}
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		ll c = i & 1 ? M - 1 : 1;
		c = c * nck(n, i) % M * nck(m, i) % M * f1[i] % M * nck(m - i, n - i) % M * nck(m - i, n - i) % M * f1[n - i] % M * f1[n - i] % M;
		ans = (ans + c) % M;
	}
	cout << ans;
}