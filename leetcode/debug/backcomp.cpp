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

bool backspaceCompare(string S, string T) {
    int i = S.size() - 1, j = T.size() - 1;
    if(S[i] != T[j]) return false;
    while(i>=0 && j>=0){
        if(S[i] == T[j]) {
            if(S[i] == '#' && T[j] == '#') {
                int cns = 1, cnt = 1;
                while(S[--i] == '#') cns++;
                while(T[--j] == '#') cnt++;
                i -= cns;
                j -= cnt;
            // cout << T[j] << " at index " << j << endl;
            }
            else {
            --i; --j;
            }
            // cout << S[i] << " at index " <<  i << endl;
            // cout << T[j] << " at index " << j << endl;
        }
        if(i>=0 && S[i] == '#' || j >= 0 && T[j] == '#' ) {
            if(i>=0 && S[i] == '#') {
                int cns = 1;
                while(S[--i] == '#') cns++;
                i -= cns;
                // cout << S[i] << " at index " <<  i << endl;
            }
            if(j >= 0 && T[j] == '#') {
                int cnt = 1;
                while(T[--j] == '#') cnt++;
                j -= cnt;
                // cout << T[j] << " at index " << j << endl;
            }
            continue;
        }
        if(i>=0 && j>= 0 && S[i] != T[j]) {
            // cout << S[i] << " at index " <<  i << endl;
            // cout << T[j] << " at index " << j << endl;
            return false;
        }
        // else {
        //     // cout << S[i] << " at index" <<  i << endl;
        //     // cout << T[j] << " at index " << j << endl;
        //     return false;
        // }      
    }
    if(i>=0 && S[i] == '#') --i;
    if(j>=0 && T[j] == '#') --j;
    // cout << i << " " << j << endl;
    return (j <= -1 && i <= -1);
}
void solve(){
    cout << backspaceCompare("ab#c","ad#c");
    cout << backspaceCompare("ab##", "c#d#");
    cout << backspaceCompare("a##c", "#a#c");
    cout << backspaceCompare("a#c", "b");
    // cout << backspaceCompare("ab#c","ad#c");
    // cout << backspaceCompare("xywrrmp","xywrrm#p");
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
    // int t; cin >> t;
    int t=1;
    while(t--)
        solve();
    return 0;
}