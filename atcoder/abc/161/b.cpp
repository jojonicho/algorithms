#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

int t;

void solve(){
	int n, m;
	float tot;
	cin >> n >> m;
	vi A(n);
	for(int i=0; i<n; i++){
		// int cur;
		cin >> A[i];
		tot += A[i];
	}
	sort(A.begin(), A.end(), greater<int>());
	for(int i=0; i<m; i++) {
		float ba = tot / (4*m);
		// cout<<A[i]<<" "<<ba<<endl;
		if(A[i] < ba) {
			cout << "No";
			return ;
		}
	}
	cout << "Yes";
	// cout << x << " " <<  y << " "<< z; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// cin >> t;
	// while(t--)
	solve();
}