#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
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
	// maks 300000
	// 3e6
	int ans = 1e9;
    int n; cin >> n;
	vi a(n*2), b(n*2);
	ll tot = 0;
	forn(i,n){
		cin >> a[i] >> b[i];
		tot += a[i];
		a[n+i] = a[i];
		b[n+i] = b[i];
	}
	// print(a);
	// print(b);
	forn(i,n) {
		int cr = tot;
		int cur = 0;
		// int h = a[i];
		int id = i;
		bool ok = 0;
		int left = 0;
		while(cr > 0) {
			int health = a[id];
			health -= left;
			left = 0;
			// if(cr < a[id]) {
			// 	cur += cr;
			// 	break;
			// }
			cr -= min(cr, health);
			cur += a[id];
			while(b[id] >= a[id+1]&& cr>0) {
				cr -= min(cr,a[++id]);
			}
			left = b[id];
			id++;
		}
		ans = min(ans, cur);
	}
	cout << ans << en;
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