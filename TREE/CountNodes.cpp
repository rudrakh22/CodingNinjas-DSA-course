#include <iostream>
#include <vector>
#include <queue>
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
    int rootData;
    cout << "Enter root data"<<endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter number of child of " << front->data;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter" << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
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
        for (int i = 0; i < root->children.size(); i++)
        {
            if (i < front->children.size()-1)
            {
                cout << front->children[i]->data << ",";
            }
            else{
                cout << front->children[i]->data;
            }
        }
        cout<<endl;
    }
}
int NumNodes(TreeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=NumNodes(root->children[i]);
    }
    return ans;
}
int main()
{
    TreeNode<int>*root=takeInput();
    printTree(root);
    int num=NumNodes(root);
    cout<<"Number of nodes in tree :"<<num<<endl;
}