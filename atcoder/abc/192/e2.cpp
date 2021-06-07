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

struct comp
{
	bool operator()(pair<int, ll> &a, pair<int, ll> &b)
	{
		return b.second < a.second;
	}
};

struct Edge
{
	int v;
	ll t, k;
	inline Edge(int v, ll t, ll k) : v(v), t(t), k(k) {}
};

const ll INF = 1e18;

int main()
{
	fast;
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	x--;
	y--;
	vector<vector<Edge>> G(n, vector<Edge>());

	FOR(m)
	{
		int a, b;
		ll t, k;
		cin >> a >> b >> t >> k;
		a--;
		b--;
		G[a].pb(Edge(b, t, k));
		G[b].pb(Edge(a, t, k));
	}

	vll dist(n, INF);

	priority_queue<pair<int, ll>, vector<pair<int, ll>>, comp> pq;
	pq.push({x, 0});
	dist[x] = 0;

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int u = cur.first;
		ll w = cur.second;
		for (auto edge : G[u])
		{
			int v = edge.v;
			// how to get from u to v on time t
			ll weight = (w + edge.k - 1) / edge.k * edge.k + edge.t;
			if (weight < dist[v])
			{
				dist[v] = weight;
				pq.push({v, weight});
			}
		}
	}

	if (dist[y] == INF)
	{
		dist[y] = -1;
	}
	cout << dist[y] << en;
}