#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, ans;
	cin >> x;
	ans = 0;
	while (x >= 500) {
		x -= 500;
		ans += 1000;
	}
	while(x >= 5) {
		x -= 5;
		ans += 5;
	}
	cout << ans;
}
