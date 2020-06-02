#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 
 
int t;
 
void solve(){
	ll n, k;
	cin >> n >> k;
	if(k == 1){
		cout << 0;
		return ;
	}
	n %= k;
	if(k-1 == n) {
		cout << 1;
		return ;
	}
	cout << min(n, k-n);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	t = 1;
	while(t--)
		solve();
	return 0;
}