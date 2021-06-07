#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

int t;

void solve(){
	string ans = "";
    string s;
	cin >> s;
    ll cnt = 0;
    ll index;
    bool first = true;
	for(ll i = 0; i<s.size(); i++){
        char c = s[i];
        if(first){
            for(int i=0; i< atoi(&c); i++) {
                ans += '(';
            }
            ans += c;
            for(int i=0; i< atoi(&c); i++) {
                ans += ')';
            }
            index = atoi(&c) + 1;
            first = false;
        } else {
            if(c == '0'){
                ans += c;
                index = ans.length();
            } else {
                ll score = atoi(&c) - cnt;
                if(!score) {
                    ans.insert(index++, 1, c);
                } else {
                    if(score > 0) {
                        ll cur = 0;
                        for(ll i=0; i< score; i++) {
                            ans.insert(index++, 1, '(');
                        }
                        ans.insert(index++, 1, c);
                        ll ma = index;
                        for(ll i=0; i< score; i++) {
                            ans.insert(ma++, 1, ')');
                        }
                    }
                    else {
                        for(ll j=index; j<ans.size(); j++) {
                            if(score == 0) {
                                ans.insert(j++, 1, c);
                                index = j;
                                break;
                            }
                            if(ans[j] == ')') score++;
                        }
                    }
                }
            }

        }
        cnt = atoi(&c);
	}
    cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
    for(int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
		solve();
    }
}