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
    int n;
	cin >> n;
	string ans(n, 'C');
	vvi intervals(n);
	for(int i=0; i<n; i++) {
		vi temp(3);
		cin >> temp[0];
		cin >> temp[1];
		temp[2] = i;
		intervals[i] = temp;
	}
	sort(intervals.begin(), intervals.end(), [](vi a, vi b){return a[1] < b[1];});
	vi end = intervals[0];
	bool ok = true;
	vi prev = intervals[0];
	// bool ok2 = true;
	for(int i = 1; i<n; i++) {
		if(intervals[i][0] < end[1]) {
			if(!ok){
				if(intervals[i][0] < prev[1]) {
					ans = "IMPOSSIBLE";
					break;
				}
			} else {
				ok = false;
			}
			ans[intervals[i][2]] = 'J';
			prev = intervals[i];
		} else if(intervals[i][0] == end[0] && intervals[i][1] == end[1]){
			if(!ok) {
				ans = "IMPOSSIBLE";
				break;
			} else {
				char c = ans[end[2]];
				if (c == 'J') {
					ans[intervals[i][2]] = 'C';
				} else {
					ans[intervals[i][c]] = 'J';
				}
				ok = false;
			}
		} else {
			if(intervals[i][0] >= prev[1]) ok=true;
			end = intervals[i];
			// ok = true;
		}
	}
	// for(vi i: intervals) {
	// 	for(int j: i) {
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
    for(int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
		solve();
    }
}