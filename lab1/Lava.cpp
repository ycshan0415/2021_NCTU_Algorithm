#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long int n, k;
    cin >> n >> k;
    //n = # of furniture, k = # of members

    vector<long int> c(n);
    vector<long int> p(n);
    //c = point value, p = # of people 
    for (long int i = 0; i < n; i++)
        cin >> c[i] >> p[i];

    double min = 0.0;
    double max = 1000000000.0;
    while (fabs (max - min) > 0.000001){//(double)absolute value
        double expect = (min + max) / 2;
        long long send = 0;
        //expect = points we expect in this round, send = # of people we need to send out this round
        for (long long i = 0; i < n; i++){
            long long remain = (int)(c[i] / expect) - p[i];
            //remain = remaining place on the furniture
            if (remain <= 0)
                continue;
            send += remain;
        }
        if (k <= send)
            min = expect;
        else
            max = expect;
    }

    cout << setprecision(10) << (min + max) / 2;

    return 0;
}
           