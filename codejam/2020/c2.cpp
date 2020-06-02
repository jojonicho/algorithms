#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

const int mxN=1e3;
int n, l[2];
ar<int, 3> a[mxN];
char c[2] = {'C', 'J'}, ans[mxN];

void solve(){
    int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i][0] >> a[i][1];
		a[i][2] = i;
	}
	sort(a, a+n);

	l[0]=l[1]=1e9;
	for(int i=n-1; ~i; --i){
		bool assigned=0; // first person
		int p1=0, p2=1;
		if(l[p1]>l[p2])
			swap(p1, p2);
		// p1 to start with
		// loop from n-1 to 0, check start time
		// compare to end time of c and j
		if(a[i][1]<=l[p1]) {
			assigned=1; // mark first person is assigned
			ans[a[i][2]] = c[p1];
			l[p1]=a[i][0];
		}
		if(!assigned&&a[i][1]<=l[p2]){
			assigned=1;
			ans[a[i][2]] = c[p2];
			l[p2]=a[i][0];
		}
		if(!assigned) { // if no person is available to assign
			cout << "IMPOSSIBLE\n";
			return ;
		}
	}
	// for(vi i: intervals) {
	// 	for(int j: i) {
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }
	forn(i, n)
		cout << ans[i];
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
    for(int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
		solve();
    }
}