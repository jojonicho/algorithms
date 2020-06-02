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
#define endl '\n'

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
    int a[n], b[n];
	forn(i,n) cin >> a[i];
	forn(i,n) cin >> b[i];
	if(a[0] != b[0]) {
		cout << "NO" << en;
		return ;
	}
	bool pos = 0, neg = 0;
	forn(i,n) {
		if(a[i] != b[i]) {
			if((b[i] > a[i] && !pos) || (b[i] < a[i] && !neg)) {
				cout << "NO" << en;
				return ;
			}
		}
		if(a[i] == 1) pos = 1;
		if(a[i] == -1) neg = 1;
	}
	cout << "YES" << en;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}