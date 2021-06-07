#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (s[0]==s[2])
                cout << "No";
        else
                cout << "Yes";
}