#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long n, t;
    cin >> n >> t;
    //n = # of furniture, t = # of rounds
    vector<vector<long long>> points(t);
    for (long long i = 0; i < t; i++){
        points[i].resize(n);
        for (long long j = 0; j < n; j++)
            cin >> points[i][j];
    }

    if (n == 1){
        long long sum = 0;
        for (long long j = 0; j < t; j++)
            sum += points[j][0];
        cout << sum;
        return 0;
    }

    for (long long i = t - 2; i >= 0; i--){
        for (long long j = 0; j < n; j++){
            if (j - 1 < 0)
                points[i][j] += max(points[i + 1][j], points[i + 1][j + 1]);
            else if (j - 1 >= 0 && j + 1 < n)
                points[i][j] += max({points[i + 1][j - 1], points[i + 1][j], points[i + 1][j + 1]});
            else if (j + 1 == n)
                points[i][j] += max(points[i + 1][j - 1], points[i + 1][j]);
        }
    }
    for (long long j = 0; j < n; j++)
        cout << points[0][j] << " ";
    
    return 0;
}