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
	int n, k;
	cin >> n >> k;
	vi a(n);
	for(auto &it: a) cin >> it;
	/* evt[i]=sum events at index i */
	vi evt(2*k+2);
 
    for(int i=0; i<n/2; i++) {
        int mi=min(a[i], a[n-1-i]);
        int ma=max(a[i], a[n-1-i]);
        evt[1]+=2;
        evt[mi+1]-=1;
        evt[mi+ma]-=1;
        evt[mi+ma+1]+=1;
        evt[ma+k+1]+=1;
    }
    
    int ans=1e18;
    int sum=0;
    for(int i=1; i<evt.size(); i++) {
        sum+=evt[i];
        ans=min(ans, sum);
    }
 
    cout<<ans<<en;
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