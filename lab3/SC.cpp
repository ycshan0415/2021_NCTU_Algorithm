#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <stdlib.h>
using namespace std;

bool cmp(pair<long, long> &a, pair<long, long> &b){
    return a.first < b.first;
}

long sol(vector<pair<long, long>> &boundaries, long L, long it){
    bool check = false;
    long cur;
    long max = 0;
    for (int i = it; i < boundaries.size(); i++){
        long curL = boundaries[i].first;
        long curR = boundaries[i].second;
        if (curL <= L && (curR - L) > max){
            cur = i;
            check = true;
            max = curR - L;
        }
        if (curL > L)
            break;
    }
    if (check == false){
        cout << 0;
        exit(0);
    }
    return cur;       
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n, p;
    cin >> n >> p;
    //n = # of applicable sections, p = rental fee
    long L, R;
    cin >> L >> R;

    vector<pair<long, long>> boundaries;
    for (int i = 0; i < n; i++){
        long l, r;
        cin >> l >> r;
        boundaries.push_back(make_pair(l, r));
    }
    sort(boundaries.begin(), boundaries.end(), cmp);
    /*
    for (auto it = boundaries.begin(); it !=  boundaries.end(); it++)
        cout << "{" << it->first << "," << it->second << "} ";
    */
    long count = 0;
    long it = 0;
    while (boundaries[it].second <= R){
        it = sol(boundaries, L, it);
        L = boundaries[it++].second;
        count++;
    }
    cout << count * p;
    
    return 0;
}