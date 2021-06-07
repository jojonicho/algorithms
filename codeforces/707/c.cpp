#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back
#define fast                   \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL);
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)     \
	F_ORC(__VA_ARGS__) \
	(__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...)     \
	E_ACHC(__VA_ARGS__) \
	(__VA_ARGS__)

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

pair<int, int> mp[5000001];

int main()
{
	fast;

	for (int i = 1; i <= 5000000; i++)
	{
		mp[i] = {-1, -1};
	}

	int n;
	cin >> n;

	vll A(n);
	FOR(n)
	{
		cin >> A[i];
	}

	// map<ll, pair<ll, ll>> mp;

	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			ll sum = A[i] + A[j];
			// if (mp.find(sum) != mp.end())
			if (mp[sum].first != -1)
			{
				auto prev = mp[sum];
				ll first = prev.first, second = prev.second;
				if (first != i && second != i && first != j && second != j)
				{
					cout << "YES" << en;
					cout << i + 1 << " " << j + 1 << " " << first + 1 << " " << second + 1 << en;
					return 0;
				}
			}
			else
			{
				mp[sum] = {i, j};
			}
		}
	}
	cout << "NO" << en;
}