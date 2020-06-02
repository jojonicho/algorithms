#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 
#define all(x) (x).begin(),(x).end()
#define en '\n'
#define endl '\n'

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
// right
void solve(){
    int n; cin >> n;
    vi a(n + 1);
    vector<ll> prefix(n + 1);
    map<ll, int> map;
    map[0] = 0;
    ll ans = 0;
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		int len = 0;
		cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
		if(map.count(prefix[i])) {
			len = map[prefix[i]] + 1;
		}
		map[prefix[i]] = i;
		pre = max(pre, len);
		ans += i - pre;
    }
	cout << ans << en;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    int t=1;
    while(t--)
        solve();
    return 0;
}