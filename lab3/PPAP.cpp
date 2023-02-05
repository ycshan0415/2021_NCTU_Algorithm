#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<string, long> words;
map<string, long> huffman;
vector<map<string, long>> fline;
vector<long> nline;
vector<string> lines;


struct Node{
    string word;
    long freq;
    Node *left;
    Node *right;

    Node (string word, long freq, Node* left, Node* right){
        this->word = word;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct cmp{
    bool operator()(Node* a, Node* b){
        if (a->freq != b->freq)
            return a->freq > b->freq;
        else
            return a->word > b->word;
            //alphbetic
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stringstream ss;
    
    long n;
    cin >> n;
    string empty;
	getline(cin, empty);
    for (int i = 0; i <= n; i++){
        string lyrics;
        getline(cin, lyrics);
        lines[i] = lyrics;
        string temp = "";
        for (int j = 0; j < lyrics.size(); j++){
            if (lyrics[j] == ' '){
                words[temp]++;
                nline[i]++;
                fline[i][temp]++;
                temp = "";
            }
            else
                temp += lyrics[j];
        }
        //last word
        words[temp]++;
        nline[i]++;
        fline[i][temp]++;
    }

    for (auto it = words.begin(); it != words.end(); it++){
        cout << it->first << it->second << endl;
    }

    return 0;
}
