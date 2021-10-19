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
ll fen[MAX];


void fast_io(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    
}

void update(ll i , ll r , ll m) {
        while(i <= m){
             fen[i] += r ; 
             i = i + (i & (-i));
        }

}

ll sum(ll i){
        ll s = 0;
        while( i > 0 ){

                s += fen[i] ;
                cout<<fen[i] <<" "<<s<<endl;
                i =i - (i & (-i)) ;

        }

        return s;
}

void solve(){
   int n;cin>>n;
   string s; cin>>s;
   int c_r =0 , c_b =0 ;
   for(int i=0;i<n;i++){ 
        if(s[i]=='B') c_b ++ ;
        else if(s[i]=='R') c_r++;
   }

   for(int i=0;i<n;i++){
        if(s[i] == '?'){
                if(c_r >= c_b){
                        s[i] = 'B';
                        c_b ++;
                }

                else s[i] = 'R' , c_r ++;
        }

        else if(s[i]=='B') c_b++;
        else if(s[i] == 'R') c_r++;
   }

   cout<<s<<endl;
}

signed main(){
    fast_io();
    int t=1;cin>>t;
    while(t--)
      solve();
 return 0;
}