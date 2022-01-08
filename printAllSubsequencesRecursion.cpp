#include <bits/stdc++.h>
using namespace std;

void print ( vector<int> & a ) {
    if ( a.size() == 0) {
        cout << "[]" << endl;
        return;
    }
    for ( auto i : a ) cout << i << " ";
    cout << endl;
}


void subsequences(int ind , vector<int> & a , vector <int> & b , int n) {

    // this function will help in printing all subsequence of the given array A
    // subsequence is something which can have a contagious or non contagious array elements but following the order
    // eg :- A = [ 1  3  2]  subsequences will be [1 3]  , [ 1 3 2 ] , [ 1 2] , [1] , [3 2] , [3] , [2] , []
    // but [ 1 2 3 ] is not a subsequence.


    // base case
    if ( ind >= n) {
        print(b);
        return;
    }

    b.push_back(a[ind]);
    subsequences(ind + 1 , a , b , n );
    b.pop_back();
    subsequences(ind + 1 , a , b , n) ;

}

int main () {

    // all the subsets using recursion method

    int n ; cin >> n;

    vector<int> a ( n , 0 ) , b;
    for ( auto & i : a) cin >> i;

    subsequences( 0 , a , b , n);
}
