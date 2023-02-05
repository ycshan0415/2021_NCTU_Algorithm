#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    //n = # of spaghetti, k = time of spilt tolerence 

    vector<long long> lengths;
    for (long long i = 0; i < n; i++){
        long long l;
        cin >> l;
        lengths.push_back(l);
    }

    sort(lengths.begin(), lengths.end());

    long long q;
    cin >> q;
    //q = # of different conditions
    for (long long i = 0; i < q; i++){
        long long x, l;
        cin >> x >> l;
        //x = length we need, l = max length

        long long ans = 0, count = 0;
        vector<long long>::iterator itupp;//auto itupp
        vector<long long>::iterator itlow;//auto itlow
        //lower_bound:大於或等於value的最小值位置
        //upper_bound:大於value的最小值位置
        itupp = upper_bound(lengths.begin(), lengths.end(), x * k > l ? l : x * k);
        /*
        if (x * k > l) it1 = l;
        else it1 = x * k;
        */
        itlow = lower_bound(lengths.begin(), lengths.end(), x);
        //篩選從最短長度(x)到最長長度(x*tolerance或max length)
        for (long long j = 1; j <= k && j * x <= l; j++){
            //j(能分幾段)不超過tolerance且j*x(總長度)不超過max length
            vector<long long>::iterator low;
            vector<long long>::iterator upp;
            low = lower_bound(itlow, itupp, x * j);
            upp = lower_bound(itlow, itupp, x * (j + 1));
            //長度到x*(j+1)之前都是j段
            ans += j * (upp - low);
        }

        cout << ans << "\n";
    }

    return 0;
}