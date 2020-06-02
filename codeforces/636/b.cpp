#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 
#define all(x) (x).begin(),(x).end()
#define en '\n'
#define FILL(x,v) memset(x,v,sizeof(x))
#define pb push_back

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

void solve(){
	int n;
	cin >> n;
	// even = 2k
	// odd = 2k+1
	vi a(n);
	int cur = 0;
	for(int i=1; i<=n/2; i++){
		a[i-1] = i*2;
		cur += i*2;
	}
	int sum = cur;
	forn(i,n/2) cur--;
	if(cur%2) {
		cout << "NO" << en;
	} else {
		cout << "YES" << en;
		int k = 1;
		forn(i,n/2-1) {
			sum -= k;
			a[i+n/2] = k;
			k+=2;
		}
		a[n-1] = sum;
		forn(i,n)
			cout << a[i] <<" ";
	}

}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
	cin >> t;
    while(t--)
        solve();
    return 0;
}