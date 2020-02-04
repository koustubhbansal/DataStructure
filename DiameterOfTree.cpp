#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int diameter=-1;
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

int heightoftree(Node *root, int &diameter)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = heightoftree(root->left, diameter);
    int rh = heightoftree(root->right, diameter);

    diameter = max(diameter, 1 + lh + rh);

    return (1 + max(lh, rh));

}
int dia(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int height = heightoftree(root, diameter);
    return diameter;
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

    cout<<dia(root)<<endl;


    return 0;
}
