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
const int MAX = 1e5 + 7;
const int MAXG = 10;

void fast_io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

}

ll costchange(vector<int> &change, int m, int n) {
	if (m == 0)
		return 0;
	if (n == 0)
		return 1;
	if (m <= 0 && n >= 0)
		return 0;
	else return costchange(change, m - 1, n) + costchange(change, m, n - change[n - 1]);


}

void solve() {
	int n; cin >> n;
	int k; cin >> k;
	vector<int> change(k + 1, 0);
	for (auto &i : change) cin >> i;

	cout << costchange(change, k, n) << endl;
}

signed main() {
	fast_io();
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}
