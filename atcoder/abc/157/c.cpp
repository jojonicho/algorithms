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
	int n, m;
	cin >> n >> m;
	int s[n], c[n];
	for (int i = 1; i <= m; i++)
		cin >> s[i] >> c[i];
	FOR(1000)
	{
		string t = to_string(i);
		if (t.size() == n)
		{
			int j;
			for (j = 1; j <= m; j++)
				if (t[s[j] - 1] != c[j] + '0')
					break;
			if (j == m + 1)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}

// int main()
// {
// 	fast;
// 	int n, m;
// 	cin >> n >> m;
// 	int a[n] = {};
// 	FOR(m)
// 	{
// 		int s, c;
// 		cin >> s >> c;
// 		s--;
// 		a[s] = c;
// 	}
// 	bool lead = 0;
// 	if (n > 1)
// 	{
// 		for (int i = 0; i < n; ++i)
// 		{
// 			if (a[i] != 0)
// 				lead = 1;
// 			if (a[i] == 0 && !lead)
// 			{
// 				cout << -1;
// 				return 0;
// 			}
// 		}
// 	}
// 	FOR(n)
// 	cout << a[i];
// }