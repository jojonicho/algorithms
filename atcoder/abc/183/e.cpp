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
const int mxN = 2000;
char grid[mxN][mxN];
vector<vector<bool>> vis;

int x, y, ans;

// void dfs(int a, int b, vector<vector<bool>> vis)
// {
// 	vis[a][b] = 1;
// 	if (a == x - 1 && b == y - 1)
// 	{
// 		// ans += (a == x - 1 && b == y - 1);
// 		ans++;
// 		return;
// 	}
// 	FOR(x)
// 	{
// 		if (a + i >= x || vis[a + i][b] || (!vis[a + i][b] && grid[a + i][b] == '#'))
// 			continue;
// 		dfs(a + i, b, vis);
// 	}
// 	FOR(j, y)
// 	{
// 		if (b + j >= y || vis[a][b + j] || (!vis[a][b + j] && grid[a][b + j] == '#'))
// 			continue;
// 		dfs(a, b + j, vis);
// 	}
// }
void dfs(int a, int b, vector<vector<bool>> vis)
{
	if (a == x - 1 || b == y - 1)
	{
		ans += (a == x - 1 && b == y - 1);
		// ans++;
		return;
	}
	vis[a][b] = 1;
	FOR(x)
	{
		FOR(j, y)
		{
			if (a + i >= x || b + j >= y || vis[a + i][b + j] || (!vis[a + i][b + j] && grid[a + i][b + j] == '#'))
				continue;
			dfs(a + i, b + j, vis);
		}
	}
	// ans++;
}
int main()
{
	fast;
	cin >> x >> y;
	ans = 0;
	FOR(x)
	{
		FOR(j, y)
		{
			cin >> grid[i][j];
		}
	}
	vis = vector<vector<bool>>(x, vector<bool>(y));
	dfs(0, 0, vis);
	cout << ans << en;
}