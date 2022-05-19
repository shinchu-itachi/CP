/*
     ContestName     =   Shinchu_itachi
   " Walking on the road not taken with my own gutts.. "
*/


#include <bits/stdc++.h>
using namespace std ;
using namespace chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vi vector<int>
#define nline "\n"
#define inf (ll)1e18
#define iinf (int)2e9
#define eb emplace_back
#define vb vector<bool>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define nline "\n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fs first
#define sc second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define oset ordered_set

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define working cerr << "Working here.." << "\n" ;
#else
#define working
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(priority_queue<T> v);
template <class T> void _print(ordered_set<T> st);
template <class T, class V> void _print(unordered_map<T, V> m);

template <class T, class V> void _print(unordered_map<T, V> m) {cerr << "{ "; for (auto i : m) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(ordered_set<T> st) {cerr << "{ "; for (auto i : st) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(priority_queue<T> v) {cerr << "{ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << " }";}
template <class T> void _print(stack<T> v) {cerr << "[" ; while (!v.empty()) {_print(v.top()); cerr << " " ; v.pop();} cerr << "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for (auto i : v) {_print(i); cerr << " " ;} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fs); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*--------------------------------------------------------------------------------------------------------------------------------*/
ll power(ll a, ll b) {ll res = 1; while (b) {if (b & 1) {res *= a;} b /= 2; a *= a;} return res ;}
ll mod_pow(ll a, ll b, ll mod = (ll)(1e9 + 7)) {ll res = 1; while (b) {if (b & 1) {res = (res * a) % mod;} b /= 2; a = (a * a) % mod;} return (res % mod) ;}
void usaco (string filename = "") {if (sz(filename)) { freopen((filename + ".in").c_str() , "r", stdin); freopen((filename + ".out").c_str() , "w", stdout); } }
inline ll modadd (ll a , ll b , ll mod = (ll)(1e9 + 7)) { return (a + b) - (a + b >= mod ? mod : 0); }
void print128(__int128 x) { if (x < 0) { putchar('-'); x = -x; } if (x > 9) print128(x / 10); putchar(x % 10 + '0');}
/*--------------------------------------------------------------------------------------------------------------------------------*/
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
   size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};


/*---------------------------------------------------------------------------------------------------------------------------------*/

const ll mod = 1e9 + 7 , mod0 = 998244353, mod1 = 1e9 + 9 ;
const ll N = 2e5 + 10  ;

int n ; 
vector<int> arr  , bit ( N );

void update( int i , int val , int prevalue ){
        for (  i ; i <= n ;  i = i + ( i & -i))
                bit[i] += ( val - prevalue);
}

int sum ( int i ){
        // sum functions return sum till the ith index 
        int s = 0 ;

        for (  i ; i > 0 ; i = i - ( i & -i))   // please look it carefully
                s += bit[i];

        return s;
}

void solve() {
        // implementing the fenwick tree here , it is helpful in find the range sum query problem a
        // also findding the answer for array count inversinon

        // so there are two basic operation in fenwick tree
        // one is to find the sum 
        // another is to update the tree

        // so basically we first create an fenwick or BIT 

        // one more thing , i & -i helps in getting the righmost set bit in i 
        // example : -         i  ===  1101100
        // rightmsot bit   ->              -  

        // so -i gives two's complement of the number i 
        // so                 -i  ===  0010100

        // so when we do     i  ==== 1101100
        // so             & -i  ==== 0010100
        //                           --------
        //                           0000100

        // so we got the rightmost set bit
        // now when we do i - ( i & -i) we got == a number which rightmost set bit have been removed and its previou to i
        
        int q;
        cin >> n >> q;

        arr.resize(n , 0 );

        for ( auto &i : arr) cin >> i ; 

        // now we have to create a fenwick tree 
        // basically we create a fenwick tree only with 1 based index 
        // now zero as while removing the last set index from a number can lead to infinite loop
        // here by update we will update the value with the new value 

        for ( int i = 0 ; i < n ; i ++){
                update( i + 1 , arr.at(i) , 0);
        }

        // so above we have created the BIT

        // now computing the sum for the type queries
        for ( int i = 0 ; i < q ; i++){
                int ch , l , r ;  cin >> ch >> l >> r;

                // since the index will be zero based and our bit tree is 1 based so we will update the value of l and r

                if ( ch == 1 ){
                // since we have to update the bit with new values we will send the old value to
                // so that we can update the new value by  preval + ( updateval - preval )
                   update ( l + 1 , r  , arr[l]);

                   // remember one thing afte update you have to update the array value to for the further update
                   arr[l] = r ;
                }

                if ( ch == 2){
                        cout << sum (r+1) - sum ( l ) << endl;
                }


        }

}



inline void testcases() {
   int test = 1, testcase = 1 ;
   cin >> test ;

   cout << setprecision(12) ;
   cerr << setprecision(8) ;
   while (test --) {
      // cout << "Case #" << testcase++ << ": ";
      solve () ;
   }
}





int main () {
   fastio();

#ifndef ONLINE_JUDGE
   // freopen("output.txt", "w", stdout);
   // freopen("input.txt", "r", stdin);
   //freopen("error.txt", "w", stderr);
#endif

   auto start = high_resolution_clock::now();

   testcases();

   auto end = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(end - start);

   cerr << "Time : " << duration.count() / 1000 ;
}
