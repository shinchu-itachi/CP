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

void fast_io(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    
}

ll int arr[MAX];
ll sg[4*MAX];

void build(ll int root,ll low,ll high){
	if(low==high){
		sg[root] = arr[low];
		return ;
	}

	ll mid = (low + high) >> 2 ;
	build(2*root+1 , low , mid);
	build(2*root+2 , mid+1 , high);
	sg[root] = sg[2*root+1];
}

void update(ll root , ll low, ll high , ll ind , ll val){
	if(low == high){
		sg[low] = val;
		return ;
	}

	ll mid = (low+mid) >> 2;
	if(ind<=mid and ind>=low)
		update(2*root+1 , low , mid , ind , val );
	else update(2*root+2 , mid+1 , high , ind , val );

	sg[ind] = sg[2*root+1];
}


void solve(){
	ll int n , q ;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	   cin>>arr[i];
	build(0,0,n-1);
	forco(sg) cout<<c<<" ";
	cout<<endl;
	for(int i=0;i<q;i++){
		ll int ch,l,r;
		cin>>ch;
		if(ch==2) cin>>l , cout<<sg[l-1]<<endl;
		if(ch==1) cin>>l>>r , update(0,0,n-1,l-1,r-1);
	}
}

signed main(){
	fast_io();
	int t=1;//cin>>t;
	while(t--)
	  solve();
 return 0;
}