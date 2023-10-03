#include <iostream>
#include <queue>
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
BinaryTreeNode<int> *takeInputLevelWise()
{
    cout << "Enter root Data" << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }
        else
        {
            cout << front->data << ":";
            cout << "L:";
            if (front->left)
            {
                pendingNodes.push(front->left);
                cout << front->left->data << ",";
            }
            else
            {
                cout << "-1"<< ",";
            }
            cout << "R:";
            if (front->right)
            {
                pendingNodes.push(front->right);
                cout << front->right->data << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
}
int numNodes(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}
bool isNodePresent(BinaryTreeNode<int>*root,int x){
    if(root==NULL){
        return false;
}
if(root->data==x){
    return true;
}
return isNodePresent(root->left,x) || isNodePresent(root->right,x);
}
int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
void mirrorBinaryTree(BinaryTreeNode<int>*root){
    if(root==NULL){
        return ;
    }
    BinaryTreeNode<int>*temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}


void inOrder(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void preOrder(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    int num=numNodes(root);
    cout<<"Number of nodes= "<<num<<endl;
    int x;
    cout<<"Enter the element you want to search"<<endl;
    cin>>x;
    bool presentOrNot=isNodePresent(root,x);
    if(presentOrNot){
        cout<<"Element " <<x<<" found in tree."<<endl;
    }
    int h=height(root);
    cout<<"Height of tree : "<<h<<endl;
    // mirrorBinaryTree(root);
    // printLevelWise(root);
    inOrder(root);
    cout<<endl;
    postOrder(root);   
    cout<<endl;
    preOrder(root);
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1   