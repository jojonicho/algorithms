#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vii vector<vector<int>>


int maxEvents(vector<vector<int>>& events) {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(events.begin(), events.end());
    int ans = 0, n = events.size(), j = 0;
    for (int i = 1; i<1e5; ++i) {
        while (pq.size() && pq.top() < i)
            pq.pop();
        while (j < n && events[j][0] == i)
            pq.push(events[j++][1]);
        if (pq.size()) {
            pq.pop();
            ++ans;
        }
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    vi v;
    // cin >> A;
    int myints[] = {1,3,4};
    // cout << sizeof(myints);
    // v = v(myints);
    vi fifth (myints, myints + sizeof(myints) / sizeof(int) );
    for (auto c: fifth)
    cout << c << "\n";

    vii events = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
    // vii events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]];
    cout << maxEvents(events);
}