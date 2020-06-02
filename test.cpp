#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

void happy(int n){
	int j = 0;
	while(n) {
		j += pow(n%10, 2);
		n /= 10;
	}
	cout << j << endl;
	if(j == 1) return ;
	happy(j);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	happy(7);
	return 0;
}