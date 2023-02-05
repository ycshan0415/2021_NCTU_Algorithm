#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include<queue>
using namespace std;
#define INF 1e15

struct node{
    long long from;
    long long to;
    long long weight;
};

struct cmp{
    bool operator()(pair<long long, long long> &a, pair<long long, long long> &b){
        return a.second > b.second;
    }
};

vector<vector<pair<long long, long long>>> adjList;
vector<vector<pair<long long, long long>>> adjRe;
void addEdge(long long u, long long v, long long w){
    adjList[u - 1].push_back(make_pair(v - 1, w));
    adjRe[v - 1].push_back(make_pair(u - 1, w));
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n ,m;
    cin >> n >> m;
    //n = vertices, m = edges;
    adjList.resize(n);
    adjRe.resize(n);

    vector<node> graph;
    for (long long i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        node temp;
        temp.from = u - 1;
        temp.to = v - 1;
        temp.weight = w;
        graph.push_back(temp);
    }
    
    vector<long long> dist(n, INF);
    dist[0] = 0;
    vector<bool> visited(n, false);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
    pq.push(make_pair(0, dist[0]));
    while(!pq.empty()){
        pair<long long, long long> temp = pq.top();
        pq.pop();
        long long start = temp.first;
        visited[start] = true;

        for (auto i = adjList[start].begin(); i < adjList[start].end(); i++){
            long long cur = i->first;
            long long weight = i->second;
            if (!visited[cur] && dist[cur] > dist[start] + weight){
                dist[cur] = dist[start] + weight;
                pq.push(make_pair(cur, dist[cur]));
            }
        }
    }

    vector<long long> distRe(n, INF);
    distRe[n - 1] = 0;
    vector<bool> visitedRe(n, false);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pqRe;
    pqRe.push(make_pair(n - 1, distRe[n - 1]));
    while(!pqRe.empty()){
        pair<long long, long long> temp = pqRe.top();
        pqRe.pop();
        long long start = temp.first;
        visitedRe[start] = true;

        for (auto i = adjRe[start].begin(); i < adjRe[start].end(); i++){
            long long cur = i->first;
            long long weight = i->second;
            if (!visitedRe[cur] && distRe[cur] > distRe[start] + weight){
                distRe[cur] = distRe[start] + weight;
                pqRe.push(make_pair(cur, distRe[cur]));
            }
        }
    }

    for (long long i = 0; i < m; i++){
        long long before = dist[graph[i].from];
        // before the vertice
        long long after = distRe[graph[i].to];
        // after the vertice
        long long toN = dist[n - 1];
        // oringinal path

        long long diff = before + after + graph[i].weight - toN;
        if (diff <= graph[i].weight)
            cout << diff << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}