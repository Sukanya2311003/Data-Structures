#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left= nullptr;
        right=nullptr;

    }
};
class Solution{
  public:   int diameterofBinaryTree(Node* root){
        int diameter= 0;
        height(root, diameter);
        return diameter;
    }
    private:
    int height(Node* root, int &diameter){
        if(root==nullptr) return 0;
        int lh= height(root->left, diameter);
        int rh= height(root->right, diameter);
        diameter= max(diameter, lh+ rh);
        return 1+ max(lh, rh);

    }
};
int main(){
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->right= new Node(6);
    root->right->right->right= new Node(7);
    Solution S1;
    int diameter= S1.diameterofBinaryTree(root);
    cout<<"Diameter of binary tree is "<<diameter<<endl;
    return 0; 

}