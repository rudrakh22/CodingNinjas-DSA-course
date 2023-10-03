#include<iostream>
#include<vector>
using namespace std;
template<typename t>
class TreeNode{
    public:
    t data;
    vector<TreeNode<t>*> children;
    TreeNode(t data){
        this->data=data;
    }
};
// void printTree(TreeNode<int>*root){
//     cout<<root->data<<endl;
//     for(int i=0;i<root->children.size();i++){
//         printTree(root->children[i]);
// }}
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data :"<<endl;
    cin>>rootData;
    TreeNode<int>*root=new TreeNode<int>(rootData);
    int n;
    cout<<"Enter the number of child of"<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;

}
void printTree(TreeNode<int>*root){
    if(root==NULL) return;
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main(){
TreeNode<int>*root=takeInput();
printTree(root);

}