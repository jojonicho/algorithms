#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
// #define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define fork(i,n) for(ll i=0; i<(n); i++)
#define forn for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 
#define all(x) (x).begin(),(x).end()
#define en '\n'
#define FILL(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}
template<typename T> void print(vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template<typename T> void print(deque<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template<typename T> void print(vector<vector<T>>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << en;
	}
}

// vi dp(5e5+5, 0);
// 1 2 3 4 5
// 4 5 6 4 5
// 7 8 9 3 2 
// 4 5 6 4 5
// 7 8 9 3 2 
const int n = (int)1e6+77;
vll ar(n);

void solve(){
	int a, b, c ,d; // x+y>z
	cin >> a >> b >> c >> d;
	for(int i=a; i<=b; i++){
		ar[i+b]++;
		ar[i+c+1]--;
	}
	print(ar);
	for(int i=1; i<n; i++) ar[i] += ar[i-1];
	for(int i=1; i<n; i++) ar[i] += ar[i-1];
	// print(ar);
	ll ans=0;
	for(int i=c; i<=d; i++)
		ans += ar[n-1] - ar[i];
	cout << ans << en;
}

int main(){
	fast;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
solve();
    return 0;
}