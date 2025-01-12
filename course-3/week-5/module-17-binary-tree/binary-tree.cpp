#include <bits/stdc++.h>
using namespace std;

// BINARY TREE IMPLEMENTATION
class Node
{
public:
    int val;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val)
    {
        this->val = val;
    };
};

int main()
{

    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);

    /*


     root
     / \
    a   b
   /   / \
  c   d   e

    */

    // Root Connection
    root->left = a;
    root->right = b;

    a->left = c;

    b->left = d;
    b->right = e;

    return 0;
}