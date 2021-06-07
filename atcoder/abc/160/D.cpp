#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x ,y;
	cin >> n >> x >> y;

	--x, --y;
	vi A(n-1, 0);

	for(int i = 0; i<n; i++) {
		for(int j=i+1; j<n; j++ ){
			ll d1 = j - i, d2 = 1;
			d2 += abs(x - i) + abs(y - j);
			A[ min(d1, d2) - 1 ]++;
			cout << d1 << " " << d2 << endl;
		}
	}
	for(int i=0; i<n-1; i++)
		cout << A[i] << '\n';
}