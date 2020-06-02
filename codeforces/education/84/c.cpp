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

void solve(){
	int n,m,k, moves;
	cin >> n >> m >> k;
	forn(i,2*k*2) {
		int tr;
		cin >> tr;
	}
	moves = (n-1) + (m-1) + (n*m-1);
	cout << moves << en;
	forn(i,n-1) cout << 'U';
	forn(i,m-1) cout << 'L';
	bool dir = 0;
	for(int i=0; i<n; i++){
		if(i!=0) cout << 'D';
		for(int j=0; j<m; j++) {
			if(j==0) continue;
			if(dir) cout << 'L';
			else cout << 'R';
		}
		dir = !dir;

	}
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    int t = 1; 
	// cin >> t;
    while(t--)
        solve();
    return 0;
}