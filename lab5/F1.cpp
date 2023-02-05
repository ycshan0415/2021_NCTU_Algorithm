#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod 1000000007

struct node{
    long long x, y;
    long long length;
};

bool cmp(node a, node b){
    return a.length < b.length;
}

vector<long long> forest;

long long find (long long x){
    if (x == forest[x])
        return x;
    else{
        forest[x] = find(forest[x]);
        return forest[x];
    }
}

vector<bool> visited;
vector<vector<long long>> adj;
vector<long long> cities;

void DFS (long long v){
    visited[v] = true;
    for (auto it : adj[v])
        if(!visited[it]){
            DFS(it);
            cities[it]++;
            cities[v] += cities[it];
        }
    
}

void connect (node a){
    adj[a.x].push_back(a.y);
    adj[a.y].push_back(a.x);
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    //n = cities, m = cables
    visited.resize(n + 1, false);
    adj.resize(n + 1);
    cities.resize(n + 1, 0);
    forest.resize(n + 1);
    for (long long i = 0; i <= n; i++)
        forest[i] = i;
    
    vector<node> cable(m);
    for (long long i = 0; i < m; i++)
        cin >> cable[i].x >> cable[i].y >> cable[i].length;
    sort(cable.begin(), cable.end(), cmp);

    vector<node> graph;
    long long km = 0;
    long edge = 0;
    for (long long i = 0; i < m; i++){
        if (find(cable[i].x) != find(cable[i].y)){        
            forest[find(cable[i].x)] = find(cable[i].y);
            graph.push_back(cable[i]);
            connect(cable[i]);

            km += cable[i].length;
            km %= mod;
            edge++;
            if (edge >= n - 1)
                break;
        }
    }

    DFS(1);
    cities[1]++;
    
    if (edge == n - 1){
        long long construction = km;
        construction *= 2;
        construction %= mod;

        long long data = 0;
        for (long long i = 0; i < graph.size(); i++){
            long long c1 = cities[graph[i].x];
            long long c2 = cities[graph[i].y];
            long long aside = min(c1, c2);
            long long time = aside * (n - aside) % mod;
            long long fee = graph[i].length * 2 * time % mod;
            data += fee;
            data %= mod;
        }

        cout << construction << " " << data;
    }
    else
        cout << "-1";

    return 0;
}