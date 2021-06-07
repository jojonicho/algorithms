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
#define fast                     \
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
#define FOR(...)       \
	F_ORC(__VA_ARGS__) \
	(__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...)       \
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
	int h, w;
	cin >> h >> w;
	int ch, cw; // current
	cin >> ch >> cw;
	int dh, dw; // destination
	cin >> dh >> dw;

	string s[h];
	FOR(h)
	{
		cin >> s[i];
	}
	// 01 bfs -> dequeue
	deque<tuple<int, int, int>> dq;
	vvi dist(h, vector<int>(w, -1)); // -1 for unvisited, dist >=0 means already relaxed
	dq.emplace_front(ch - 1, cw - 1, 0);

	while (!dq.empty())
	{
		int x, y, z;
		tie(x, y, z) = dq.front();
		dq.pop_front();

		if (x < 0 || x >= h || y < 0 || y >= w || dist[x][y] >= 0 || s[x][y] == '#')
			continue;

		dist[x][y] = z;

		for (int i = -2; i <= 2; i++)
		{
			for (int j = -2; j <= 2; j++)
			{
				if (!i && !j)
					continue;
				if (i * i + j * j == 1) // adjacent to maximum 1 distance
				{
					dq.emplace_front(x + i, y + j, z);
				}
				// else if (i * i + j * j > 1)
				else
				{
					/*
				[x][j]
				[i][cur] -> (-1)^2 + 1^2 == 2, more than 1 step
				*/
					dq.emplace_back(x + i, y + j, z + 1);
				}
			}
		}
	}
	cout << dist[dh - 1][dw - 1] << en;
}