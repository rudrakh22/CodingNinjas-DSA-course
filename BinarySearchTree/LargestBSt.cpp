#include <iostream>
#include <queue>

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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

using namespace std;

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
#include <climits>
class BST
{
public:
    int maximum;
    int minimum;
    bool isBST;
    int height;
};
BST largestBSTSubtreeHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        BST ans;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        ans.isBST = true;
        ans.height = 0;
        return ans;
    }
    BST left = largestBSTSubtreeHelper(root->left);
    BST right = largestBSTSubtreeHelper(root->right);
    int maximum = max(root->data, max(left.maximum, right.maximum));
    int minimum = min(root->data, min(left.minimum, right.minimum));
    bool isBSTfinal = root->data > left.maximum && root->data < right.minimum && right.isBST && left.isBST;
    BST ans;
    ans.maximum = maximum;
    ans.minimum = minimum;
    ans.isBST = isBSTfinal;
    if (isBSTfinal)
    {
        ans.height = 1 + max(left.height, right.height);
    }
    else
    {
        ans.height = max(left.height, right.height);
    }
    return ans;
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    return largestBSTSubtreeHelper(root).height;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
