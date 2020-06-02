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
    int n; cin >> n;
	int jomblo = -1;
    vector<bool> a(n, 0);
	forn(i,n){
		int k;
		cin >> k;
		bool marry = 0;
		forn(j,k) {
			int m;
			cin >> m;
			if(!marry && !a[m-1]) {
				a[m-1] = 1;
				marry = 1;	
			} 
		}
		if(!marry && jomblo == -1) {
			jomblo = i+1;
		}
	}
	if(jomblo == -1) cout << "OPTIMAL\n";
	else {
		forn(i,n){
			if(!a[i]) {
				cout << "IMPROVE\n" << jomblo << " " << i+1 << en;
				break;
			}
		}
	}
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