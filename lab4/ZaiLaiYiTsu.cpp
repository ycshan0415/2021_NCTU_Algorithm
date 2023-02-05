#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long n;
    cin >> n;
    //number of different coin values

    vector<long long> value(n);
    for (long i = 0; i < n; i++)
        cin >> value[i];
    vector<long long> changev(1e5 + 1, 1e18);
    changev[0] = 0;
    changev[1] = 1;
    for (long i = 0; i < n; i++){
        long k = value[i];
        while (k < 100001){
            if (changev[k] > changev[k - value[i]] + 1)
                changev[k] = changev[k - value[i]] + 1;
            k++;
        }
    }

    long long q;
    cin >> q;
    //number of customers
    while (q--){
        long long b;
        cin >> b;
        //total bills
        long long paid = 0;
        for (long i = 0; i < n; i++){
            long money;
            cin >> money;
            paid += money * value[i];
        }
        long long change = paid - b;
        if (change == 0)
            cout << 0 << "\n";
        else
            cout << changev[change] << "\n";
    }
    
    return 0;
}

