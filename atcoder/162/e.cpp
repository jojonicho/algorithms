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

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y){
	x -= y;
	if(x<0) return x + MOD;
	return x;
}
ll mult(ll x, ll y){
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if(p==0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p-1));
	return bin_pow(mult(x,x), p/2);
}
ll rev(ll x){
	return bin_pow(x, MOD - 2);
}

int maxFactor(int n) {
	for(int i = 2;i*i<=n;i++)
		if (n%i == 0) return n / i;
	return 1;
}

void solve(){
	int n, k;
	cin >> n >> k;
	ll tot = 0;
	// tot += 

}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    while(t--)
        solve();
    return 0;
}