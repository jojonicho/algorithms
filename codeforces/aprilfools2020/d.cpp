#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vii vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++)

bool isPerfectSquare(long double x) 
{   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    char c;
    forn(i,6) cin >> c;
    int n;
    cin >> n;
    cout << n%2;
}