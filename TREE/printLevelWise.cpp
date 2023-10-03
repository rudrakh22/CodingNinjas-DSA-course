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

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter " << i << "th child of "<<front->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
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
        cout<<front->data<<":";
        for (int i = 0; i < front->children.size(); i++)
        {
            if(i<front->children.size()-1){
                cout<<front->children[i]->data<<",";
            }
            else{
            cout<<front->children[i]->data;}
            pendingNodes.push(front->children[i]);
        }
    cout<<endl;}
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
}