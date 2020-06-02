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
	int n;
	cin >> n;
	vi a(n);
	vll pre(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
		ll sum = (i>0) ? pre[i-1] : 0;
		pre[i] = a[i] + sum;
	}
	vector<bool> spec(n+1, 0);
	if(pre[0]==pre[n-1]){
		cout << 0 << en;
		return ;
	}
	forn{
		ll cur = pre[i];
		if(i>0&&cur<=n) spec[cur] = 1;
		for(int j=i+2; j<n; j++){
			if(pre[j]-cur <= n)
				spec[pre[j]-cur] = 1;
		}
	}
	int ans = 0;
	forn{
		ans += spec[a[i]];
	}
	cout << ans << en;
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