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
const int N = 300010;

int n, m;

int A[N], B[N], C[N], ans[N];

vector<int> G[N];
void solve()
{
	// int n, m;
	cin >> n >> m;
	// int A[n], B[n], C[n], ans[m];
	// vector<int> G[n];

	FOR(n)
	{
		cin >> A[i];
		A[i]--;
	}
	FOR(n)
	{
		cin >> B[i];
		B[i]--;
		if (B[i] != A[i])
		{
			G[B[i]].pb(i);
		}
	}
	FOR(m)
	{
		cin >> C[i];
		C[i]--;
	}
	int last = -1;
	if ((int)G[C[m - 1]].size() > 0)
	{ // there is B that needs last painter's color
		last = G[C[m - 1]].back();
		G[C[m - 1]].pop_back();
	}
	else
	{
		FOR(n)
		{
			if (B[i] == C[m - 1])
			{
				last = i;
				break;
			}
		}
	}
	if (last == -1)
	{
		cout << "NO" << en;
		return;
	}
	ans[m - 1] = last;
	FOR(m - 1)
	{
		if ((int)G[C[i]].size() == 0)
		{ // dont need this color
			ans[i] = last;
		}
		else
		{
			ans[i] = G[C[i]].back();
			G[C[i]].pop_back();
		}
	}

	FOR(n)
	{
		if (G[i].size())
		{
			cout << "NO" << en;
			return;
		}
	}

	cout << "YES" << en;
	FOR(m)
	{
		cout << ans[i] + 1;
		if (i != m - 1)
			cout << " ";
	}
	cout << en;
}
int main()
{
	fast;
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}