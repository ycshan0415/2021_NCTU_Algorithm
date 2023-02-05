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
    //n = # of processes, c = # of cores, q = # of task
    vector<long> task(q);
    vector<long> key(n + 1);
    for (int i = 0; i <= n; i++)
        key[i] = 0;
    map<long, queue<long>> next;
    for (int i = 0; i < q; i++){
        cin >> task[i];
        next[task[i]].push(i);
    }
    bool* executing = new bool[q + 1];
    for(int i = 0; i <= q; i++)
        executing[i] = false;
    
    set<pair<long, long>> core;//next index, value
	set<long> core_value;

    long count = 0;
    for (int i = 0; i < q; i++){
        long int cur = task[i];
        auto it = core_value.find(cur);
		set<pair<long, long>>::iterator it2 = core.find(pair<long, long>(next[cur][key[cur]], cur));
        if(executing[cur] == true){
            next[cur].pop();
            if (key[cur] < next[cur].front()){
                core.insert(pair<long, long>(next[cur][key[cur]], cur));
            }
            else{
                core.insert(pair<long, long>(10000000, cur));
            }
        }
        else {
            if (core_value.size() < c){
                core_value.insert(cur);
                key[cur]++;
                if (key[cur] < next[cur].size()){
                    core.insert(pair<long, long>(next[cur][key[cur]], cur));
                }
                else{
                    core.insert(pair<long, long>(10000000, cur));
                }
            }
            else{
                core_value.erase(core_value.find((--core.end())->second));
                core_value.insert(cur);
                key[cur]++;
                core.erase(--core.end());
                if(key[cur] < next[cur].size()){
                    core.insert(pair<long, long>(next[cur][key[cur]], cur));
                }
                else{
                    core.insert(pair<long, long>(10000000, cur));
                }
            }
            
        }
    }
                
    cout << count;

    return 0;
}

/*long max = next[cur].front();
                for (int j = 0; i < c; j++){
                    if (next[core[j]].front() > max){
                        max = next[core[j]].front();
                        idx = j;
                    }
                }
            }
            core[idx] = cur;
            executing[core[idx]] = false;
        }
        else{
            if (!next[cur].empty())
                next[cur].pop();
        }*/