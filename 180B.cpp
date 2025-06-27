#include<iostream>
#include<vector>
using namespace std;

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }

    for ( int i = 0; i < n-1; i++ ) {
        if ( abs( a[i] - a[i+1]) <= 1 ) return 0;
    }

    for ( int i = 1; i < n-1; i++ ) {

        if ( (a[i] > a[i+1] && a[i] > a[i-1]) || (a[i] < a[i+1] && a[i] < a[i-1]) ) return 1;
    }

    return -1;
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        cout << solve() << endl;
    }
    return 0;
}
