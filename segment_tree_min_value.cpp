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
const int MAX = 4e6+7;
const int MAXG = 10;

// vector<int> arr(MAX);
// vector<int> sg (4*MAX);
ll int arr[MAX];
ll int sg[MAX];


void fast_io(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    
}



void build(ll int root ,ll int low ,ll int high){
      if(low==high){
            sg[root] = arr[low];
            return ;
      }

      ll int mid = (low + high) /2 ;
      build(2*root + 1 , low , mid);
      build(2*root + 2 , mid+1,high);

      sg[root] = min(sg[2*root+1] , sg[2*root+2]);
}

ll int query(ll int root , ll int low,ll int high , ll int l ,ll int r){
            if(low >= l && high <= r) return sg[root];
            if(high < l || low > r) return LONG_MAX;
            ll int mid = (low+high)/2;
            ll int left = query(2*root + 1,low ,mid , l ,r);
            ll int right = query(2*root + 2,mid+1,high,l,r);
            return min(left,right);
}

void update(ll int root ,ll int low ,ll int high ,ll int ind ,ll int val){
      
      if(low==high){
            arr[ind] = val;
            sg[root] = val;
            return ;
      }
      
            ll int mid = (low+high)/2;
            if(ind >= low && ind <= mid)
                  update(2*root+1 , low , mid , ind , val);
            else  update(2*root+2 , mid+1 , high , ind , val);
      
      sg[root] = min(sg[2*root+1],sg[2*root+2]);
}

void solve(){
      ll int n,m;cin>>n>>m;
      for(int i=0;i<n;i++) cin>>arr[i];
      build(0 , 0 , n-1);
      // for(int i=0;i<n;i++)
      //       cout<<sg[i]<<" ";
      // cout<<endl;
      // int q;cin>>q;
      for(int i=0;i<m;i++){
           ll int l=0,r=0,ch=0;
            cin>>ch>>l>>r;
            if(ch==2){
            cout << query(0,0,n-1,l-1,r-1)<<endl;
            }
            else if(ch==1){
               update(0,0,n-1,l-1,r);
               }
      }
}

signed main(){
    fast_io();
    int t=1;
    // cin>>t;
    while(t--)
      solve();
 return 0;
}