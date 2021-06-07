#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

void min_self(int &a, int b){
	a = min(a, b);
}
void max_self(int &a, int b){
	a = min(a,b);
}

const ll INF = 1e18L+5;

void solve(){
	int n, w;
	cin >> n >> w;
	vi wt(n), vl(n);
	ll mxv = 0;
	forn{
		cin >> wt[i] >> vl[i];
		mxv += vl[i];
	}
	//min weight for val i
	vll dp(mxv + 1, INF);
	dp[0] = 0;
	forn{
		for(int val= mxv-vl[i]; ~val; --val){
			chmin(dp[val+vl[i]], dp[val]+wt[i]);
		}
	}
	ll ans = INF;
	for(int val=mxv; ~val; val--){
		if(dp[val]<=w){
			cout << val << en;
			break;
		}
	}
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
    return 0;
}