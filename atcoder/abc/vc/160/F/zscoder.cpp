#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}

int modpow(int x, int p) {
  if(p==0) return 1;
  if(p&1) return mult(x, modpow(x, p-1));
  return modpow(mult(x, x), p/2);
}

int inverse(int x) {
  return modpow(x, MOD-2);
}

void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}
	
vi adj[222222];
int sub[222222];

void dfs(int u, int p=-1)
{
	sub[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		sub[u]+=sub[v];
	}
}

int dp[222222];
int dpup[222222];
int ans[222222];

void dfs1(int u, int p)
{
	int prod=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs1(v,u);
		prod=mult(prod,dp[v]);
		prod=mult(prod,ifact[sub[v]]);
	}
	prod=mult(prod,fact[sub[u]-1]);
	dp[u]=prod;
}
int par[333333];
int n; 
void dfs2(int u, int p)
{
	par[u]=p;
	for(int v:adj[u])
	{
		if(v==p) continue;
		//compute dpup[v]
		int totsiz = n-sub[v];
		dpup[v]=mult(dp[u],ifact[sub[u]-1]);
		dpup[v]=mult(dpup[v],inverse(dp[v]));
		dpup[v]=mult(dpup[v],fact[sub[v]]);
		if(u!=0)
		{
			dpup[v]=mult(dpup[v],dpup[u]);
			dpup[v]=mult(dpup[v],ifact[n-sub[u]]);
		}
		dpup[v]=mult(dpup[v],fact[totsiz-1]);
		dfs2(v,u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(333333);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0,-1);
	dfs1(0,-1);
	dfs2(0,-1);
	for(int i=0;i<n;i++)
	{
		int ans=fact[n-1];
		for(int v:adj[i])
		{
			if(v!=par[i])
			{
				ans=mult(ans,dp[v]);
				ans=mult(ans,ifact[sub[v]]);
			}
			else
			{
				ans=mult(ans,dpup[i]);
				ans=mult(ans,ifact[n-sub[i]]);
			}
		}
		cout<<ans<<'\n';
	}
}

