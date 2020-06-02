#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vii vector<vector<int>>

bool isPerfectSquare(long double x) 
{   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    ll n;
    cin >> n;
    if(isPerfectSquare(n)) {
        cout << sqrt(n) << sqrt(n);
    } else{ 
        for(ll i = 2; i<n; i++) {
            if(!(n%i)) cout << i;
        }
    }
}