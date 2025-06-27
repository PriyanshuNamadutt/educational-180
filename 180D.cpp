#include<bits/stdc++.h>
using namespace std;

int N = 2e5 + 5;

void print( vector<pair<int,int>> &ans ) {
    for ( int i = 0; i < ans.size(); i++ ) {
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
}

void dfs( int node, vector<int> &vis, vector<int> (&adj)[], vector<pair<int,int>> &ans, bool check ) {

    vis[node] = 1;
    for( auto it : adj[node] ) {
        if ( !vis[it] ) {

            if ( check ) ans.push_back( {node, it} );
            else ans.push_back( {it, node} );

            dfs( it, vis, adj, ans, !check );
        }
    }
}

int main () {
    int t; cin >> t;
    while ( t-- ) {

        int n; cin >> n;
        vector<int> adj[N];
        for ( int i = 1; i < n; i++ ) {
            int u, v;
            cin >> u >> v;
            u-- , v--;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int i = 0;
        while ( i < n && adj[i].size() != 2 ) {
            i++;
        }
        if ( i >= n ) {
            cout << "NO" << endl;
            continue;
        }

        vector<pair<int,int>> ans;
        vector<int> vis( n, 0 );
        ans.push_back( { i, adj[i][0] } );
        ans.push_back( { adj[i][1], i } );
        vis[i] = 1;

        dfs( adj[i][0], vis, adj, ans, false );
        dfs( adj[i][1], vis, adj, ans, true );

        cout << "YES" << endl;
        print(ans);

    }
    return 0;
}
