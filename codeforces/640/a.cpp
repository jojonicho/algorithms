#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
#define ar array
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

void solve(){
	int n;
	cin >> n;
	vi ans;
	int cur = 0;
	while(n>=10){
		if(n%10){
			ans.push_back(n%10*(pow(10,cur)));
		}
		n/=10;
		cur++;
	}
	if(n>0) ans.push_back(n*(pow(10,cur++)));
	cout << ans.size() << en;
	for(int c: ans) cout << c << " ";
	cout << en;
}

int main(){
	fast;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
	cin >> t;
    while(t--){
		solve();
	}
    return 0;
}