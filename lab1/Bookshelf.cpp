#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<long int, long int> bookshelf;
    long int n, m;
    cin >> n >> m;
    //n = # of books, m = # Brian asked for

    for (int i = 0; i < n; i++){
        long int height;
        cin >> height;
        bookshelf[height] = i;
        //從高度找index 不是用vector一個一個去存(vector[i] = height)
    }

    for (int i = 0; i < m; i++){
        long int height;
        cin >> height;
        if (bookshelf.find(height) != bookshelf.end())//找map的first(map[height])
            cout << bookshelf[height] << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}