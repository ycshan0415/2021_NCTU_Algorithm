#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long n, c, q;
    cin >> n >> c >> q;
    //n = # of processes, c = # of cores, q = # of tasks
    vector<long> order(n + 1);
    vector<long> key(n + 1);
    vector<vector<long>> farest(q + 1);
    vector<bool> executing;
    map<long, long> findcore;
    set<pair<long, long>> core;//next idx, value
    set<long> incore;
    
    for (int i = 0; i <= n; i++){
        order[i] = 0;
        key[i] = 0;
    }
    for (int i = 0; i < q; i++){
        long temp;
        cin >> temp;
        order[i] = temp;
        process[i].push_back(temp);
    }

    for (int i = 0; i < q; i++){
        if (key[order[i]] < process[order[i]].size()){
            auto itset = incore.find(order[i]);
            auto itsetpair = core.find(pair<long, long>(process[order[i]][key[order[i]]], order[i]);
            
        }
    }

    bool* executing = new bool[q + 1]{false};
    set<long> run;
    set<long> last;
    int count = 0;

    for (int i = 0; i < q; i++){
        long int cur = task[i];
        p1[cur]--;
        if(executing[cur]){
            if(p1[cur]){
                last.erase(process[cur][p1[cur]]);
                last.insert(process[cur][p1[cur]] - 1);
            }
            else{
                run.erase(cur);
                last.erase(process[cur][p1[cur]]);
                executing[cur];
                count--;
            }
            continue;
        }
        else if (count < c){
            if()
        }
        next[cur].pop();
        if (executing[cur] == true){
            if (next[cur].empty())
                change = cur;
            else
                if (next[cur].front() > far){
                    far = next[cur].front();
                    change = cur;
                }
        }
        else{
            executing[cur] = true;
            count++;
            if (next[cur].empty())
                change = cur;
            else{
                if (next[cur].front() > far){
                    far = next[cur].front();
                }
            }
            executing[far] = false;
            far = 0;
        }
    }
    cout << count;

    return 0;
}