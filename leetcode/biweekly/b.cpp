#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

// int t;

// bool canConstruct(string s, int k) {
//     if(s.size() < k) return false;
//     int a[26] = {};
//     for(char c : s)
//         a[c-'a']++;
//     int cnt = 0;
//     for(int i : a){
//         if(i!=0 && i % 2) cnt++;
//     }
//     return cnt <= k;
// }

void solve(){
	// int x, y, a ,b, c;
	// ll ans = 0;
	// cin >> x >> y >> a >> b >> c;
	// int A[a], B[b], C[c], cnt = x + y;
	// forn(i,a) cin >> A[i];
	// forn(i,b) cin >> B[i];
	// forn(i,c) cin >> C[i];
	// sort(A, A+a, greater<int>());
	// sort(B, B+b, greater<int>());
	// sort(C, C+c, greater<int>());
	// vi abc(x+y+c);
	// forn(i,x) abc.push_back(A[i]);
	// forn(i,y) abc.push_back(B[i]);
	// forn(i,c) abc.push_back(C[i]);
	// sort(abc.begin(), abc.end(), greater<int>());
	// forn(i,x+y) ans += abc[i];
	// cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    vi a = {1,1,1,2,9,3,1,2};
    priority_queue<int> maxHeap(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> maxHeap(a.begin(), a.end());

    int target[] = {1,1,1,2,9,3,1,2};
    priority_queue<int> pq2(target, target+8);
    // while(pq1.size()) {
    //     cout << pq1.top() << '\n';
    //     pq1.pop();
    // }
    // canConstruct("messi", 3);
	// cin >> t;
	// while(t--)
	// 	solve();
}