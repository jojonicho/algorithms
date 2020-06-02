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
 
const int mxN = 200005;
vi dif;
vvi g;
 
int dfs(int v, int par=-1, int dep=0){
	dif[v] = dep;
	int size = 1;
	for(int node: g[v]) {
		if(node == par) continue;
		// size of all subtree
		int k = dfs(node, v, dep+1);
		size += k;
		dif[v] -= k;
	}
	return size;
}
 
void solve(){
	int n, k;
	cin >> n >> k;
	g = vvi(n);
	dif = vi(n);

	for(int i=0; i<n-1; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	dfs(0);
 
	// sort(all(dif), greater<int>())
	// sort by depth
	nth_element(dif.begin(), dif.begin()+k, dif.end(), greater<int>());

	ll ans = 0;
	forn(i,k)
		ans += dif[i];
	cout << ans;
}
 
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t=1;
	// cin >> t;
    while(t--)
        solve();
    return 0;
}