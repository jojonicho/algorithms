#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

const int N = 2e5 + 5;

int A[N];
vi G[N];

int n, k;
int u, v;

int dfs(int u, int p=-1) {
  for(auto v: G[u]) {
    if(v == p) continue;
    dfs(v, u);

  }
}

int main() {
  cin >> n >> k; // nTowns
  int nUni = 2*k;

  // 2k -> nUniversities
  for(int i=0; i<nUni; i++) cin >> A[i];

  for(int i=0; i<n-1; i++) {
    cin >> u >> v, u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  // divide 2k into k pairs

}
