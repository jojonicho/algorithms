#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define arr array
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, a ,b;
	cin >> n >> a >> b;
	cout << n/(a+b)*a+min(n%(a+b), a);
}