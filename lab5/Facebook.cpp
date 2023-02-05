#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

struct node{
    long a, b;
    char type;
};

vector<long> group;

long find (long x){
    //return x == group[x] ? x : (group[x] = find(group[x]));
    if (x == group[x])
        return x; 
    else{
        group[x] = find(group[x]);
        return group[x]; 
    }
}

void merge (long x, long y){//connect
    long fx = find(x);
    long fy = find(y);
    if (fx == fy)
        return;
    group[fx] = fy;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long n, m, q;
    cin >> n >> m >> q;
    //n = people, m = relationships, q = events
    group.resize(n);
    for (long i = 0; i < n; i++)
        group[i] = i;
    
    set<pair<long, long>> friends;
    for (long i = 0; i < m; i++){
        long x, y;
        cin >> x >> y;
        long a = min(x, y);
        long b = max(x, y);
        pair<long, long> temp;
        temp = make_pair(a, b);
        friends.insert(temp);
    }

    vector<pair<long, long>> unfriend;
    vector<node> list(q);
    for (long i = 0; i < q; i++){
        cin >> list[i].type >> list[i].a >> list[i].b;
        if (list[i].type == 'A')
            NULL;
        else if (list[i].type == 'U'){
            long a = min(list[i].a, list[i].b);
            long b = max(list[i].a, list[i].b);
            pair<long, long> temp;
            temp = make_pair(a, b);
            unfriend.push_back(temp);
        }
    }

    for (long i = 0; i < unfriend.size(); i++)
        friends.erase(unfriend[i]);

    for (auto &it : friends)
        merge(it.first, it.second);
        // group[find(it.first)] = find(it.second);

    vector<bool> ans;
    for (long i = q - 1; i >= 0; i--){
        if (list[i].type == 'A'){
            if (find(list[i].a) == find(list[i].b))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        else if (list[i].type == 'U')
            merge(list[i].a, list[i].b);
            // group[find(list[i].a)] = find(list[i].b);
    }

    for (long i = ans.size() - 1; i >= 0; i--){
        if (ans[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}