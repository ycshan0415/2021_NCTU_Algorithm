#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    //n = # of stones Andy has, t = target

    vector<long int> stone;
    for (int i = 0; i < n; i++){
        long int w;
        cin >> w;
        stone.push_back(w);
    }

    sort(stone.begin(), stone.end());
    
    int count = 0;
    for (int i = 0; i < n; i++){
        if (i > 0 && stone[i] == stone[i-1])
            continue;
        int target = t - stone[i], front = i + 1, back = stone.size() - 1;
        while ( front < back){
            int sum = stone[front] + stone[back];
            if (target > sum)
                front++;
            else if (target < sum)
                back--;
            else if (target == sum)
                count++;
                int left = stone[front], right = stone[back];
                while (front < back && stone[front] == left)//跳過重覆的
                    front++;
                while (front < back && stone[back] == right)//跳過重覆的
                    back --;
            }
        }

    if (count == 0)
        cout << "FeiDooDoo_Zuo_Wei_Men";
    else
        cout << count;

    return 0;
}