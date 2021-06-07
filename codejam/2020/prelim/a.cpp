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
    int arr[n][n];
    int ans = 0;
    int k = -1;
    int r = 0;
    for(int i=0; i<n; i++){
        k++;
        bool ok = false;
        set<int> st;
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            int cur = arr[i][j];
            if(st.find(cur) != st.end())
                ok = true;
            st.insert(cur);
            if(j == k)
                ans+= cur;
        }
        if(ok)
            r++;
    }
    int c = 0;
    for(int j=0; j<n; j++){
        set<int> st;
        bool ok = false;
        for(int i=0; i<n; i++){
            int cur = arr[i][j];
            if(st.find(cur) != st.end())
                ok = true;
            st.insert(cur);
        }
        if(ok)
            c++;
    }
    cout << ans << " " << r << " " << c << "\n";
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