
    if (root == NULL)
    {
        return 0;
    }
    int l;
    if (root->data == value)
    {
        return l;
    }
    l = 1 + max(level(root->left, value), level(root->right, value));
}
bool isSibling(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->left != NULL && root->right != NULL)
    {
        return (root->left->data == a) && (root->right->data == b) || (root->left->data == b) && (root->right->data == a) || isSibling(root->left, a, b) || isSibling(root->right, a, b);
    }
    else
    {
        return false;
    }
}
bool isCousin(BinaryTreeNode<int> *root, int a, int b)
{
    if (level(root, a) == level(root, b) && (!isSibling(root, a, b)))
    {
        return true;
    }
    else
    {
        false;
    }
}
