#include<iostream>
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

bool checkBST(Node* root) {
    if (root == NULL)
        return true;
    bool a,b;
    if(root->left == NULL)
        a=true;
    else if(root->data > root->left->data )
    {
        Node *temp;
        temp=root->left;
        while(temp !=NULL){
            if(temp->data >= root->data)
                break;
            temp = temp->right;
        }
        if(temp == NULL)
            a=true;
        else a=false;
    }
    else a=false;
    if(root->right == NULL)
        b=true;
    else if(root->data < root->right->data)
    {
        Node *temp;
        temp=root->right;
        while(temp !=NULL){
            if(temp->data <= root->data)
                break;
            temp = temp->left;
        }
        if(temp == NULL)
            b=true;
        else b=false;
    }
    else b=false;
    return (a && b && checkBST(root->left) && checkBST(root->right));
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

    if (checkBST(root))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
