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
    int n, x;
	cin >> n >> x;
	vll a(n);
	bool ok = 1;
	int ans = 0;
	int cur = 0;
	ll tot = 0;
	forn(i,n) {
		ll t;
		cin >> t;
		a[i] = t;
		if(t < x) {
			ok = 0;
		}
		if(t >= x) {
			ans++;
			cur += t - x;
		}
		tot += t;
	}
	if(ok) {
		cout << n << en;
		return ;
	}
	// if(tot / n >= x) {
	// 	cout << n << en;
	// 	return ;
	// }
	if(cur == 0) {
		cout << 0 << en;
		return ;
	}
	sort(all(a));
	int id = n-ans-1;
	while(id>=0 && (cur -= x-a[id]) > 0) {
		ans++;
		id--;
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