#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

long long transform(vector<long long> seq, int begin, int end){
    size_t size = seq.size();
    if((end - begin) == 1)
        return min(abs(seq[begin] - seq[begin + 1]), abs(seq[end] - seq[end - 1]));
    else if((end - begin) == 2) 
        return 0;
    else if((end - begin) == 3)
        return min(abs(seq[begin] - seq[begin + 1]), abs(seq[end] - seq[end - 1]));
    // if (size <= 2)
    //   return 0;
    
    long long mid;
    mid = (begin + end) / 2;
    long long quarter;
    quarter = (begin + mid) / 2;

    vector<long long> L; 
    vector<long long> R;
    L.assign(seq.begin(), seq.begin() + mid + 1);
    R.assign(seq.begin() + mid + 1, seq.end());
    vector<long long> originL;
    vector<long long> originR;
    originL.assign(L.begin(), L.end());
    originR.assign(R.begin(), R.end());

    long long operationsL, operationsR;
    operationsL = operationsR = 0;
    nth_element(L.begin(), L.begin() + quarter, L.end());
    nth_element(R.begin(), R.begin() + quarter, R.end());
    //median
    for (int i = 0; i < L.size(); i++)
        operationsL += abs(L[quarter] - L[i]);
    for (int i = 0; i < R.size(); i++)
        operationsR += abs(R[quarter] - R[i]);

    operationsL += transform(originR, 0, R.size() - 1);
    operationsR += transform(originL, begin, mid);

    return min(operationsL, operationsR);
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long n;
    cin >> n;
    
    vector <long long> seq(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    
    cout << transform(seq, 0 , n - 1) << endl;

    return 0;
}