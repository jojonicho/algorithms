#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vii vector<vector<int>>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        // cout << ((b-a) % b + b ) % b << "\n";

        if (a % b == 0) 
            cout << 0 << '\n';
        else
            cout <<  b - (a % b) << '\n';
    }
    return 0;
}