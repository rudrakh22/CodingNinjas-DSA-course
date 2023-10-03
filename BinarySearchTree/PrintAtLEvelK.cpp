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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void nodeAtKDistanceDown(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    nodeAtKDistanceDown(root->left, k - 1);
    nodeAtKDistanceDown(root->right, k - 1);
}
int nodeAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == target)
    {
        nodeAtKDistanceDown(root, k);
        return 0;
    }
    int leftD = nodeAtDistanceKHelper(root->left, target, k);
    if (leftD != -1)
    {
        if (leftD + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            nodeAtKDistanceDown(root->right, k = leftD - 2);
        }
        return 1 + leftD;
    }
    int rightD = nodeAtDistanceKHelper(root->right, target, k);
    if (rightD != -1)
    {
        if (rightD + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            nodeAtKDistanceDown(root->left, k - (rightD + 1) - 1);
        }
        return 1 + rightD;
    }
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    nodeAtDistanceKHelper(root, node, k);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 3 1