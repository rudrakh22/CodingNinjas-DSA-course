#include <iostream>
#include<queue>
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
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
BinaryTreeNode<int>*takeInputLevelWise(){
    cout<<"Enter root Data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData ==-1 ){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() !=0){
    BinaryTreeNode<int>*front=pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter left child of "<<front->data<<endl;
    int leftChildData;
    cin>>leftChildData;
    if(leftChildData != -1){
        BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChildData);
        front->left=child;
        pendingNodes.push(child);
    }
        cout<<"Enter right child of "<<front->data<<endl;
    int rightChildData;
    cin>>rightChildData;
    if(rightChildData != -1){
        BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChildData);
        front->right=child;
        pendingNodes.push(child);
    }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    printTree(root);
}