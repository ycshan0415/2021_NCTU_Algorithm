#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define mod 1000000007;

struct Node{
    long long  value;
    Node *left = NULL;
    Node *right = NULL;
};

long long compute(Node n){
  if (n.left == NULL && n.right == NULL)
    return n.value;
  else
    return n.value * (compute(*n.left) + compute(*n.right)) % mod;
  //recurrance
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    //n =  # of nuerons

    vector <Node> c(n);
    for (int i = 0; i < n; i++){
      long long temp;
      cin >> temp;
      Node n;
      n.value = temp;
      c[i] = n;
    }

    for (int i = 1; i < n; i++){
        int o;
        cin >> o;
        //o = where the output goes to 
        if (c[o - 1].left == NULL)
          c[o - 1].left = &c[i];
        else 
          c[o - 1].right = &c[i];
        //從parent新增child(上到下的感覺)
    }

    cout << compute(c[0]);

}