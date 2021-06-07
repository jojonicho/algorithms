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
#define FILL(x,v) memset(x,v,sizeof(x))
#define pb push_back

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

const ll MOD = 1e9+7;

void solve(){
	ll n, k;
	cin >> n >> k;
	ll pw = n*(n+1)/2;
	ll ans = 0;
	cout << pw << en;
	for(ll i = k; i<=n+1; i++){
		ll mn = (i-1)*i/2;
		ll mx = pw - (n-i)*(n-i+1)/2;
		ans += mx - mn + 1;
		ans %= MOD;
	}
	cout << ans << en;
}

void solve2(){
	ll n, k, ans=0;
	cin >> n >> k;
	// finding the range
	for(int i=k; i<=n+1; i++){
		ans += i*(n-i+1) + 1;
		ans %= MOD;
	}
	cout << ans << en;
}


int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t = 1;
	// cin >> t;
    while(t--)
        solve2();
    return 0;
}