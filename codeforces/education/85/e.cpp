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

const ll MOD = 998244353;
ll add(ll x, lly) {
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

const int N = 52;
ll P[N];
int n;
ll C[N][N];

void solve(){
	// binomial coefficient with pascal triangle
	forn(i,N)
		C[i][0] = C[i][i] = 1;
	forn(i,N)
		fori(j, 1, i)
			C[i][j] = add(C[i - 1][j-1], C[i-1][j]);
	ll x;
	cin >> x;
	for (ll y=2; y*y <= x; y++) {
		if (x % y) continue;
		p[n++] = y;
		while(!x%y) x/=y;
	}
	if (x>1) p[n++] = x;

	int q;
	cin >> q;
	while(q--){
		ll x, y;
		cin >> x >> y;
		forn(i,n) {
			a[i] = b[i] = 0;
			while(x % p[i] == 0) {
				x /= p[i];
				a[i]++;
			}
			while(y % p[i] == 0) {
				y /= p[i];
				b[i]++;
			}
		}
		ll ans1= 1, ans2 = 1;
		int sum1 = 0, sum2 = 0;
		forn(i,n){
			int z = min(a[i], b[i]);
			sum1 += a[i]-z;
			sum2 += b[i]-z;
			//mult is multinomial cofficient
			//mult and divide by factorials of prefix sum
			// (a1+a2+..ak)!/a1!/s2!/.../ak!
			ans1 = mult(ans1, C[sum1][a[i]-z]);
			ans2 = mult(ans2, C[sum2][b[i]-z]);
		}
		cout << mult(ans1, ans2);
	}
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    int t; 
	cin >> t;
    while(t--)
        solve();
    return 0;
}