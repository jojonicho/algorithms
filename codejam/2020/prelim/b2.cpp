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
    string s;
    cin >> s;

    string ans;
    int dep = 0;
    for(char c: s) {
        int score = c-'0';
        while(score > dep) {
            ans+='(';
            dep++;
        }
        while(score < dep) {
            ans += ')';
            dep--;
        }
        ans+=c;
    }
    while(dep > 0){
        ans+=')';
        dep--;
    }
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