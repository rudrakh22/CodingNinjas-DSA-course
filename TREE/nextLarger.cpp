#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename t>
class TreeNode
{
public:
    t data;
    vector<TreeNode<t> *> children;
    TreeNode(t data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}
TreeNode<int> *takeInput()
{
    cout << "Enter root data" << endl;
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Number of child of" << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter the " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            if (i < front->children.size() - 1)
            {
                cout << front->children[i]->data << ",";
            }
            else
            {
                cout << front->children[i]->data << endl;
            }
        }
        cout << endl;
    }
}
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *maxChild = maxDataNode(root->children[i]);
        if (max->data < maxChild->data)
        {
            max = maxChild;
        }
    }
    return max;
}
int sumOfNodes(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}
int countNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}
int getLeafNodeCount(TreeNode<int> *root)
{
    int count = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
}
void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}
void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return false;
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        if (!areIdentical(root1->children[i], root2->children[i]))
        {
            return false;
        }
    }
    return true;
}
TreeNode<int>* getnextLargerElement(TreeNode<int>*root,int n){
    if(root==NULL){
        return root; 
    }
    bool flag=false;
    TreeNode<int>*nextLarger=NULL;
    if(root->data>n){
        nextLarger =root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>*temp=getnextLargerElement(root->children[i],n);
        if(nextLarger==NULL){            
            nextLarger= temp ;
        }
        else if(temp !=NULL && temp->data<nextLarger->data){
            nextLarger=temp;
            flag=true;
        }
    }
    return nextLarger;
}
TreeNode<int>* getnextLargestElement(TreeNode<int>* root,int n){
    if (root==NULL){
        return root;
    }
    TreeNode<int>* nextLarger=NULL;
    if(root->data>nextLarger->data){
        nextLarger=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>*temp=getnextLargestElement(root->children[i],n);
        if(nextLarger==NULL){
            nextLarger=temp;
        }
        else if(temp!=NULL && temp->data<nextLarger->data){
            nextLarger=temp;
        }
    }
    return nextLarger;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int n;
    cout<<"Enter the element for which you want the next larger"<<endl;
    cin>>n;
    TreeNode<int>* nextLarger=getnextLargerElement(root,n);
    cout<<"The nest largest element is : "<<nextLarger->data<<endl;
    // TreeNode<int> *root1 = takeInput();
    // TreeNode<int> *root2 = takeInput();
    // if(areIdentical(root1,root2)){
    //     cout<<"Both tree are structurally identical"<<endl;
    // }
    // printTree(root);
    // int count = countNodes(root);
    // cout << "Number Of Nodes: " << count << endl;
    // int sum = sumOfNodes(root);
    // cout << "Sum of nodes is:" << sum << endl;
    // TreeNode<int> *max = maxDataNode(root);
    // cout << "Maximum node of tree : " << max->data << endl;
    // int k;
    // cout << "Enter the depth of  tree" << endl;
    // cin >> k;
    // cout << "Node at level " << k << " are :" << endl;
    // printAtLevelK(root, k);
    // cout << endl;
    // int leafCount = getLeafNodeCount(root);
    // cout << "Total number of Leaf Node in Tree are :" << leafCount << endl;
    // cout << "PreOrder Traversal" << endl;
    // preOrder(root);
    // cout << endl;
    // cout << "PostOrder Traversal" << endl;
    // postOrder(root);
    // cout << endl;
    // // deleteTree(root);

    // delete root;
}
