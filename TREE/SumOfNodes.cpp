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
};
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
            if (i < front->children.size()-1)
            {
                cout << front->children[i]->data<< ",";
            }
            else
            {
                cout << front->children[i]->data << endl;
            }
        }
        cout<<endl;
    }
}
int sumOfNodes(TreeNode<int>* root){
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=sumOfNodes(root->children[i]);
    }
    return sum;
}
int countNodes(TreeNode<int> * root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
    ans += countNodes(root->children[i]);
    }
    return ans;
}
int main()
{
    TreeNode<int>* root=takeInput();
    printTree(root);
    int count=countNodes(root);
    cout<<"Number Of Nodes: "<<count<<endl;
    int sum=sumOfNodes(root);
    cout<<"Sum of nodes is:"<<sum<<endl;
}
