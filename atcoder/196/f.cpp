#include <bits/stdc++.h>
#include <atcoder/all>

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

const int INF = 1e6 + 1;

int main()
{
	fast;
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int ans = INF;
	reverse(t.begin(), t.end());
	vector<modint998244353> s1(n), s2(n), t1(n), t2(n);
	// s1 -> number of 1's that match
	// s2 -> number of 0's that match
	for (int i = 0; i < m; i++)
	{
		(t[i] == '1' ? t1 : t2)[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		(s[i] == '1' ? s1 : s2)[i] = 1;
	}

	s1 = convolution(s1, t2);
	s2 = convolution(s2, t1);

	for (int i = m - 1; i < n; i++)
	{
		chmin(ans, s1[i].val() + s2[i].val());
	}
	cout << ans << en;
}