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

const int mxN = 2e5;
// wa somehome

// queue<int> q;
// vector<bool> d(n, 1);
// q.push(0);
// d[0] = 0;
// int ans = 0;
// while(!q.empty()){
// 	bool ok = 1;
// 	int cur = q.front(); q.pop();
// 	for(auto c: adj[cur]){
// 		ok &= h[c] < h[cur];
// 		if(d[c]){
// 			d[c]=0;
// 			q.push(c);
// 		}
// 	}
// 	if(ok) ans++;
// }

void solve(){
	int n, m;
	cin >> n >> m;
	vi h(n);
	for(int i=0; i<n; i++){
		cin >> h[i];
	}
	vvi adj(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	forn{
		bool ok =1;
		for(int c: adj[i]){
			ok &= h[c] < h[i];
		}
		ans += ok;
	}
	// for(int i=0; i<n; i++) {
	// 	if(d[i]) ans++;
	// }
	cout << ans << en;
}

int main(){
	fast;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
    return 0;
}