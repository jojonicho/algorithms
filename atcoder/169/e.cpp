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
	int n;
	cin >> n;
	vi a(n), b(n);
	forn
	{
		cin >> a[i] >> b[i];
	}
	sort(all(a));
	sort(all(b));
	// nth_element(a.begin(), a.begin() + n / 2, a.end());
	// nth_element(b.begin(), b.begin() + n / 2, b.end());
	// print(a);
	// print(b);
	int x, y;
	// find median
	// a[i] always < b[i]
	if (n % 2)
	{

		x = a[n / 2];
		y = b[n / 2];
	}
	else
	{
		// no need to /2 because range stays the same
		x = a[n / 2] + a[n / 2 - 1];
		y = b[n / 2] + b[n / 2 - 1];
	}
	// range = (max - min + 1)
	// cout << x << " " << y << en;
	cout << y - x + 1 << en;
	return 0;
}