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

const ll mnN = -2e14;
const ll mxN = 1e9;
ll n, m;

ll bin_search(vll &maxPref, ll v)
{
	ll lo = 0, hi = n - 1;
	while (lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;

		if (maxPref[mid] >= v)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return lo;
}

void solve()
{
	cin >> n >> m;
	ll cycle_sum = 0, maxPrefixSum = 0;
	vll A(n), maxPref(n, mnN);
	FOR(n)
	{
		cin >> A[i];
		cycle_sum += A[i];
		chmax(maxPrefixSum, cycle_sum);
		maxPref[i] = maxPrefixSum;
	}

	FOR(m)
	{
		int x;
		cin >> x;
		if (cycle_sum <= 0 && maxPrefixSum < x)
		{
			cout << -1 << " ";
			continue;
		}

		ll time = 0;
		if (maxPrefixSum < x)
		{																												 // x isn't reachable from 1 cycle
			time = (x - maxPrefixSum + cycle_sum - 1) / cycle_sum; // ceil(x - maxPrefixSum)
		}
		x -= time * cycle_sum;
		cout << time * n + bin_search(maxPref, x) << " ";
	}
	cout << en;
}
int main()
{
	fast;
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}