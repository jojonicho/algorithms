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
const int mxN = 1000;
int n, m;
bool vis[mxN][mxN];
string g[mxN];
int ways[5] = {0, 1, 0, -1, 0};
string str_ways[5] = {"R", "U", "L", "D"};

string dfs(string ans = "", int i, int j)
{
	if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == '#' || vis[i][j])
	{
		return "";
	}
	if (g[i][j] == 'B')
	{
		return ans;
	}
	vis[i][j] = 1;
	for (int k = 0; k < 4; k++)
	{
		int x = i + ways[k], y = j + ways[k + 1];
		dfs(ans + str_ways[k], x, y);
	}
	return ans;
}

int main()
{
	fast;
	cin >> n >> m;
	FOR(n)
	{
		cin >> g[i];
	}
	int ans = 0;
	string str_ans;
	bool ok = str_ans.back() == 'B';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (g[i][j] != 'A')
			{
				continue;
			}
			str_ans = dfs(i, j);
			break;
		}
	}
	cout << (ok ? "YES" : "NO") << en;
	cout << ans << en;
	cout << str_ans << en;
}