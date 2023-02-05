#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int cmpOrder[4][4];
int curH;

struct student{
    string name;
    int score[4];
};


bool cmp(student& s1, student& s2) {
    for (int i = 0; i < 4; i++)
	    if(s1.score[cmpOrder[curH][i]] != s2.score[cmpOrder[curH][i]]) 
		    return s1.score[cmpOrder[curH][i]] > s2.score[cmpOrder[curH][i]];
	
    return s1.name < s2.name;
    //alphbetic order
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    //n = # of new students
    student stu;
    map <char, int> mp = {{'G', 0}, {'H', 1}, {'R', 2}, {'S', 3} } ;
    map <int, string> list = {{0, "GRYFFINDOR:"}, {1, "HUFFLEPUFF:"}, {2, "RAVENCLAW:"}, {3, "SLYTHERIN:"}};
    string order;
    for (int i = 0; i < 4; i++){
        cin >> order;
        for (int j = 0; j < 4; j++)
            cmpOrder[i][j] = mp[order[j]];
            //decide the order to compare in different houses
    }

    vector<student> house[4];//an array[4], each element is a vector
    for (int i = 0; i < n; i++){
        cin >> stu.name;
        int max = 0;
        int idx = 0;
        for (int j = 0; j < 4; j++){
            cin >> stu.score[j];
            if (stu.score[j] > max){
                max = stu.score[j];
                idx = j;
            }
        }
        house[idx].emplace_back(stu);
        //find one's highest score of 4 house, put the student into that house
    }

    for (int i = 0; i < 4; i++){
        cout << list[i];
        if (!house[i].empty()){
            curH = i;
            sort(house[i].begin(), house[i].end(), cmp);
            for (int j = 0; j < house[i].size(); j++)
                cout << "\n" << house[i][j].name;
            cout << "\n";
        }
        else if (house[i].empty())
            cout << " NO NEW STUDENTS\n";
    }

    return 0;
}