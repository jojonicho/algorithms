#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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

int main()
{
	fast;
	int n;
	cin >> n;

	string S, X;
	cin >> S >> X;
	int dp[n + 1][7] = {};
	dp[n][0] = 1;

	for (int i = n; i > 0; i--)
	{
		FOR(j, 7)
		{
			// j denotes the previous number chosen
			int num = S[i - 1] - '0';
			bool a = dp[i][(j * 10 + num) % 7];
			bool b = dp[i][(j * 10) % 7];
			if (X[i - 1] == 'T')
			{
				dp[i - 1][j] = a || b;
			}
			else
			{
				dp[i - 1][j] = a && b;
			}
		}
	}

	cout << (dp[0][0] ? "Takahashi" : "Aoki");
}