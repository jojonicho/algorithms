#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n, ma = 0;
	cin >> k >> n;
	vi A(n);
	for (int i=0; i<n; i++) {
		cin >> A[i];
	}
	for (int i=1; i<n; i++) {
		ma = max(abs(A[i] - A[i-1]), ma);
	}
	ma = max(ma, k - A[n-1] + A[0]);
	cout << k - ma;
}