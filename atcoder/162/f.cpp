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

void solve(){
	ll n;
	cin >> n;
	//prefix sum // max if choose a[i-1]
	vll a(n), pre(n,0), dp(n+1, 0);
	forn{
		cin >> a[i];
		pre[i] = (i>1 ? pre[i-2] : 0) + a[i];
	}
	for(ll i=2; i<=n; i++){
		if(i&1L){//odd
			dp[i]=max(dp[i-2]+a[i-1], dp[i-1]);
		} else{
			dp[i]=max(pre[i-2], dp[i-2]+a[i-1]);
		}
	}
	print(pre);
	print(dp);
	cout << dp[n] << en;
	// print(a);
	// print(pre);
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