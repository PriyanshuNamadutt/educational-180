#include<iostream>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int a, x, y;
        cin >> a >> x >> y;
        if ( a < min( x, y) || a > max( x, y ) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
