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
const ll mxM = 1e18;
const ll INF = 5.76460752e17;

ll m;

ll mul(ll a, ll b)
{
	if (b == 0)
		return 0;
	ll ret = mul(a, b / 2);
	ret += ret;
	if (b & 1)
		ret += a;
	if (ret > m)
		ret = m + 1;
	return ret;
}

int main()
{
	fast;
	string x;
	cin >> x >> m;
	if (x.size() == 1)
	{
		cout << (stoi(x) <= m) << en;
		return 0;
	}

	ll d = 0;

	vll digits(60);

	for (int i = x.size() - 1; i >= 0; i--)
	{
		// reverse number
		ll cur = x[x.size() - i - 1] - '0';
		digits[i] = cur;
		chmax(d, cur);
	}

	ll lo = d + 1, hi = mxM;
	while (lo <= hi)
	{
		ll curM = m;
		ll mid = lo + (hi - lo) / 2;
		ll exp = 1;

		for (int i = 0; i < x.size(); i++)
		{
			ll decrement = mul(exp, digits[i]);
			if (exp > m || decrement > m)
			{
				curM = -1;
				break;
			}

			curM -= (decrement);
			if (curM < 0)
			{
				break;
			}
			exp = mul(exp, mid);
		}

		if (curM >= 0)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	cout << hi - d << en;
}