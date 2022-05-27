#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x1fffffffffffffff;
template<class T, class U> bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto& i : a) cin >> i;
    const ll cnt = 1 + (n & 1);
    vector<vector<ll>> dp(n + 2, vector<ll>(cnt + 1, -INF));
    dp[0][0] = 0;
    for(ll i = 0; i <= n; i++) for(ll j = 0; j <= cnt; j++){
        if(j < cnt) chmax(dp[i + 1][j + 1], dp[i][j]);
        if(i < n) chmax(dp[i + 2][j], dp[i][j] + a[i]); // 1個選んだら1個選ばないのもセット
    }
    cout << dp[n + 1][cnt] << endl; // なので floor(n / 2) * 2 + cnt == n + 1 に答えが入る
}
