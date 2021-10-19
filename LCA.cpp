/*----     
        |\   |   | /  
        | \  |   |/     code created by SINCHU_ITACHI
        |  \ |   |\    "Fal ka kya hain Ache Karmas krtey raho , Fal market se le lena"
        |   \|   | \                                                                    -------*/                   
                                
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/math/constants/constants.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define ll          long long
#define fn0         for(int i=0 ; i<n  ; ++i)
#define fe0         for(int i=0 ; i<=n ; ++i)
#define fn1         for(int i=1 ; i<n  ; ++i)
#define fe1         for(int i=1 ; i<=n ; ++i)
#define forci(x)    for(auto &c:x)
#define forco(x)    for(auto c:x)
#define scn(x)      scanf("%lld",&x);
#define pb          push_back
#define set_bit(x)  __builtin_popcountll(x)
#define mod         1000000007
#define all(x)      (x).begin(), (x).end()
#define dll(x)      (x).begin(), (x).end(),greater<int>()
#define endl        "\n"
const int MAX = 1e5+7;
const int MAXG = 10;

void fast_io(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    
}


vector<int> grp[MAX];
int par[MAX],visited[MAX],dis[MAX];

void dfs(int node,int parent,int d){
	visited[node]=1;
	dis[node] = d;
	par[node] = parent;
	for(auto i:grp[node]){
	  if(visited[i]==0){
	  	dfs(i,node,dis[node]+1);
	  }
	}
}

void solve(){
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++) visited[i]=0, par[i] = 0;

	for(int i=0;i<m;i++){
		cin>>a>>b;
		grp[a].pb(b);
		grp[b].pb(a);
	}

	for(int i=1;i<=n;i++){
		if(visited[i]==0)
			dfs(i,-1,0);
	}
	int x,y;
	cin>>x>>y;
	if(dis[x]<=dis[y])
		swap(dis[x],dis[y]);
	int d = (dis[x]-dis[y]);
	while(d--){
		x = par[x];
	}
    if(x==y){
     cout<<x<<endl;
     exit(0);
    }
	while(par[x]!=par[y])
		x = par[x],y= par[y];
	cout<<par[x]<<endl;
}

signed main(){
	fast_io();
	int t;t=1;
	cin>>t;
	while(t--)
	  solve();
 return 0;
}