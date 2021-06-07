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
ll n;

ll ask(ll lo, ll hi)
{
	if (lo == hi)
	{
		return -1;
	}
	cout << "? " << lo << " " << hi << en;
	cout.flush();

	ll ans;
	cin >> ans;
	return ans;
}

ll find_left(ll secondMaxIdx)
{
	ll lo = 1, hi = secondMaxIdx - 1;
	while (lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		if (ask(mid, secondMaxIdx) == secondMaxIdx)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	return hi;
}

ll find_right(ll secondMaxIdx)
{
	ll lo = secondMaxIdx + 1, hi = n;
	while (lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;

		if (ask(secondMaxIdx, mid) == secondMaxIdx)
		{
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	return lo;
}

int main()
{
	fast;
	cin >> n;
	ll secondMaxIdx = ask(1, n);

	ll ans;

	if (ask(1, secondMaxIdx) == secondMaxIdx)
		ans = find_left(secondMaxIdx);
	else
		ans = find_right(secondMaxIdx);
	cout << "! " << ans << endl;
}