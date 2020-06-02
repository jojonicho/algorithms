#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define arr array
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;

	for (int i=1; i<1e4; ++i) {
		int a2=i*8/100, b2=i*10/100;
		if(a2==a && b2==b) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}