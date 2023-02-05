#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void add(vector<int> &r, vector<int> &s ,int power){
    for (int i = 0; i < r.size(); i++)
        r[i] = s[i] + power;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> S(1);
    S[0]=1;

    if (n == 0)
        cout << 1;
    else{
        for (int i = 1; i <= n; i++){
            vector<int> R(S.size());
            //vector <int> b;
            add(R, S, pow(2, i - 1));
            reverse(S.begin(), S.end());
            S.insert(S.begin(), R.begin(), R.end());
            //其實rotate後會變成B+A.reverse
            //從開頭加入R(B) 變成B+A.reverse
        }
        for(int i = 0; i < S.size(); i++)
            cout << S[i] << " ";
    }
    
    return 0;
}