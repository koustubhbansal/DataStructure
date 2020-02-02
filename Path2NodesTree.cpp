#include <iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// structure of a node of binary tree
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
bool getpath(Node *root,int x, vector <int> &s)
{
    if(root==NULL)
        return false;
    // push in stack
    s.push_back(root->data);
    if (root->data == x) {
        return true;
    }
    if(getpath(root->left, x, s) || getpath(root->right, x, s))
    {
        return true;
    }
    s.pop_back();
    return false;
    // pop from stack
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

    vector <int> path1;
    vector <int> path2;
    getpath(root, 8, path1);
    getpath(root, 9, path2);


    int i=0,j=0;
    while(i!=path1.size() || j!=path2.size())
    {
        if(path1[i]==path2[j]){
            i++;
            j++;
        }
        else break;
    }
    for(int m=path1.size()-1;m>i-1;m--)
    {
        cout<<path1[m]<<"  ";
    }
    for(int n=j-1;n<path2.size();n++)
    {
        cout<<path2[n]<<"  ";
    }

}
