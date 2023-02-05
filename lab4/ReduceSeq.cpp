#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long reduce(long &arr[], long i){
    long a = arr[i - 1] + arr[i] + arr[i + 1];
    long reward = arr[i - 1] * arr[i + 1];

    return reward;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long n;
    cin >> n;
    //length

    long *seq = new long [n];
    for (long i = 0; i < n; i++){
        cin >> seq[i];
    }
    while (seq.size() > 1){

    }


    return 0;
}
