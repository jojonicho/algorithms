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
//7 8
//6 9
//5 5
//4 4
//3 7
//2 1
void solve(){
	int n, k;
	// a[0] = 0;
	// a[1] = 0;
	// a[2] = 1;
	// a[3] = 7;
	// a[4] = 4;
	cin >> n >> k;
	vi ans(n);
	forn(i,n){
		int cnt=0;
		vi a(7);
		string s;
		cin >> s;
		forn(i,7){
			a[i]=s[i];
			if(a[i] == 1) cnt++;
		}
		int tot = cnt + k;
		if(i<n-1){
					if(tot >= 7) {
			ans[i]=8;
		} else if(tot >= 6){
			if(a[4]==0){
				ans[i]=9;
			} else if(a[2]==0){
				ans[i]=6;
			} else if(a[3]==0){
				ans[i]=0;
			}
		} else if(tot>=5){
			if(a[2]==a[4]==0){
				ans[i]=5;
			} else if(a[1]==a[4]==0){
				ans[i]=3;
			} else if(a[1]==a[5]==0){
				ans[i]=2;
			}
		} else if(tot >= 4){
			if(a[0]==a[4]==a[6]==0){
				ans[i]=4;
			}
		} else if(tot>=3){
			if(a[1]==a[3]==a[4]==a[6]==0){
				ans[i]=7;
			}
		} else if(tot>=2){
			if(a[0]==a[3]==a[6]==0){
				ans[i]=1;
			}
		} else {
			// ans[i]=-1;
			cout << -1 << en;
			return ;
		}
		}
		if(tot == 7) {
			ans[i]=8;
		} else if(tot == 6){
			if(a[4]==0){
				ans[i]=9;
			} else if(a[2]==0){
				ans[i]=6;
			} else if(a[3]==0){
				ans[i]=0;
			}
		} else if(tot==5){
			if(a[2]==a[4]==0){
				ans[i]=5;
			} else if(a[1]==a[4]==0){
				ans[i]=3;
			} else if(a[1]==a[5]==0){
				ans[i]=2;
			}
		} else if(tot == 4){
			if(a[0]==a[4]==a[6]==0){
				ans[i]=4;
			}
		} else if(tot==3){
			if(a[1]==a[3]==a[4]==a[6]==0){
				ans[i]=7;
			}
		} else if(tot==2){
			if(a[0]==a[3]==a[6]==0){
				ans[i]=1;
			}
		} else {
			// ans[i]=-1;
			cout << -1 << en;
			return ;
		}
		k-= a[i]-cnt;
	}
	print(ans);
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while(t--)
        solve();
    return 0;
}