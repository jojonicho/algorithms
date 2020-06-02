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
    // int n; cin >> n;
	// vi a(n);
	int n, m;
	cin >> n;
	vi a(n), p(n);
	vi ans(n);
	int ma = 0;
	forn(i,n) {
		int t;
		cin >> t;
		a[i] = t;
		if(t > ma) ans.push_back(t);
		ma = max(ma, t);
	}
	forn(i,n){
		cin >> p[i];
	}
	cin >> m;
	int b(m);
	forn(i,m) {
		cin >> b[i];
	}

	bool ok = 1;

    // sort(all(ans));
    // print(ans);
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    // int t; cin >> t;
	int t =1;
    while(t--)
        solve();
    return 0;
}