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

char alp[26] = {'a','b','c','d','e','f',
'g','h','i','j','k','l','m','n','o','p',
'q', 'r', 's', 't', 'u', 'v', 'w','x','y','z'};

void solve(){
	int a, n, b;
	cin >> n >> a >> b;
	string ans, s;
	// a=5 b=5 abcde
	// a=5 b=4 aabcd
	for(int i=0; i<a-b+1; i++)
		s+='a';
	for(int i=0; i<n-a+b-1; i++)
		s+='a'+i+1;
	forn(i,n)
		ans+= s[i%a];
	cout << ans << en;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    int t; 
	cin >> t;
    while(t--)
        solve();
    return 0;
}