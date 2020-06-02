#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG
#ifndef DEBUG
#define endl "\n"
#define log(args...)
#else
#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); logf(_it, args); }
void logf(istream_iterator<string> it) {
}
template<typename T, typename ... Args>
void logf(istream_iterator<string> it, T a, Args ... args) {
	cout << *it << " = " << a << endl;
	logf(++it, args...);
}
#endif
 
#define forn(i,k,n) for(ll i=(k); i<(n); i++)
 
const double PI = acos(-1);
typedef long long ll;
#define fori(n) for(ll i=0; i<(n); i++)
 
#define cins(s) string s; cin>>s;
#define cini(i) int i; cin>>i;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cinai(a, n) vi a(n); fori(n) { cin>>a[i]; }
#define cinall(a, n) vll a(n); fori(n) { cin>>a[i]; }
#define cinas(s, n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a, n) vd a(n); fori(n) { cin>>a[i]; }
 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;
typedef vector<ll> vll;
 
void solve() {
	cini(k);
	cini(n);
	vi a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
 
	int ma = 0;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		ma = max(ma, abs(prev - a[i]));
		prev = a[i];
	}
 
	ma = max(ma, k - a.back() + a[0]);
 
	ll ans = k - ma;
	cout << ans << endl;
 
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}