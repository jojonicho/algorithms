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
	int n;
	ll l, r;
	cin >> n >> l >> r;
	l--;
	r--;
	// index first value
	ll s = 0;
	for(int v=1; l<=r&&v<n; v++) {
		// how many cycles eaten (1,2) (1,3) (1,4) = 3 = 2(n - v)
		ll len = n-v; // 3-1, 3-2,
		if(s + 2*len <= l) {
			s += 2*len;
			continue;
		}
		// s about to surpass l
		for (int u=v+1; u<=n; u++){
			if(s == l && l<=r){ // l zero indexing, r 1
			//<= change r to 0 base
				cout << v << " ";
				l++;
			}
			s++;
			if(s == l && l<=r){
				cout << u << " ";
				l++;
			}
			s++;
		}
	}
	if(l <= r) cout << 1;
	cout << en;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}