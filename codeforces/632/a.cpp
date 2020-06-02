#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) {
			if(i == 0 && j==0)
				cout << "W";
			else 
				cout<< "B";
		}
		cout << "\n";
	}
}

// void solve(){
// 	int n, m;
// 	cin >> n >> m;
// 	int b = 0, w=1;
// 	bool ok = false;
// 	char a[n][m];
// 	for(int i=0; i<n; i++){
// 		for(int j=0; j<m; j++) {
// 			if(!ok)
// 				a[i][j] = 'B';
// 			else
// 				a[i][j] = 'W';
// 			ok = !ok;
// 		}
// 	}
// 	if(n*m % 2 == 0){
// 		if(n>m){
// 			a[n-1][n % 2] = 'B';
// 		} else if(m > n) {
// 			a[m%2][m-1] = 'B';
// 		}
// 	}
// 	for(int i=0; i<n; i++){
// 		for(int j=0; j<m; j++) {
// 			cout<< a[i][j];
// 		}
// 		cout << "\n";
// 	}
// }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}