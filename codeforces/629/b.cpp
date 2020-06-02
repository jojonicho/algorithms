#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vii vector<vector<int>>
#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        string s(n, 'a');

        for(int i = n-2; i>=0; i--) {
            if (k <= (n - i - 1)) {
                s[i] = 'b';
                s[n-k] = 'b';
                cout << s << '\n';
                break;
            }
            k -= n - i - 1;
        }
    }
}