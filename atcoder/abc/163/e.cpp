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
#define P pair<ll, int>

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

const int N = 2020;
 
int n;
ll a[N];
vector<pair<ll, int>> v;
 
ll dp[N][N];
ll dfs(int l, int r){
    if(l>r) return 0;
    if(dp[l][r]>=0) return dp[l][r];
    int idx = l+(n-1-r);
    int p = v[idx].second;
    ll x = v[idx].first;
 
    ll ret = 0;
    ret = max(ret, dfs(l+1,r)+x*(p-l));
    ret = max(ret, dfs(l,r-1)+x*(r-p));
    return dp[l][r] = ret;
}

void solve(){
	cin >> n;
	forn(i,n) cin >> a[i];
	v = vector<pair<ll, int>>(n);
	forn(i,n) v[i] = {a[i],i};
	sort(all(v), greater<P>());

	memset(dp, -1, sizeof(dp));
	cout << dfs(0,n-1) << en;
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