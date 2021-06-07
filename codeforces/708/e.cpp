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
const int A = 1e7;
int primeFactor[A + 1];
vi primes;

void pre()
{
	for (int i = 2; i <= A; ++i)
	{
		if (primeFactor[i] == 0)
		{
			primes.pb(i);
			primeFactor[i] = i;
		}
		for (auto &x : primes)
		{
			if (x > primeFactor[i] || x * i > A)
			{
				break;
			}
			primeFactor[x * i] = x;
		}
	}
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 1);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		int cnt = 0, last = 0;
		while (x > 1)
		{
			int p = primeFactor[x];
			if (last == p)
			{
				++cnt; // even number of same prime factor -> perfect square
			}
			else
			{
				if (cnt % 2 == 1)
				{
					a[i] *= last; // only keep track of odd prime count
				}
				last = p;
				cnt = 1; // reset
			}
			x /= p;
		}

		if (cnt % 2 == 1)
		{
			a[i] *= last;
		}
	}

	int lastGroupIdx = 0, ans = 1;
	map<int, int> last;

	for (int i = 0; i < n; ++i)
	{
		if (last.find(a[i]) != last.end() && last[a[i]] >= lastGroupIdx)
		{
			++ans;
			lastGroupIdx = i;
		}
		last[a[i]] = i;
	}

	cout << ans << en;
}

int main()
{
	fast;
	int t;
	cin >> t;
	pre();

	while (t--)
	{
		solve();
	}
}