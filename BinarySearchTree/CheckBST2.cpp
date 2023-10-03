#include <iostream>
#include <queue>
#include <climits>
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
class isBSTReturn
{
public:
    bool isBST;
    int maximum;
    int minimum;
};
isBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        isBSTReturn output;
        output.isBST = true;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTfinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && (leftOutput.isBST) && rightOutput.isBST;
    isBSTReturn output;
    output.isBST = isBSTfinal;
    output.maximum = maximum;
    output.minimum = minimum;
    return output;
}
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
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBST2(root).isBST ? "true" : "false");
}
// 3 1 5 -1 2 -1 -1 -1 -1

