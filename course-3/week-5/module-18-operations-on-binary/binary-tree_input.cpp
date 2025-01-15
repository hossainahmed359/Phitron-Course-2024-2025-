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

// LEVEL ORDER TRAVERSE ->  root (level 0) -> a, b  (level 1) -> c, d, e (level 2) ->  10 , 20 , 30, 40, 50, 60
void level_order_print(Node *root)
{

    if(!root) {
        cout << "NO TREE" << endl;
        return;
    }

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

// LEVEL ORDER INPUT | BINARY TREE INPUT -> root a b c -1 d e -1 -1 -1 -1
// LEVEL ORDER INPUT | BINARY TREE INPUT -> 10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1
Node *level_order_input()
{

    // ROOT NODE INPUT
    int val;
    cin >> val;

    if(val == -1) return NULL;

    Node *root = new Node(val);

    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        // 1. EXTRACT ROOT/FRONT NODE
        Node *front = que.front();
        que.pop();

        // 2. WORK ON THE NODE
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        Node *leftNode, *rightNode;

        // LEFT NODE
        if (leftVal == -1)
        {
            leftNode = NULL;
        }
        else
        {
            leftNode = new Node(leftVal);
        }

        // RIGHT NODE
        if (rightVal == -1)
        {
            rightNode = NULL;
        }
        else
        {
            rightNode = new Node(rightVal);
        }

        front->left = leftNode;
        front->right = rightNode;

        // 3. PUSH THE CHILDREN
        if (front->left)
            que.push(front->left);
        if (front->right)
            que.push(front->right);
    }

    return root;
}

int main()
{

    Node *root = level_order_input();
    level_order_print(root);

    return 0;
}