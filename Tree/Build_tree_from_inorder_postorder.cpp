//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
     void create(map<int,int>&m,int in[],int n){
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
    }
    
    Node* solve(int in[],int post[],int &index,int instart,int inend,int n,map<int,int> &m){
        
        if(index<0 || instart>inend){
            return NULL;
        }
        
        int el = post[index--];
        Node* root = new Node(el);
        
       int position = m[el];
        
        root->right = solve(in,post,index,position+1,inend,n,m);
        root->left = solve(in,post,index,instart,position-1,n,m);
        
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        
       int index=n-1;
       map<int,int> m;
       create(m,in,n);
       Node* ans= solve(in,post,index,0,n-1,n,m);
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends