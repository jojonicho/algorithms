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
#define fast                     \
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
#define FOR(...)       \
	F_ORC(__VA_ARGS__) \
	(__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...)       \
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
bool mx = false;
bool div8(ll a[], int n)
{
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = ans * 10 + a[i];
	}
	if (ans > 2e5)
	{
		mx = true;
		return false;
	}
	return ans % 8 == 0;
}

int main()
{
	fast;
	ll n;
	cin >> n;
	if (n % 8 == 0)
	{
		cout << "Yes";
		return 0;
	}
	vll a;
	bool no = true;
	vi ending = {0, 8, 6, 4, 2};
	while (n)
	{
		ll x = n % 10;
		for (int i = 0; i < ending.size(); i++)
		{
			if (ending[i] == x)
			{
				no = false;
				break;
			}
		}
		a.pb(x);
		n /= 10;
	}
	if (no)
	{
		cout << "No";
		return 0;
	}
	ll arr[a.size()];
	copy(a.begin(), a.end(), arr);
	int len = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + len);

	do
	{
		if (arr[0] == 0)
			continue;
		if (div8(arr, len))
		{
			cout << "Yes";
			return 0;
		}
	} while (!mx && next_permutation(arr, arr + len));
	cout << "No";
	return 0;
}