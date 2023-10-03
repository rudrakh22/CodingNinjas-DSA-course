#include <iostream>
using namespace std;
template <typename t>
class BinaryTreeNode
{
public:
    t data;
    BinaryTreeNode<t> *left;
    BinaryTreeNode<t> *right;
    BinaryTreeNode(t data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTreeNode<int>*takeInput(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftChild=takeInput();
    BinaryTreeNode<int>*rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}
int main()
{
    BinaryTreeNode<int>*root=takeInput();
    printTree(root);
    // BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    // root->left=node1;
    // root->right=node2;
}