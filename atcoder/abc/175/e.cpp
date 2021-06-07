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
const ll INF = 6e12 + 1;
const int mxN = 3001;
ll V[mxN][mxN];
ll dp[mxN][mxN][4];

int main()
{
	fast;
	int R, C, K;
	cin >> R >> C >> K;
	FOR(K)
	{
		int r, c, k;
		cin >> r >> c >> k;
		r--;
		c--;
		V[r][c] = k;
	}
	FOR(R)
	{
		FOR(j, C)
		{
			FOR(k, 4)
			{
				dp[i][j][k] = -INF;
			}
		}
	}

	dp[0][0][0] = 0;
	FOR(R)
	{
		FOR(j, C)
		{
			for (int k = 2; k >= 0; k--)
			{
				chmax(dp[i][j][k + 1], dp[i][j][k] + V[i][j]);
			}
			FOR(k, 4)
			{
				if (i + 1 < R)
				{
					chmax(dp[i + 1][j][0], dp[i][j][k]);
				}
				if (j + 1 < C)
				{
					chmax(dp[i][j + 1][k], dp[i][j][k]);
				}
			}
		}
	}
	ll ans = -INF;
	FOR(k, 4)
	{
		chmax(ans, dp[R - 1][C - 1][k]);
	}
	cout << ans << en;
}