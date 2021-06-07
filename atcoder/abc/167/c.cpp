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
#define fast                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

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
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<int>> a(n, vector<int>(m));
	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	int ans = 12345678;
	int all = 1 << n;
	for (int mask = 0; mask < all; mask++)
	{
		vi level(m);
		int cst = 0;
		for (int i = 0; i < n; i++)
		{
			// cout << mask << " " << i << " " << (mask >> i) << " " << ((mask >> i) & 1) << en;
			// mask >> i checks every i..n toggled or not
			if ((mask >> i) & 1) // last bit on same as odd
			{
				// cout << mask << " " << (mask >> i) << en;
				cst += c[i];
				// cout << c[i] << en;
				for (int j = 0; j < m; j++)
				{
					level[j] += a[i][j];
				}
			}
		}
		bool ok = 1;
		fork(j, m)
		{
			// cout << "eval for level " << j << ": " << level[j] << en;
			if (level[j] < x)
				ok = 0;
		}
		if (ok)
			ans = min(ans, cst);
	}
	if (ans == 12345678)
		cout << -1 << endl;
	else
		cout << ans << endl;
}

int main()
{
	fast;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}