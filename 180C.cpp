#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) cin >> a[i];

        ll cnt = 0;
        int mx = a[n-1];
        for ( int i = 0; i < n-1; i++ ) {
            for ( int j = i+1; j < n; j++ ) {
                int tar1 = mx - a[i] - a[j];
                int tar2 = a[i] + a[j];

                ll left = upper_bound( a.begin() + (j+1), a.end(), tar1 ) - a.begin();
                ll right = lower_bound(a.begin() + (j+1), a.end(), tar2 ) - a.begin();


                if ( right - left > 0 ) cnt += right - left;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
