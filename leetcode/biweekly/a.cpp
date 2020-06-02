#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

int t;

int countLargestGroup(int n) {
    int res = 1;
    vi ans(1e4);
    for(int i = 1; i<=n; i++){
        if(i<10) ans[i]++;
        else{
            int cur = 0;
            int j = i;
            while(j>0) {
                cur += j%10;
                j/=10;
            }
            ans[cur]++;
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    int ma = ans[0];
    // while()
    for(int i=1; i<ans.size(); i++) {
        if(ans[i]!=ma) break;
        res++;
    }
    return res;
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
	cin >> t;
	while(t--)
		solve();
}