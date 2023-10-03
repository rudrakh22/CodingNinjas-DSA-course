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
                cout << "-1"
                     << ",";
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
int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// BinaryTreeNode<int> *buildTreeHelper(int *preorder, int preStart, int preEnd, int *inorder, int inStart, int inEnd)
// {
//     if(preStart>preEnd || inStart>inEnd){
//         return NULL;
//     }
//     int rootData = preorder[preStart];
//     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
//     int k = 0;
//     for (int i = inStart; i <= inEnd; i++)
//     {
//         if (inorder[i] == rootData)
//         {
//             k = i;
//             break;
//         }
//     }
//     root->left = buildTreeHelper(preorder, preStart + 1, preStart+(k-inStart),inorder,inStart,k-1);
//     root->right=buildTreeHelper(preorder,preStart+(k-inStart)+1,preEnd,inorder,k+1,inEnd);
//     return root;
// }
// BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
// {
//     int preStart = 0;
//     int preEnd = preLength - 1;
//     int inStart = 0;
//     int inEnd = preLength - 1;
//     return buildTreeHelper(preorder, preStart, preEnd, inorder, inStart, inEnd);
// }
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {

	int in[] = {4,2,5,1,8,6,9,3,7};
	int pre[] = {1,2,4,5,3,6,8,9,7};
	BinaryTreeNode<int>* root = buildTree(in, pre, 9);
	printTree(root);
	cout << "Num: " << numNodes(root) << endl;
	inOrder(root);
	delete root;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1