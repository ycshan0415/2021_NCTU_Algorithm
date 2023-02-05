#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <stack>
using namespace std;

map <string, int> e1;
map <string, int> e2;

map<string, int> parseUnit(string& s, int& i);
map<string, int> parseFormula(string& s, int& i);
int parseDigits(string& s, int& i);

void countOfAtoms(string formula) {
    const int n = formula.size();
    int i = 0;
    map<string, int> counts = parseFormula(formula, i);
    for (pair<string, int> p : counts) {
        if(p.first.length() == 1)
            e1[p.first] = p.second;
        if(p.first.length() == 2)
            e2[p.first] = p.second;   
    }
}

void merge(map<string, int>& counts, map<string, int>& cnts, int times) {
    for (pair<string, int> p : cnts)
        counts[p.first] += p.second * times;
}

map<string, int> parseFormula(string& s, int& i) {
    map<string, int> counts;
    const int n = s.size();
    while (i < n && s[i] != ')') {
        map<string, int> cnts = parseUnit(s, i);
        merge(counts, cnts, 1);
    }
    return counts;
}

int parseDigits(string& s, int& i) {
        int i1 = i;
        while (i < s.size() && isdigit(s[i]))
            i++;
        int digits; //= i == i1 ? 1 : stoi(s.substr(i1, i - i1));
        if (i == i1)
            digits = 1;
        else
            digits = stoi(s.substr(i1, i - i1));
        
        return digits;
}

map<string, int> parseUnit(string& s, int& i) {
    map<string, int> counts;
    const int n = s.size();
    if (s[i] == '(') {
        map<string, int> cnts = parseFormula(s, ++i); // ++i for '('
        int digits = parseDigits(s, ++i); // ++i for ')'
        merge(counts, cnts, digits);
    }
    else {
        int i0 = i++; // first letter
        while (i < n && islower(s[i]))
            i++;
        string atom = s.substr(i0, i - i0);
        int digits = parseDigits(s, i);
        counts[atom] += digits;
    }
    return counts;
}


int main(){
    string formula;
    cin >> formula;
    countOfAtoms(formula);
    cout << e1.size() << "\n";
    for (map<string, int>::iterator it1 = e1.begin(); it1 != e1.end(); it1++)
        cout << it1->first << ":" << it1->second << "\n";
    cout << e2.size() << "\n";
    for (map<string, int>::iterator it2 = e2.begin(); it2 != e2.end(); it2++)
        cout << it2->first << ":" << it2->second << "\n";
}