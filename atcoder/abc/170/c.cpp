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

int main()
{
	fast;
	int x, n;
	cin >> x >> n;
	vector<bool> a(n + 1, 0);
	if (n == 0)
	{
		cout << x << en;
		return 0;
	}
	forn
	{
		int t;
		cin >> t;
		if (t < 0)
			continue;
		a[t] = 1;
	}
	int ans, cur = 1e9 + 5;
	for (int i = x + n; i >= 0 && i >= x - n; i--)
	{
		if (a[i])
			continue;
		// cout << i << en;
		int dif = abs(i - x);
		if (dif <= cur)
		{
			cur = dif;
			ans = i;
		}
	}
	cout << ans << en;
}