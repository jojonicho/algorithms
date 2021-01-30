#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

void solve()
{
	int n, requiredMemory;
	cin >> n >> requiredMemory;
	int memory[n];
	FOR(n)
	{
		cin >> memory[i];
	}
	vi conv1, conv2;

	ll sum1 = 0, sum2 = 0, ans = INT_MAX;
	for (auto &mem : memory)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			conv1.pb(mem);
		}
		else
		{
			conv2.pb(mem);
			sum2 += mem;
		}
	}

	sort(rall(conv1));
	sort(rall(conv2));

	// greedily delete conv1 over conv2 applications
	int r = conv2.size() - 1;
	for (int l = 0; l <= conv1.size(); l++)
	{
		// delete less of conv2
		while (r >= 0 && sum1 + sum2 - conv2[r] >= requiredMemory)
		{
			sum2 -= conv2[r--];
		}
		if (sum1 + sum2 >= requiredMemory)
		{
			chmin(ans, 2 * (r + 1) + l);
		}
		if (l == conv1.size())
			break;
		sum1 += conv1[l];
	}
	cout << (ans == INT_MAX ? -1 : ans) << en;
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