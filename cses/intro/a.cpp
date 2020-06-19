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

const int mod = 1e9 + 7;

ll pw(ll b, ll e)
{
	ll res = 1;
	while (e)
	{
		if (e % 2)
			res = (res * b) % mod;
		b = (b * b) % mod;
		e >>= 1; // e/=2;
	}
	return res;
}

ll fact[200005], inv[200005];
ll C(ll n, ll k)
{
	return (((fact[n] * inv[k]) % mod) * inv[n - k]) % mod;
}

int main()
{
	fast;
	ll n;
	cin >> n;
	while (n > 1)
	{
		cout << n << " ";
		if (n % 2)
			n = n * 3 + 1;
		else
			n /= 2;
	}
	cout << "1" << en;
}