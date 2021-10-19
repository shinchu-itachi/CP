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
const int MAX = 2e5+7;
const int MAXG = 10;


ll arr[MAX];
ll sg[4*MAX];

void fast_io(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    
}

void build(ll root , ll low , ll high){
	if(low == high){
		sg[root] = arr[low];
		return ; 
	}

	ll mid = (low+high)/2;
	build(2*root+1 , low , mid);
	build(2*root+2 , mid+1 , high);

	sg[root] = min(sg[2*root+1],sg[2*root+2]);
}

ll query(ll root , ll low,ll high , ll l, ll r){
	if(low>=l and high <= r) return sg[root];
	if(l > high || r < low) return LONG_MAX;
	ll mid = (low+high)/2;
	ll left = query(2*root+1,low,mid,l,r);
	ll right = query(2*root+2,mid+1,high,l,r);
	return min(left,right);
}

void  update(ll root , ll low,ll high  ,ll ind , ll val){
	if(low == high){
		arr[ind] = val;
		sg[root] = val;
		return ;
	}

	ll mid = (low+high) /2;
	update(2*root+1,low,mid,ind,val);
	update(2*root+2,mid+1,high,ind,val);

	sg[root] = min(sg[2*root+1],sg[2*root+2]);
}

void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	build(0,1,n);

	while(m--){
		ll ch,l,r;
		// cin>>ch>>l>>r;
		// if(ch==1)
		// 	update(0,1,n,l,r);
		cin>>l>>r;
			cout<<query(0,1,n,l,r)<<endl;
	}
}

signed main(){
	fast_io();
	int t=1;
	while(t--)
	  solve();
 return 0;
}