#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 
#define all(x) (x).begin(),(x).end()
#define en '\n'

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
    int n; cin >> n;
	vll a(n), b(n);
	// int mn = 1e9;
	forn(i,n)
		cin >> a[i] >> b[i];

	ll ans = 0;
	forn(i,n){
		//p for previous
		// 7 15
		// 2 14
		// 5 3
		// ans += 7 - 3
		// a[0] = b[2]
		// 
		int p = i-1;
		if(p<0) p += n;
		if(a[i] > b[p]){
			ans += a[i] - b[p];
			a[i] = b[p];
		}
	}
	ll mn = a[0];
	forn(i+1,n)
		mn = min(mn, a[i]);
	cout << ans + mn << en;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}