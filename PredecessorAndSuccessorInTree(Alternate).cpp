#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

Node *preptr = NULL;
Node *succptr = NULL;
Node* getNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *findnode(Node *root, int x, Node * &preptr, Node * &succptr)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return root;
    }
    if (root->data > x)
    {
        succptr=root;
        return findnode(root->left, x, preptr, succptr);
    }
    if (root->data < x)
    {
        preptr=root;
        return findnode(root->right, x, preptr, succptr);
    }
}

void predecessor(Node *root, int x)
{
    Node *givennode;
    givennode=findnode(root, x, preptr, succptr);

    if (givennode == NULL)
    {
        cout<<"Node not found"<<endl;
        return;
    }

    if (givennode->left == NULL)
    {
        if(preptr == NULL)
        {
            cout<<"No predecessor"<<endl;
        }
        else
        {
            cout<<"Predecessor="<<preptr->data<<endl;
        }
    }
    else
    {
        Node *pre;
        pre=givennode->left;
        while (pre->right != NULL)
        {
            pre = pre->right;
        }
        cout<<"Predecessor="<<pre->data<<endl;
    }
    if (givennode->right == NULL)
    {
        if(succptr == NULL)
        {
            cout<<"No successor"<<endl;
        }
        else
        {
            cout<<"Successor="<<succptr->data<<endl;
        }
    }
    else
    {
        Node *succ;
        succ=givennode->right;
        while (succ->left != NULL)
        {
            succ = succ->left;
        }
        cout<<"Successor="<<succ->data<<endl;
    }
    return;
}

int main()
{
    Node* root = getNode(50);
    root->left = getNode(30);
    root->left->left = getNode(20);
    root->left->right = getNode(40);
    root->left->right->right = getNode(45);
    root->right = getNode(70);
    root->right->left = getNode(60);
    root->right->right = getNode(80);

    int a;
    cout << "Enter the node value to find its predecessor and successor" << endl;
    cin >> a;

    predecessor(root, a);

    return 0;
}
