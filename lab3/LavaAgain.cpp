#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct element{
    long double point, people;//fixed
    long double earned, member;//changing  
};

struct cmp{
    bool operator()(element a, element b){
        long sendA = a.member + 1;
        long sendB = b.member + 1;
        long totalA = a.people + sendA;
        long totalB = b.people + sendB;
        long double preA = a.point / totalA * sendA;
        long double preB = b.point / totalB * sendB;
        long double newA = preA - a.earned;
        long double newB = preB - b.earned;
        //和上一輪比"多拿"幾分
        return newA < newB;
        //priority_queue的cmp會是反的
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double n, k;
    cin >> n >> k;
    //n = # of furniture, k = # of members
    priority_queue<element, vector<element>, cmp> pq;
    element temp;
    for (int i = 0; i < n; i++){
        //long point, people;
        cin >> temp.point >> temp.people;
        //temp.point = point;
        //temp.people = people;
        temp.earned = temp.member = 0;
        pq.push(temp);
    }
    for (int i = 0; i < k; i++){
        element temp = pq.top();
        // if (temp.member == 0)
        //     temp.member = 1;
        // else
            temp.member++;
        long total = temp.people + temp.member;
        long double value = temp.point / total * temp.member;
        temp.earned = value;
        pq.pop();
        pq.push(temp);
    }
    long double ans = 0;
    for (int i = 0; i < n; i++){
        element temp = pq.top();
        if (temp.earned != 0)
            ans += temp.earned;
        pq.pop();
    }
    cout << fixed << setprecision(8) << ans;
    
    return 0;
}
           