#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define fork(i,n) for(ll i=0; i<(n); i++)
#define forn for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 
#define all(x) (x).begin(),(x).end()
#define en '\n'
#define FILL(x,v) memset(x,v,sizeof(x))
#define pb push_back

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}
template<typename T> void print(vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template<typename T> void print(deque<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template<typename T> void print(vector<vector<T>>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << en;
	}
}

void solve(){
	ll x, y, a, b;
	cin >> x >> y >> a >> b;
	// ll ans = 0;
	// ans = min({
	// b*min(x,y)+abs(x-y)*a,
	// abs(x-y)*a+b*max(x,y),
	// (x+y)*(min(2*a,b)/2)
	// }
	// );
    cout << min((x+y)*a, min(x,y)*b + abs(x-y)*a) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
	cin >> t;
    while(t--)
        solve();
    return 0;
}