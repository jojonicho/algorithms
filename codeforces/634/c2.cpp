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

int fr[200002];
void solve(){
	int n, dis = 0;
	cin >> n;
	forn(i,n) {
		int k; cin >> k;
		fr[k]++;
		if(fr[k] == 1) dis++;
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		ans = max(ans, max(min(dis, fr[i] - 1), min(dis - 1, fr[i])));
	}
	cout << ans << en;
	// reset
	fori(i, 1, n+1)
		fr[i] = 0;
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