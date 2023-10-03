#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include<vector>
void rootToLeafPathsSumToKHelper(BinaryTreeNode<int> *root,vector<int> &v, int k) {
if(root==NULL){
    return;
}
k-=root->data;
v.push_back(root->data);
if(root->left==NULL && root->right==NULL){
    if(k==0){
        for(int i=0;i<v.size();i++){
            cout <<v[i]<<" ";
        }
        cout<<endl;
    }
    v.pop_back();
    return; 
}
rootToLeafPathsSumToKHelper(root->left,v, k);
rootToLeafPathsSumToKHelper(root->right,v,k);
v.pop_back();
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> v;
    rootToLeafPathsSumToKHelper(root,v,k);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}