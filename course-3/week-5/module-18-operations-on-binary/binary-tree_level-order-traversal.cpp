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

// LEVEL ORDER TRAVERSE ->  root (level 0) -> a, b  (level 1) -> c, d, e (level 2) ->  10 , 20 , 30, 40, 50, 60

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

// LEVEL ORDER TRAVERSAL
void level_order_print(Node *root)
{
    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        Node *root = que.front();
        que.pop();

        cout << root->val << " ";

        if (root->left != NULL)
            que.push(root->left);
        if (root->right != NULL)
            que.push(root->right);

        
    }
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

    level_order_print(root);

    return 0;
}