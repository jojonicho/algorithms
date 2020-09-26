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

void solve()
{
	int n, k;
	cin >> n >> k;
	int mn = 0, mx = 1e9 + 1;
	// priority_queue<int, vi, greater<int>> minq;
	// priority_queue<int> maxq;
	map<int, int> mp;
	vi a(n);
	FOR(n)
	{
		int c;
		cin >> c;
		a[i] = c;
		mp[c]++;
	};
	// sort(all(a));
	// int mn=a[0], mx=a[n-1];
	int num = mp.size();
	vi pre(num);
	int i = 0, cur = 0;
	for (auto c : mp)
	{
		// cur += c.second;
		// pre[i] += cur;
		// i++;
		pre[i++] = c.second;
	}
	for (int sd : pre)
	{
		cout << sd << " ";
	}
	cout << en;
	// FOR(n){
	// 	int c;
	// 	cin >> c;
	// mp[c]++;
	// chmin(mn, c);
	// chmax(mx, c);
	// minq.push(c);
	// maxq.push(c);
	// }
	// FOR(n)
	// {
	// 	int c = a[i];
	// 	mp[c]++;
	// 	if (mp[c] <= k)
	// 	// if(mp[c])
	// }
	// int i = 0, j = n - 1;
	// while (i != j)
	// {
	// 	int c = 0, d = 0;
	// 	int i2 = i, j2 = j;
	// 	if (mp[a[i]] <= k)
	// 	{
	// 		i2 += mp[a[i]];
	// 	}
	// 	if (mp[a[j]] <= k)
	// 	{
	// 		i2 += mp[a[i]];
	// 	}
	// }
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