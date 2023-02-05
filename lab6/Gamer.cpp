#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e13

vector<vector<long long>> dist;

void floyd_warshall(vector<vector<long long>> graph, long long n){
    dist.resize(n);
    for (long i = 0; i < n; i++)
        dist[i].resize(n);

    for (long i = 0; i < n; i++)
        for (long j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
 
    for (long k = 0; k < n; k++){
        for (long i = 0; i < n; i++){
            for (long j = 0; j < n; j++){
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[i][k] != INF && dist[k][j] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    // n = equipments, m = relationships

    vector<vector<long long>> adj(n);
    for (long i = 0; i < n; i++)
        adj[i].resize(n);
    
    for (long i = 0; i < n; i++){
        for (long j = 0; j < n; j++){
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }

    for (long i = 0; i < m; i++){
        long a, b, w;
        cin >> a >> b >> w;
        // the upgrade cost fom a to b is w
        if (w < adj[a][b])
            adj[a][b] = w;
    }

    floyd_warshall(adj, n);

    // for (long i = 0; i < n; i++){
    //     for (long j = 0; j < n; j++)
    //         cout << adj[i][j] << " ";
    //     cout << endl;
    // }

    long k;
    cin >> k;
    // k = upgrades
    for (long i = 0; i < k; i++){
        long f, t;
        cin >> f >> t;
        //f = from, t = to
        if (dist[f][t] != INF)
            cout << dist[f][t] << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}