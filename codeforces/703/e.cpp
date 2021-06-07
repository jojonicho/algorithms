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

const int mxW = 50;
const int GAP = mxW + 1;
const ll INF = 1e9 + 1;

struct comp
{
	bool operator()(pair<int, ll> &a, pair<int, ll> &b) // overloading both operators
	{
		return b.second < a.second; // if you want increasing order;(i.e increasing for minPQ)
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	// n*51 because we want gaps of 50 for every n
	vector<vector<pair<int, int>>> G(n * GAP, vector<pair<int, int>>());
	auto addEdge = [&](int a, int b, int w) {
		a *= GAP;
		b *= GAP;
		G[a].pb({b + w, 0});
		for (int i = 1; i <= 50; i++)
		{
			G[a + i].pb({b, (w + i) * (w + i)});
		}
	};

	FOR(m)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		addEdge(a, b, w);
		addEdge(b, a, w);
	}

	vll dist(n * GAP, INF);
	dist[0] = 0;

	priority_queue<pair<int, ll>, vector<pair<int, ll>>, comp> pq;
	pq.push({0, 0});

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int u = cur.first;
		ll w = cur.second;
		for (auto edge : G[u])
		{
			int v = edge.first;
			ll w2 = edge.second;
			ll weight = w + w2;
			if (weight < dist[v])
			{
				dist[v] = weight;
				pq.push({v, weight});
			}
		}
	}

	FOR(n)
	{
		if (dist[i * GAP] == INF)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << dist[i * GAP] << " ";
		}
	}
	cout << en;
}
int main()
{
	fast;
	solve();
}