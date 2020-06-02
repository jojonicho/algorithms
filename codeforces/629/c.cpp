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

void solve(){
	int n;
	cin >> n;
    string s;
    cin >> s;
    string a(n,'0'), b(n, '0');
    forn(i,n) {
        if(s[i] == '0') a[i] = b[i] = '0';
        if(s[i] == '2') a[i] = b[i] = '1';
        if (s[i] == '1') {
            a[i] = '1';
            b[i] = '0';
            for (int j = i + 1; j < n; ++j) {
                b[j] = s[j];
            }
            break;
        }
    }
    cout << a << en << b << en;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}