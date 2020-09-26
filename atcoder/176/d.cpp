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
	int ch, cw;
	cin >> ch >> cw;
	int dh, dw;
	cin >> dh >> dw;
	char s[h][w];
	// vector<vector<char>> s;
	FOR(h)
	{
		FOR(j, w)
		{
			char c;
			cin >> c;
			s[i][j] = c;
		}
	}
	int ans = 0;
	while (ch != dh && cw != dw)
	{
		while (ch < dh && s[ch + 1] != "#")
			ch++;
		while (ch > dh && s[ch - 1] != "#")
			ch--;
		while (cw < dw && s[cw + 1] != "#")
			cw++;
		while (cw > dw && s[cw - 1] != "#")
			cw--;
		if (ch < dh)
		{ // up
			for (int i = ch; i < ch + 3 && i < h; i++)
			{
				if (cw < dw)
				{ // right
					for (int j = cw + 1; j < w && j < cw + 3; j++)
					{
						// if
					}
				}
				else
				{ // left
					for (int j = cw - 1; j >= 0 && j > cw - 3; j--)
					{
					}
				}
			}
		}
		else
		{ // ch > dh down
			if (cw < dw)
			{ // right
			}
			else
			{ // left
			}
		}
		// for(int i=)
	}
	cout << ans << en;
}