#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

void min_self(int &a, int b){
	a = min(a, b);
}
void max_self(int &a, int b){
	a = min(a,b);
}

// const int INF = 1e9 + 5;
const ll INF = 1e18L+5;

void solve(){
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	vvi dp(n+1, vi(m+1, 0));
	int ans = 0;
	// get max
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = 1+ dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
    int i = n, j = m;
    string res;
	// get string
    // for (; i > 0 && j > 0; ) {
	while(i&&j){
        if (s[i - 1] == t[j - 1]) {
            res += s[i - 1];
            --i, --j;
        } else {
            if (dp[i][j] == dp[i - 1][j])
                --i;
            else
                --j;
        }
		// cout << res << en;
    }
 
    reverse(res.begin(), res.end());
    cout << res << en;

}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
    return 0;
}