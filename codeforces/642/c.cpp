#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
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
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

// vi dp(5e5+5, 0);
// 1 2 3 4 5
// 4 5 6 4 5
// 7 8 9 3 2 
// 4 5 6 4 5
// 7 8 9 3 2 
void solve(){
	ll n;
	cin >> n;
	ll ans =0;
	// ans += 3*(n*(n+1) / 2 - 1); diag and top + left
	// ans += 2*((n-1)*n/2) + 2*n;
	ll cnt = 0;
	while(n > 2){
		cnt += n*n - (n-2)*(n-2) + ans;
		ans += n*n - (n-2)*(n-2);
		// cout <<  2*((n-1)*n/2) << en;
		// cout << (n-2)*2*(n-1) << en;
		n-=2;
	}
	// for(int i=1; i<n-1; i++){
	// 	ans += n;
	// }
	// for(int i=1; i<n-1; i++){
	// 	// ans += (n-i-1)*i + (n-i-1)*(n-i)/2;
	// 	cout << (n-i-1)*i;
	// 	// for(int j=1; j<n; j++){

	// 	// }
	// }
	cout << cnt << en;
}

int main(){
	fast;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
	cin >> t;
    while(t--){
		solve();
	}
    return 0;
}