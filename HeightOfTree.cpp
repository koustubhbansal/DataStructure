#include <iostream>
using namespace std;

int height=0;
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
    height = 1 + max(heightoftree(root->left),heightoftree(root->right));

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
    root->left->right->right = getNode(9);
    root->right = getNode(2);
    root->right->left = getNode(5);
    root->right->right = getNode(6);

    heightoftree(root);

    cout<<height;
}
