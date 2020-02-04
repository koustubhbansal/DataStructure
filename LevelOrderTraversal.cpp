#include <iostream>
#include <queue>
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
void level(Node *root)
{
    queue <Node *> q;

    q.push(root);

    while (!q.empty())
    {
       cout<<q.front() -> data<<"  ";
       if(q.front()->left != NULL)
        {
            q.push(q.front() -> left);
        }
       if(q.front()->right != NULL)
        {
            q.push(q.front() -> right);
        }
        q.pop();
    }
}

int main()
{
    Node* root = getNode(1);
    root->left = getNode(4);
    root->left->left = getNode(2);
    root->left->right = getNode(3);
    root->right = getNode(8);
    root->right->left = getNode(6);
    root->right->left->left = getNode(9);
    root->right->left->right = getNode(7);
    root->right->left->right->left = getNode(5);

    level(root);

    return 0;
}
