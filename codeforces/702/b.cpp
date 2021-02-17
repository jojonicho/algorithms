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

void solve()
{
	int n;
	cin >> n;
	vi C(3);
	FOR(n)
	{
		int a;
		cin >> a;
		C[a % 3]++;
	}
	if (C[0] == 2 && C[1] == 2 && 2 == C[2])
	{
		cout << 0 << en;
		return;
	}

	ll ans = 0;
	int start = 0;
	int mx = -1;
	int target = n / 3;

	// FOR(3)
	// {
	// 	// cout << C[i] << " ";
	// 	if (C[i] > mx)
	// 	{
	// 		start = i;
	// 		mx = C[i];
	// 	}
	// }
	// cout << en;
	// cout << start << " " << target << en;
	FOR(6)
	{
		int cur = (i + start) % 3;
		int next = (cur + 1) % 3;
		// cout << cur << " " << next << en;
		if (C[cur] > target)
		{
			int diff = C[cur] - target;
			C[cur] -= diff;
			C[next] += diff;
			ans += diff;
		}
	}
	// if (C[0] > 2 && C[0] > C[1])
	// {
	// 	int diff = C[0] - 2;
	// 	C[1] += diff;
	// 	ans += diff;
	// }
	// if (C[1] > 2 && C[1] > C[2])
	// {
	// 	int diff = C[1] - 2;
	// 	C[2] += diff;
	// 	ans += diff;
	// }
	cout << ans << en;
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