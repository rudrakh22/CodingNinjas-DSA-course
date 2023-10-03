#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
BinaryTreeNode<int>* root;
   public:
    BST() { 
       root=NULL;
    }
    ~BST(){
        delete root;
    }

	/*----------------- Public Functions of BST -----------------*/
    private:
BinaryTreeNode<int>* remove(BinaryTreeNode<int>* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data<root->data){
        root->left=remove(root->left,data);
    return root;
    }
    if(data>root->data){
        root->right=remove(root->right,data);
    return root;
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left==NULL){
            BinaryTreeNode<int>* temp = root->right;
            root->right=NULL;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            BinaryTreeNode<int>* temp = root->left;
            root->left=NULL;
            delete root;
            return temp;
        }
        else{
            BinaryTreeNode<int>* minNode=root->right;
            while(minNode->left !=NULL){
                minNode=minNode->left;
            }
            int rightMin=minNode->data;
            root->data=rightMin;
            root->right=remove(root->right,rightMin);
            return root;
        }
    }
}
public:
    void remove(int data) { 
    this->root=remove(root,data);
    }
    private:
    void print(BinaryTreeNode<int>* root){
        if(root==NULL){
            return ;
        }
        cout<<root->data<<":";
        if(root->left){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        print(root->left);
        print(root->right);
    }
    public:
    void print() { 
        print(root);
    }
    private:
    BinaryTreeNode<int>* insertHelper(BinaryTreeNode<int>*root,int data){
        if(root==NULL){
            BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data<=root->data){
            root->left=insertHelper(root->left,data);
        }
        else{
            root->right=insertHelper(root->right,data);
        }
        return root;
    }
    public:
    void insert(int data) { 
        this->root=insertHelper(this->root,data);
    }
    private:
    bool searchHelper(BinaryTreeNode<int>* root,int data){
        if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        if(data<root->data){
            return searchHelper(root->left,data);
        }
        else{
            return searchHelper(root->right,data);
        }
    }
    public:
    bool search(int data) {
		return searchHelper(root,data);
    }
};
int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}