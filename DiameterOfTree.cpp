#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
};

Node* getNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int heightoftree(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return (1 + ((heightoftree(root->left)>heightoftree(root->right))?heightoftree(root->left):heightoftree(root->right)));

}
int diameter(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return max(1 + heightoftree(root -> left) + heightoftree(root -> right),max(diameter(root->left),diameter(root->right)));
}

int main()
{
    Node* root = getNode(0);
    root->left = getNode(1);
    root->left->left = getNode(3);
    root->left->left->left = getNode(7);
    root->left->right = getNode(4);
    root->left->right->left = getNode(8);
    root->left->right->right = getNode(9);
    root->right = getNode(2);
    root->right->left = getNode(5);
    root->right->right = getNode(6);

    cout<<diameter(root)<<endl;


    return 0;
}
