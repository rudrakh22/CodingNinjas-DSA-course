#include <iostream>
#include <queue>
#include <climits>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
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

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
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

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
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

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    pair<int,int> ans;
    ans.first=INT_MAX;
    ans.second=INT_MIN;
    if(root==NULL){
        return ans;
    }
    pair<int,int> leftAns=getMinAndMax(root->left);
    pair<int,int> rightAns=getMinAndMax(root->right);
    ans.first=min(min(leftAns.first,rightAns.first),root->data);
    ans.second=max(max(leftAns.second,rightAns.second),root->data);
    return ans;
}
// 10 20 60 -1 -1 3 50 -1 -1 -1 -1 
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    pair<int, int> ans = getMinAndMax(root);
    int max = ans.second;
    int min = ans.first;
    cout << "Maximum node of tree " << max << endl;
    cout << "Minimum of tree " << min << endl;
    delete root;
}
