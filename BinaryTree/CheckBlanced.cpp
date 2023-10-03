#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
pair<int, bool> isBalancedHelper(BinaryTreeNode<int> *root)
{
    pair<int, bool> p;
    if (root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int, bool> leftAns = isBalancedHelper(root->left);
    pair<int, bool> rightAns = isBalancedHelper(root->right);
    if(!leftAns.second || !rightAns.second || abs(leftAns.first-rightAns.first)>1){
        p.second=false;
    }
    else{
        p.second=true;
    }
    int lh=leftAns.first;
    int rh=rightAns.first;
    int height=1+max(lh,rh);
    p.first=height;
    return p;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    pair<int,bool>p=isBalancedHelper(root);
    return p.second;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}
// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
