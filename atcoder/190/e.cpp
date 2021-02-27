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

const int mxN = 1e5;
const int mxK = 17;
const int INF = 0x3fffffff;

int n, m;
int k;

vvi dist(mxK);
vvi g(mxN);
vi C(mxK);

vi bfs(int cur)
{
	vi distFromK(n, INF);
	queue<int> q;
	distFromK[cur] = 0;
	q.push(cur);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : g[u])
		{
			if (distFromK[u] + 1 < distFromK[v])
			{
				distFromK[v] = distFromK[u] + 1;
				q.push(v);
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		distFromK[i] = distFromK[C[i]];
	}
	distFromK.resize(k);
	return distFromK;
}

int main()
{
	fast;
	cin >> n >> m;
	FOR(m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	cin >> k;
	C.resize(k);
	for (auto &c : C)
	{
		cin >> c;
		c--;
	}

	FOR(k)
	{
		dist[i] = bfs(C[i]);
	}

	vvi dp(1 << k, vi(k, INF));
	for (int i = 0; i < k; i++)
	{
		dp[1 << i][i] = 1;
	}

	for (int mask = 0; mask < (1 << k); mask++)
	{
		for (int i = 0; i < k; i++)
		{
			if ((mask >> i) & 1)
			{
				const int mask2 = mask ^ 1 << i;
				for (int j = 0; j < k; j++)
				{
					if ((mask2 >> j) & 1)
					{
						chmin(dp[mask][i], dp[mask2][j] + dist[j][i]);
					}
				}
			}
		}
	}

	int ans = *min_element(dp.back().begin(), dp.back().end());
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
}