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

const int mxn = 5e5;
const int M = 1e9 + 7;

ll pw(ll b, ll e)
{
	ll res = 1;
	while (e)
	{
		if (e % 2)
			res = (res * b) % M;
		b = (b * b) % M;
		e >>= 1; // e/=2;
	}
	return res;
}

ll iv[mxn + 1], f1[mxn + 1], f2[mxn + 1];
ll nck(int n, int k)
{
	return f1[n] * f2[k] % M * f2[n - k] % M;
}

const int mxN = 1e9;

int helper(ll a, ll b)
{
	int ans = 0;
	if (b == 1)
	{
		b++;
		ans++;
	}
	while (a)
	{
		ans++;
		a /= b;
	}
	return ans;
}

void solve2()
{
	int a, b;
	cin >> a >> b;
	if (b > a)
	{
		cout << 1 << en;
		return;
	}

	int ans = mxN;
	for (int i = 0; i <= 30; i++)
	{
		chmin(ans, i + helper(a, b + i));
	}
	cout << ans << en;
}

// void solve()
// {
// 	cin >> A >> B;

// 	// vvi dp(mxN, vi(mxN, mxN));
// 	// ll dp[a][b];
// 	int mx = max(A, B);
// 	vector<vll> dp(mx + 1, vll(mx + 1, A - B + 1));

// 	FOR(mx + 1)
// 	dp[0][i] = 0;
// 	dp[1][1] = 2;

// 	for (ll i = 1; i <= mx; i++)
// 	{
// 		for (ll j = mx; j > 0; j--)
// 		// for (ll j = B; j > 0; j--)
// 		{
// 			if (j > i)
// 			{
// 				dp[i][j] = 1;
// 			}
// 			if (i == 1 && j == 1)
// 			{
// 				break;
// 			}
// 			// cout << "dp[" << i << "][" << j << "] : " << dp[i][j] << en;
// 			// cout << "dp[" << i << "][" << j + 1 << "] : " << dp[i][j + 1] << en << en;
// 			if (j != 1)
// 			{
// 				// cout << "dp[" << i / j << "][" << j << "] : " << dp[i / j][j] << en;
// 				chmin(dp[i][j], 1 + dp[i / j][j]);
// 			}
// 			chmin(dp[i][j], 1 + dp[i][j + 1]);
// 			// cout << i << " " << j << en;
// 			// if (j + 1 <= B)
// 			// 	chmin(dp[i][j - 1], dp[i][j] + 1);
// 			// if (i * j <= A)
// 			// 	chmin(dp[i * j][j], dp[i][j] + 1);
// 		}
// 	}
// 	// dp[9][2] = min(dp[4][2], dp[9][3]);
// 	// dp[]

// 	// // int ans = mxN;
// 	// int ans = *min_element(dp.back().begin(), dp.back().begin());
// 	// cout << ans << en;
// 	cout << dp[A][B] << en;
// 	// cout << helper(a, b) << en;
// }

int main()
{
	fast;
	int t;
	cin >> t;
	while (t--)
	{
		solve2();
	}
}