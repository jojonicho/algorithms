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
ll n, m, ans=0;

void solve(){
	cin >> n;
	//k<-[2,n] until n<k:
	for(ll i=2; i*i<=n; i++){
		m = n;
		while(m%i==0) m/=i;
		if(m%i==1) ans++;
		if(n%i==1) ans++;
		if(n==i*i+1) ans--;
	}
	ans += 2;
	if(n==2) ans=1;
	cout << ans << en;
}

void solve2(){
  ll n,a;
  cin>>n;
  ll ans=1;
  for(ll i=2;i*i<=n;i++){
    if(n%i==1){
      if(i*i==n-1) ans++; 
      else ans+=2;
    }
    else if(n%i==0){
      a=n;
      while(a%i==0){
        a/=i;
      }
      if(a%i==1) ans++;
    }
  }
  if(n!=2) ans++;
  cout<<ans<<endl;
  
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