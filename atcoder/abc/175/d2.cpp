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

const ll INF = 1e18;

int main()
{
	fast;
	int n, k;
	cin >> n >> k;
	vi P(n), C(n);
	for (auto &p : P)
	{
		cin >> p;
		p--;
	}
	for (auto &c : C)
	{
		cin >> c;
	}

	ll ans = -INF;

	FOR(n)
	{
		ll cycle_sum = 0;
		int cycle_len = 0;
		int v = i;
		do
		{
			cycle_len++;
			cycle_sum += C[v];
			v = P[v];
		} while (i != v);

		ll sum = 0;
		int len = 0;

		do
		{
			len++;
			sum += C[v];

			int num = (k - len) / cycle_len;
			ll cur = sum + max(0ll, cycle_sum) * num;
			chmax(ans, cur);

			v = P[v];

		} while (i != v && len < k);
	}
	cout << ans << en;
}