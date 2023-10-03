#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

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


BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
#include<stack>
int countNodes(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}
void printNodesSumToS(BinaryTreeNode<int>* root,int s){
    if(root==NULL){
        return ;
    }
    int totalCount=countNodes(root);
    int count=0;
    stack<BinaryTreeNode<int>*> Inorder;
    stack<BinaryTreeNode<int>*> RevInorder;
    BinaryTreeNode<int>*currentNode=root;
    while(currentNode !=NULL){
        Inorder.push(currentNode);
        currentNode=currentNode->left;
    }
    currentNode=root;
    while(currentNode !=NULL){
        RevInorder.push(currentNode);
        currentNode=currentNode->right;
    }
    while(count <totalCount-1){
        BinaryTreeNode<int>*InorderTop=Inorder.top();
        BinaryTreeNode<int>*RevInorderTop=RevInorder.top();
        if(InorderTop->data+RevInorderTop->data==s){
            cout<<InorderTop<<" "<<RevInorderTop<<endl;
            BinaryTreeNode<int>*top=InorderTop;
            Inorder.pop();
            count++;
            if(top->right){
                top=top->right;
                while(top !=NULL){
                    Inorder.push(top);
                    top=top->left;
                }
            }
            top=RevInorderTop;
            RevInorder.pop();
            count++;
            if(top->left != NULL){
                top=top->left;
                while(top!=NULL){
                    RevInorder.push(top);
                    top=top->right;
                }
            }
        }
        else if(InorderTop->data+RevInorderTop->data>s){
            BinaryTreeNode<int>*top=RevInorder.top();
            RevInorder.pop();
            count++;
            if(top->left != NULL){
                top=top->left;
                while(top !=NULL){
                    RevInorder.push(top);
                    top=top->right;
                }
            }
        }
        else{
            BinaryTreeNode<int>*top=Inorder.top();
            Inorder.pop();
            count++;
            if(top->right != NULL){
                top=top->right;
                while(top !=NULL){
                    Inorder.push(top);
                    top=top->left;
                }
            }
        }
    }
}
int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}