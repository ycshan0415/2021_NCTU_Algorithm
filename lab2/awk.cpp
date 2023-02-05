#include <iostream>
#include <set>
#include <stack>
using namespace std;

int ans;

struct Node{
  int idx;
  int year;
  Node *left, *right;
  Node(int a,int b){
    idx = a;
    year = b;
    left = right = NULL;
  }
};

Node *buildTree(int in[], int post[],int year[], int n){
  stack<Node*> st;
  set<Node*> s; 
  int postIndex = n - 1;
  Node* root = NULL;
 
  for (int p = n - 1, i = n - 1; p>=0;) {
    // Initialise node with NULL
    Node* node = NULL;
    // Run do-while loop
    do{ 
      // Initialise node with new Node(post[p]);
      node = new Node(post[p],year[post[p]-1]);
      // Check is root is equal to NULL
      if (root == NULL)
        root = node;
      // If size of set is greater than 0
      if (st.size() > 0){   
        // If st.top() is present in the set s
        if (s.find(st.top()) != s.end()){
          s.erase(st.top());
          st.top()->left = node;
          st.pop();
        }
        else
          st.top()->right = node;
      }
      st.push(node);
    } while (post[p--] != in[i] && p >=0);
 
    node = NULL;
    // If the stack is not empty and
    // st.top()->idx is equal to in[i]
    while (st.size() > 0 && i>=0 && 
            st.top()->idx == in[i]){
      node = st.top();
      // Pop elements from stack
      st.pop();
      i--;
    }
     
    // if node not equal to NULL
    if (node != NULL){
      s.insert(node);
      st.push(node);
    }
  }
  // Return root
  return root;
 
}

void preOrder(Node* node){
    if (node == NULL)
        return;
    else {
        if (node->left!=NULL)
            if (node->year<node->left->year)
                ans+=1;
        if (node->right!=NULL)
            if (node->year<node->right->year)
                ans+=1;
    }
    preOrder(node->left);
    preOrder(node->right);
}
 
// Driver Code
int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n;
    cin>>n;
    int *year = new int [n];
    int *in = new int [n];
    int *post = new int [n];
    for (int i=0;i<n;i++){
        cin>>year[i];
    }
    for (int i=0;i<n;i++){
        cin>>in[i];
    }
    for (int i=0;i<n;i++){
        cin>>post[i];
    }
  
  // Function Call
  Node* root = buildTree(in, post, year, n);
  preOrder(root);
  cout << ans;
  return 0;
}