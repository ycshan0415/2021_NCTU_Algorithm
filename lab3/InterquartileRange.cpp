#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    vector<long double> set;
    double num1;
    cin >> num1;
    set.push_back(num1);
    cout << 0 << "\n";
    double num2;
    cin >> num2;
    set.push_back(num2);
    sort(set.begin(), set.end());
    cout << set[1] - set [0] << "\n";
    double num3;
    cin >> num3;
    set.push_back(num3);
    sort(set.begin(), set.end());
    cout << set[2] - set [0] << "\n";

    while (1){
        double num;
        cin >> num;
        if (num == 0)
            break;
        set.push_back(num);
        sort(set.begin(), set.end());
        long int length = set.size();
        long int mid = length / 2;
        
        vector<double> smallest, largest;
        if (length % 2 == 0){
            smallest.assign(set.begin(), set.begin() + mid);
            largest.assign(set.begin() + mid, set.end());
        }
        else{
            smallest.assign(set.begin(), set.begin() + mid);
            largest.assign(set.begin() + mid + 1, set.end());
        }
        /*
        for (double i = 0; i < smallest.size(); i ++)
            cout << smallest[i] << " ";
            cout << endl;
        for (double  i= 0; i < largest.size(); i ++)
            cout << largest[i] << " ";
            cout << endl;
        */
        double q1, q3;
        if (smallest.size() % 2 == 0){
            q1 = (smallest[smallest.size() / 2 - 1] + smallest[smallest.size() / 2]) / 2;
            //cout << " q1: " << q1;
            //mean of n th smallest & largest
            }
        else{
            q1 = smallest[smallest.size() / 2];
            //cout << " q1: " << q1;
            //n+1 th
        }
        if (largest.size() % 2 == 0){
            q3 = (largest[largest.size() / 2 - 1] + largest[largest.size() / 2]) / 2;
            //cout << " q3: " << q3 << endl;
        }
        else{
            q3 = largest[largest.size() / 2];
            //cout << " q3: " << q3 << endl;
        }
        float IQR = q3 - q1;
        cout << IQR << "\n";
        
    }

    return 0;
}