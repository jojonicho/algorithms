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

ll power(ll a, ll b)
{
	int res = 1;
	while (b > 0)
	{
		if (b % 2)
			res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

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
	int n, score = 0;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		for (char c : s)
		{
			if (c == '(')
			{
				score++;
			}
			else
			{
				score--;
			}
			if (score < 0)
			{
				cout << "No" << en;
				while (n--)
				{
					string s;
					cin >> s;
				}
				return 0;
			}
		}
	}
	cout << "Yes" << en;
}