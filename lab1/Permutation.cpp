#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define mod 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    long int n, c, ans = 1;
    cin >> n;
    //n = length, c = constraint

    vector<long int> permutation;
    for (int i = 0; i < n; i++){
        cin >> c;
        if (c > n)
            permutation.push_back(n);
        else
            permutation.push_back(c);
    }

    sort (permutation.begin(), permutation.end());
    
    for (int i = 0; i < permutation.size(); i++)
        ans = (ans * (permutation[i]-i)) % mod;

    cout << ans;

    return 0;
}