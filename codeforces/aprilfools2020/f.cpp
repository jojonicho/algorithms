#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vii vector<vector<int>>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int ans = 0;
	for(char c: s) {
		ans += (int)c;
	}
	if (((ans  + s.length()) % 2)) cout << "NO";
	else cout << "YES";
}