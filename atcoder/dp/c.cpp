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

void max_self(ll &a, ll b){
	a = max(a,b);
}

void solve(){
	int n, w;
	cin >> n >> w;
	vll dp(w+1);
	//dp[i] - max val with i weight
	for(int i=0; i<n; i++){
		int weight, value;
		cin >> weight >> value;
		for(int j=w-weight; j>=0; j--){
			max_self(dp[j+weight], dp[j]+value);
		}
	}
	ll ans = 0;
	for(int i=0; i<=w; i++){
		max_self(ans, dp[i]);
	}
	cout << ans << en;
}

void solve2(){ // errocjtp version
	int n;
	cin >> n;
	// dp[i] - total cost do activity i on last day
	vi dp(3);
	forn(i,n){
		// cin >> a[i] >> b[i] >> c[i];
		vi a(3), new_dp(3, 0);
		cin >> a[0] >> a[1] >> a[2];
		forn(i,3){
			forn(j,3){
				if(i!=j){
					new_dp[j] = max(new_dp[j], dp[i]+a[j]);
				}
			}
		}
		dp = new_dp;
	}
	cout << max({dp[0],dp[1],dp[2]}) << en;
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
    while(t--)
        solve();
    return 0;
}