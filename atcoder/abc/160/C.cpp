#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>

void solve2()
{
	int k, n;
	cin >> k >> n;
	vi a(n);
	int ans = k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int prev = (i == 0) ? a[n - 1] : a[i - 1];
		int dist = abs(a[i] - prev);
		ans = min(ans, max(dist, k - dist));
	}
	cout << ans << "\n";
}
void solve()
{
	int k, n;
	cin >> k >> n;
	vi a(n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		ans = max(ans, abs(a[i] - a[i - 1]));
	ans = max(ans, k - a[n - 1] + a[0]);
	cout << k - ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n, ma = 0;
	cin >> k >> n;
	vi A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 1; i < n; i++)
	{
		ma = max(abs(A[i] - A[i - 1]), ma);
	}
	ma = max(ma, k - A[n - 1] + A[0]);
	cout << k - ma;
}