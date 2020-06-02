#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

int t;

bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
//         int cright = x_center + radius;
//         int cleft
        
//         int sright = 
    float dx = abs(x_center - abs((float)x2-(float)x1)/2.0);
    float dy = abs(y_center - abs((float)y2-(float)y1)/2.0);
    cout << dx << " " << dy;
}

void solve(){
	// int x, y, a ,b, c;
	// ll ans = 0;
	// cin >> x >> y >> a >> b >> c;
	// int A[a], B[b], C[c], cnt = x + y;
	// forn(i,a) cin >> A[i];
	// forn(i,b) cin >> B[i];
	// forn(i,c) cin >> C[i];
	// sort(A, A+a, greater<int>());
	// sort(B, B+b, greater<int>());
	// sort(C, C+c, greater<int>());
	// vi abc(x+y+c);
	// forn(i,x) abc.push_back(A[i]);
	// forn(i,y) abc.push_back(B[i]);
	// forn(i,c) abc.push_back(C[i]);
	// sort(abc.begin(), abc.end(), greater<int>());
	// forn(i,x+y) ans += abc[i];
	// cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    checkOverlap(1,0,0,-1, 0,0, 1);
	// cin >> t;
	// while(t--)
	// 	solve();
}