#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for(ll i=0; i<(n); i++)
#define fori(i,k,n) for(ll i=k; i<(n); i++) 

int T;
vector<int> p, d;
vector<int> tin, tout;
vector<vector<int>> tree;

void dfs(int v, int par = -1, int dep = 0) {
	p[v] = par;
	d[v] = dep;
	tin[v] = T++;
	for (auto node : tree[v]) {
		// if current node == parent
		if (node == par) continue;
		// pass in parent to par param
		dfs(node, v, dep + 1);
	}
	tout[v] = T++;
}

bool isAnc(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	T = 0;
	p = d = vector<int>(n);
	tin = tout = vector<int>(n);
	tree = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		// tree edges
		--x, --y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(0);
	
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> v(k);
		for (auto &it : v) {
			cin >> it;
			--it;
		}
		
		int u = v[0];
		// d is vector for number of decendants
		// finding vertex with most descendants
		for (auto it : v) if (d[u] < d[it]) u = it;
		for (auto &it : v) {
			if (it == u) continue;
			// if not root
			if (p[it] != -1) it = p[it];
		}
		bool ok = true;
		for (auto it : v) ok &= isAnc(it, u);
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}