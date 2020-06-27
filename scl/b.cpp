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

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	vector<int> b(n);
	forn
	{
		int t;
		cin >> t;
		a[i] = {t, i};
		b[i] = t;
	}
	sort(all(a));
	ll ans = 0;
	vector<bool> used(n, 0);
	int uses = 0;
	int i = 0;
	for (int i = 0; i < n && uses < k; i++)
	{
		int l = INT_MAX, r = INT_MAX;
		int id = a[i].second;
		if (!used[id])
		{
			ans += a[i].first;
			used[id] = 1;
			uses++;
		}
		if (id > 0 && !used[id - 1])
			l = b[id - 1];
		if (id != n - 1 && !used[id + 1])
			r = b[id + 1];
		if (l == INT_MAX && r == INT_MAX)
			continue;
		if (l >= r && l != INT_MAX)
		{
			used[id - 1] = 1;
			uses++;
		}
		else if (r > l && r != INT_MAX)
		{
			used[id + 1] = 1;
			uses++;
		}
	}
	cout << ans << en;
}

int main()
{
	fast;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}