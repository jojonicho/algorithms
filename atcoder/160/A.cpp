#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	if (s[2] == s[3] && s[4] == s[5])
		cout << "Yes";
    else
		cout << "No";
}
