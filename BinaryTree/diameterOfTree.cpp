#include <iostream>
#include <queue>
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

int height(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return 0;
	}

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{

	BinaryTreeNode<int> *root = takeInputLevelWise();
	printLevelWise(root);
	int d = diameter(root);
	cout << "Diameter of tree " << d << endl;
	delete root;
}
