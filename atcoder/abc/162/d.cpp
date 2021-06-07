#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define fork(i,n) for(ll i=0; i<(n); i++)
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


void tle(){
	int n, ans=0;
	string s;
	cin >> n >> s;
	if(n<3) {
		cout << 0 << en;
		return ;
	}
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++) {
			if(s[i] == s[j]) continue;
			for(int k=j+1; k<n; k++){
				if(s[i]==s[k]) continue;
				if(s[j]==s[k]) continue;
				if(j-i == k-j) continue;
				ans++;
			}
		}
	}
	cout << ans << en;
}

void solve(){
	ll n, r=0,g=0,b=0;
	string s;
	cin >> n >> s;
	for(int i=0; i<s.size();i++){
		if(s[i]=='R') r++;
		if(s[i]=='G') g++;
		if(s[i]=='B') b++;
	}
	ll ans = r*g*b;
	fork(i,n) fork(h,n){
		int j = i+h, k=j+h;
		if(k>=n) break;
		if(s[i]!=s[j]&&s[j]!=s[k]&&s[i]!=s[k])ans--;
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
    int t = 1;
    while(t--)
        solve();
    return 0;
}