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

const int mxN = 5e3;
const int mxP = 1e6;

int n;
ll l, d, w;
int points[3] = {0, 0, 0};
ll numMatches;

int ans = 0;
void dfs(int cur, int target, int i)
{
	if (i == 3 || target < 0)
	{
		return;
	}

	// if (points[0] == 0 && target == 0)
	// {
	// 	ans++;
	// 	return;
	// }

	if (cur == numMatches)
	{
		if (target == 0)
		{
			ans++;
		}
		return;
	}

	// if (points[i] * (numMatches - cur) >= target)
	// {
	cur++;
	dfs(cur, target - points[i], i);
	cur--;
	// }
	dfs(cur, target, i + 1);
}

int solve(int p)
{
	if (p == 0)
	{
		if (l > 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	if (p > (numMatches * w))
	{
		return 0;
	}

	dfs(0, p, 0);
	return ans;
}

int main()
{
	fast;
	cin >> n;
	numMatches = (n - 1) * 2;

	cin >> w >> d >> l;
	points[0] = l;
	points[1] = d;
	points[2] = w;

	// map<int, int> mp;
	// mp[0] = (l == 0);

	// vi P(n);
	// FOR(n)
	// {
	// 	cin >> P[i];
	// }

	// FOR(n)
	// {
	// cout << solve(ps[i]) << en;
	// cout << mp[P[i]] << en;
	// }

	FOR(n)
	{
		int amount;
		cin >> amount;

		if (amount == 0)
		{
			if (l > 0)
			{
				cout << 0 << en;
			}
			else
			{
				cout << 1 << en;
			}
			continue;
		}

		if (amount > (numMatches * w))
		{
			cout << 0 << en;
			continue;
		}

		vi dp(amount + 1);
		dp[0] = 1;
		for (int point : points)
		{
			for (int i = point; i <= amount; i++)
			{
				dp[i] += dp[i - point];
			}
		}
		cout << dp[amount] << en;
	}
}