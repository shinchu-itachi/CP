
#include<bits/stdc++.h> 
using namespace std;
 
 
#define all(c) c.begin(),c.end()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(__gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout(x) freopen(x, "w", stdout)
#define filein(x) freopen(x, "r",stdin)
#define error(x) freopen(x,"w",stderr)
#define sqr(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define inf 1<<30
#define mod 1000000007
#define pi acos(-1.)
#define valid(x,y,row,col) (((x) >= 0 and (x) < row) and ((y) >= 0 and (y) < col))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define timer(d) for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))
 
 
int x4[] = {0,0,1,-1};
int y4[] = {1,-1,0,0};
 
void makeTree(vector<pair<ll,ll> > & tree, vector<ll> & ara, int b, int e, int node)
{
    if(b == e){
        tree[node].first = ara[b];
        tree[node].second = 0;
        return;
    }
    int left = node << 1;
    int right = left+1;
    int mid = (b+e) >> 1;
    makeTree(tree,ara,b,mid,left);
    makeTree(tree,ara,mid+1,e,right);
 
    tree[node].first = tree[left].first + tree[right].first;
}
 
ll query(vector<pair<ll,ll> > & ara, int b, int e,int node, int i, ll carry)
{
    if(b > i or e < i){
        return 0LL;
    }
    if(b >= i and e <= i){
        return ara[node].first+(carry*(e-b+1));
    }
    int left = node << 1;
    int right = left+1;
    int mid = (b+e) >> 1;
 
    ll x = query(ara,b,mid,left,i,carry+ara[node].second);
    ll y = query(ara,mid+1,e,right,i,carry+ara[node].second);
 
    return (x+y);
}
 
void update(vector<pair<ll,ll> > & ara, int b, int e, int node, int i, int j, int  u)
{
    if(b > j or e < i){
        return;
    }
    if(b >= i and e <= j){
        ara[node].first+=((e-b+1)*u);
        ara[node].second+=u;
        return;
    }
    int left = node << 1;
    int right = left+1;
    int mid = (b+e) >> 1;
 
    update(ara,b,mid,left,i,j,u);
    update(ara,mid+1,e,right,i,j,u);
 
    ara[node].first = ara[left].first+ara[right].first + ara[node].second*(e-b+1);
}
 
int main()
{
    sync();
    int n,q;
    cin >> n >> q;
    vector<ll> ara(n+1);
    vector<pair<ll,ll> > tree(4*n);
    for(int i = 1; i <= n; ++i){
        cin >> ara[i];
    }
    makeTree(tree,ara,1,n,1);
    int a,b,x,y;
    for(int i = 0; i < q; ++i){
        cin >> a;
        if(a == 1){
            cin >> b >> x >> y;
            update(tree,1,n,1,b,x,y);
        }else{
            cin >> b;
            cout << query(tree,1,n,1,b,0LL) << endl;
        }
    }
    return 0;
}
