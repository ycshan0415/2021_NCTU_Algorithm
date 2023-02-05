#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long int n, l, k;
    cin >> n >> l >> k;
    //n = # of books, l = box weight limit, k = time
    long long* weight = new long long [n];
    for (long long i = 0; i < n; i++)
        cin >> weight[i];

    sort(weight, weight + n);

    long long count = 0, min = 0, max = n - 1;
    while (min < max){
        //不能用!= 如果剩最後兩個 max和min會交錯 不會有相等的時候
        if (weight[min] + weight[max] <= l){
            min++;
            max--;
        }
        else
            max--;
        count++;
    }
    if (min == max)//到同一個idx 代表剩最後一個
        count++;

    long long time;
    time = count * k * 2;//來回
    cout << time;

    return 0;
}
