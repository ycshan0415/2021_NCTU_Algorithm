#include <iostream>
#include <vector>
#include <algorithm>

#define mod 1000000007
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long t;
    cin >> t;
    //# of queries
    
    long long singleDirection[2][10000001];
    
    singleDirection[0][2] = 1;
    singleDirection[1][2] = 2;
    singleDirection[0][3] = 3;
    singleDirection[1][3] = 5;

    for (long long i = 4; i <= 1e7; i++){
        for (int j = 0; j <= 1 ; j++){
            if (j == 0)//上面             上一個+1
                singleDirection[0][i] = (singleDirection[1][i - 1] + 1 + singleDirection[1][i - 2]) % mod;
            else if (j == 1)//下面        上一個+1
                singleDirection[1][i] = (singleDirection[0][i] + 1 + singleDirection[0][i - 1]) % mod;
        }
    }
    
    while (t--){
        long n;
        cin >> n;
        //columns
        long long totem = (4 * singleDirection[1][n] + 1) % mod;
        cout << totem << "\n";
    }

    return 0;
}