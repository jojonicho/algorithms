#include <bits/stdc++.h>
#include <atcoder/all>
// python $AC_LIBRARY_PATH/expander.py b.cpp

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
const int H = 100;
const int W = 100;

int h, w, x, y;
int dir[5] = {0, 1, 0, -1, 0};

int vis[H][W];
string S[H];
bool find(int r, int c, int x, int y)
{
	if (r < 0 || r >= h || c < 0 || c >= w || vis[r][c] || S[r][c] == '#')
	{
		return false;
	}
	vis[r][c] = true;
	if (r == x && c == y)
	{
		cout << r + 1 << " " << c + 1 << en;
		return true;
	}

	for (int k = 0; k < 4; k++)
	{
		int row = r + dir[k], col = c + dir[k + 1];
		if (find(row, col, x, y))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	fast;
	cin >> h >> w >> x >> y;
	x--;
	y--;
	FOR(h)
	{
		cin >> S[i];
	}

	int ans = 1;
	FOR(h)
	{
		if (i == x)
		{
			continue;
		}
		memset(vis, 0, sizeof(vis));
		cout << "find: " << i + 1 << " " << y + 1 << en;
		if (find(x, y, i, y))
		{
			ans++;
		}
	}
	FOR(w)
	{
		if (i == y)
		{
			continue;
		}
		memset(vis, 0, sizeof(vis));
		cout << "find: " << x + 1 << " " << i + 1 << en;
		if (find(x, y, x, i))
		{
			ans++;
		}
	}
	cout << ans;
	// queue<pair<int,int>> q;
	// q.push({x,y});
	// while(!q.empty()) {

	// }
}