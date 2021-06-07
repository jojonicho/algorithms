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

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	fast;
	ll n, m;
	cin >> n >> m;
	// vi C(n), D(n);
	vector<pair<int, int>> items(n);
	FOR(n)
	{
		int a, b;
		cin >> a >> b;
		items[i] = {a, b};
	}

	sort(all(items), comp);
	priority_queue<int, vector<int>, greater<int>> pq;

	ll sum = 0;
	ll ans = 0;
	FOR(m)
	{
		auto cur = items[n - 1 - i];
		sum += cur.first;
		pq.push(cur.first);
		if (i == m - 1)
		{
			ans = sum + cur.second * m;
		}
	}

	for (int i = n - 1 - m; i >= 0; i--)
	{
		int smallestC = pq.top();
		pq.pop();
		auto cur = items[i];
		sum -= smallestC;
		sum += cur.first;
		pq.push(cur.first);
		chmax(ans, sum * cur.second);
	}
	cout << ans << en;
}