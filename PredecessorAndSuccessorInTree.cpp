#include<iostream>
#include<vector>
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
void inorder(Node *root, vector <int> &s)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, s);
    s.push_back(root->data);
    inorder(root->right, s);
}
void predecessor(vector <int> &s, int x)
{
    int i;
    for(i = 0; i<s.size(); i++)
    {
        if(s[i] == x)
        {
            break;
        }
    }
    if(i == 0)
    {
        cout<<"No predecessor"<<endl;
        cout<<"Successor="<<s[i+1]<<endl;
    }
     if(i == s.size())
    {
        cout<<"Node not present"<<endl;
        return;
    }
    if(i == s.size()-1)
    {
        cout<<"Predecessor="<<s[i-1]<<endl;
        cout<<"No successor"<<endl;
    }
    else
    {
        cout<<"Predecessor="<<s[i-1]<<endl;
        cout<<"Successor="<<s[i+1]<<endl;
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

    vector <int> s;

    inorder(root, s);
    predecessor(s, a);

    return 0;
}
