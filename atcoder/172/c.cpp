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
long long a[200004], b[200004];
int main()
{
	fast;
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	ll tot = 0;
	for (int i = 1; i <= n; i++)
	{
		ll t;
		cin >> t;
		tot += t;
		a[i] = a[i - 1] + t;
	}
	for (int i = 1; i <= m; i++)
	{
		ll t;
		cin >> t;
		tot += t;
		b[i] = b[i - 1] + t;
	}
	if (tot <= k)
	{
		cout << n + m << en;
		return 0;
	}
	for (int i = 0; i <= n; i++)
		if (k >= a[i])
		{
			int res = upper_bound(b + 1, b + 1 + m, k - a[i]) - b - 1;
			ans = max(ans, res + i);
		}
	cout << ans << en;
}