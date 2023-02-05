#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long int n, p;
    cin >> n >> p;
    //n = # of applicable sections, p = rental fee
    long int L, R;
    cin >> L >> R;

    set<pair<long, long>> boundaries;
    for (int i = 0; i < n; i++){
        long l, r;
        cin >> l >> r;
        boundaries.insert(make_pair(l, r));
    }

    long count = 0;
    auto itmax = boundaries.begin();
    while(L <= R){
        bool continuous = false;
        for (auto it = itmax; it != boundaries.end(); it++){
            long int curL = it->first;
            long int curR = it->second;
            if (curL > L)//沒辦法連起來
                break;
            if (curR >= R){
                count++;
                cout << count * p;
                return 0;
            }
            if (curL <= L && curR >= L){
                continuous = true;
                long int max = curR - L;
                for (auto it2 = it; it2 != boundaries.end(); it2++){
                    long int curL2 = it2->first;
                    long int curR2 = it2->second;
                    it = it2;
                    if (curL2 > L)
                        break;
                    if (curR2 >= R){
                        count++;
                        cout << count * p;
                        return 0;
                    }
                    if (curR2 >= L && curR2 - L > max){
                        max = curR2 - L;
                        itmax = it2;
                    }
                }
            }
        }
        L = itmax->second;
        itmax++;
        count++;
        if (continuous == false){
            cout << 0;
            return 0;
        }
    }

    return 0;
}