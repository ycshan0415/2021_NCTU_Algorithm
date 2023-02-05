#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

long long ToPositive(long long num);

long long MakeGood(vector<long long> s, int left, int right){
    if((right - left) == 1 || (right - left) == 3)
        return min(ToPositive(s[left + 1] - s[left]), ToPositive(s[right] - s[right - 1]));
    else if((right - left) == 2) 
        return 0;

    int mid = (left + right)/2;
    int mid_l = (left + mid)/2;
    vector<long long> first;
    vector<long long> second;
    first.assign(s.begin(), s.begin() + mid + 1);
    second.assign(s.begin() + mid + 1, s.end());
    vector<long long> t1 = first;
    vector<long long> t2 = second;
    
    long long sum_first = 0;
    long long sum_second = 0;
    nth_element(first.begin(), first.begin() + mid_l, first.end());
    for(int i=0; i<first.size(); i++)
        sum_first += ToPositive(first[i] - first[mid_l]);

    nth_element(second.begin(), second.begin() + mid_l, second.end());
    for(int i=0; i<second.size(); i++)
        sum_second += ToPositive(second[i] - second[mid_l]);

    return min(MakeGood(t1, left, mid) + sum_second,
               MakeGood(t2, 0, (second.size() - 1)) + sum_first);
}


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    long long N;
    cin >> N;

    vector<long long> s;
    s.resize(N);
    for(int i=0; i<N; i++)
        cin >> s[i];

    if(N == 1 || N == 2) cout << 0; 
    else cout << MakeGood(s, 0, N-1) << "\n";

    return 0;
}

long long ToPositive(long long num){
    if(num < 0) return -num;
    else return num;
}