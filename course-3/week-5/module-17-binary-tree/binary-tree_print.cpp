#include <bits/stdc++.h>
using namespace std;

/*
     root
     / \
    a   b
   /   / \
  c   d   e

*/
/*
     10
     / \
    20  30
   /   / \
  40  50  60

*/

// PRE ORDER -> ROOT LEFT RIGHT -> root , a, c, b, d, e -> 10 20 40 30 50 60 
// IN ORDER -> LEFT ROOT RIGHT -> c, a, root, d, b , e -> 40, 20, 10, 50, 30, 60
// POST ORDER -> LEFT RIGHT ROOT -> c, a, d, e, b, root, -> 40, 20, 50, 60, 30, 10


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

// PRE ORDER TRAVERSAL
void pre_order_print(Node *root) {
    if(root == NULL) return;

    cout << root->val << " ";

    pre_order_print(root->left);

    pre_order_print(root->right);
}

// IN ORDER TRAVERSAL
void in_order_print(Node *root) {
    if(root == NULL) return;

    in_order_print(root->left);

    cout << root->val << " ";

    in_order_print(root->right);
}

// POST ORDER TRAVERSAL
void post_order_print(Node *root) {
    if(root == NULL) return;

    post_order_print(root->left);

    post_order_print(root->right);

    cout << root->val << " ";
}

int main()
{

    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);



    // Root Connection
    root->left = a;
    root->right = b;

    a->left = c;

    b->left = d;
    b->right = e;

    post_order_print(root);

    return 0;
}