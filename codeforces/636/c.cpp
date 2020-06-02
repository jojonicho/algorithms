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

auto sgn(int x) {
	if (x > 0) return 1;
	else return -1;
};

void solve(){
	// ll n, a[200005];
	int n;
	cin >> n;
	vi a(n);
	// forn(i,n) cin >> a[i];
	for (auto &it: a) cin >> it;
	ll sum = 0;
	forn(i,n) {
		int cur = a[i];
		int j = i;
		while(j < n && sgn(a[i]) == sgn(a[j])){
			cur = max(cur, a[j]);
			j++;
		}
		sum += cur;
		i = j-1;
	}
	cout << sum << en;
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