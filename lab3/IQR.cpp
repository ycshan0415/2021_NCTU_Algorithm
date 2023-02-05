#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <iterator>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    multiset<double> set;
    double num;
    cin >> num;
    cout << 0 << "\n";
    set.insert(num);
    auto itq1 = set.begin();
    auto itq3 = set.begin();
    while(1){
        double n, iqr;
        cin >> n;
        if (n == 0)
            break;
        
        set.insert(n);
        size_t size = set.size();
        if (size % 4 == 0){
            // 3 + 1
            if (n < *itq1)
                itq3--;
            else if (n >= *itq3)
                itq1++;
            else if (n >= *itq1 && n < *itq3){
                itq1++;
                itq3--;
            }
            auto temp1 = itq1;
            auto temp3 = itq3;
            iqr =  (*temp3 + *(++temp3)) / 2 - (*temp1 + *(--temp1)) / 2;
        }
        else{// %4 = 1, 2, 3
            if (n < *itq1)
                itq1--;
            // 等於的時候會放在後面: 1, (new)1
            else if (n >= *itq3)
                itq3++;
            
            if (size % 4 == 1){
                // 0(4) + 1
                auto temp1 = itq1;
                auto temp3 = itq3;
                iqr =  (*temp3 + *(++temp3)) / 2 - (*temp1 + *(--temp1)) / 2;
            }
            if (size % 4 == 2 || size % 4 == 3){
                // 1 + 1, 2 + 1
                iqr = *itq3 - *itq1;
            }
        }

        if (iqr == (int)iqr)
            cout << fixed << setprecision(0) << iqr << "\n";
        else
            cout << fixed << setprecision(1) << iqr << "\n";
    }

    return 0;
}