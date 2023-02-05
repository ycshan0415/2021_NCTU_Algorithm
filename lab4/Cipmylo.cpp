#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long n, m, s;
    cin >> n >> m >> s;
    //n = scheduled years, m = pandemic, s = scientists
    
    vector<long> scheduled(n);
    for (long i = 0; i < n; i++)
        cin >> scheduled[i];
    sort(scheduled.begin(), scheduled.end());
    vector<long> affected;
    vector<long> strength;
    long noVirus = scheduled.size();
    for (long i = 0; i < m; i++){
        long b, e, v;
        //b = begin, e = end, v = strength
        cin >> b >> e >> v;
        auto itbegin = lower_bound(scheduled.begin(), scheduled.end(), b);
        // >= val的min的位置
        auto itend = upper_bound(scheduled.begin(), scheduled.end(), e);
        // > val的min的位置
        long count = itend - itbegin;
        noVirus -= count;
        affected.push_back(count);
        strength.push_back(v);
    }

    vector<vector<long>> dp(2, vector<long>(s + 1));//有解決或沒解決
    for (long i = 0; i <= m; i++){
        for (long j = 0; j <= s; j++){
            if (i == 0 || j == 0)
                dp[i % 2][j] = 0;
            else if (strength[i - 1] <= j)
                dp[i % 2][j] = max(affected[i - 1] + dp[(i - 1) % 2][j - strength[i - 1]]
                                    ,dp[(i - 1) % 2][j]);
            else
                dp[i % 2][j] = dp[(i - 1) % 2][j];
        }
    }
    // for (long i = 0; i <= m; i++){
    //     for (long j = 0; j <= s; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[m % 2][s] + noVirus;


    return 0;
}