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
const ll mxN = 1 << 20;
ll arr[41], x[mxN], y[mxN];

void mitm(ll a[], int c, int n)
{
	FOR(i << n)
	{
		ll cur = 0;
		FOR(j, n)
		{
			if (i & (1 << j - 1))
			{
				cur += arr[j + c];
			}
		}
		a[i] = cur;
	}
}

int main()
{
	fast;
	ll n, k;
	cin >> n >> k;
	FOR(n)
	{
		cin >> arr[i];
	}
	mitm(x, 0, n / 2);
	mitm(y, n / 2, n - n / 2);
	ll nx = 1 << (n / 2), ny = 1 << (n - n / 2), ans = 0;
	sort(y, y + ny);
	for (int i = 0; i < nx; i++)
	{
		if (x[i] <= k)
		{
			ll cur = lower_bound(y, y + ny, k - x[i]) - y;
			if (cur == ny || y[cur] != (k - x[i]))
			{
				cur--;
			}
			chmax(ans, x[i] + y[cur]);
		}
	}
	cout << ans << en;
}