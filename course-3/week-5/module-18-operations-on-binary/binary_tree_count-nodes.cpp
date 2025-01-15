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

// LEVEL ORDER INPUT | BINARY TREE INPUT -> root a b c -1 d e -1 -1 -1 -1
// LEVEL ORDER INPUT | BINARY TREE INPUT -> 10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1
Node *level_order_input()
{

    // ROOT NODE INPUT
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

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

// COUNT NODES ->  root (level 0) -> a, b  (level 1) -> c, d, e (level 2) ->  10 , 20 , 30, 40, 50, 60
int count_nodes(Node *root)
{

    if (!root)
    {
        return 0;
    }

    int count = 0;

    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        Node *root = que.front();
        que.pop();

        count++;

        if (root->left != NULL)
            que.push(root->left);
        if (root->right != NULL)
            que.push(root->right);
    }

    return count;
}

int count_nodes_with_recursion(Node *parent)
{
    if (!parent)
        return 0;

    int count = 1;

    if (parent->left)
        count += count_nodes_with_recursion(parent->left);

    if (parent->right)
        count +=count_nodes_with_recursion(parent->right);

    return count;
}

int main()
{

    Node *root = level_order_input();

    int totalNodes = count_nodes(root);
    cout << totalNodes << endl;

    int totalNodes_recursion = count_nodes_with_recursion(root);
    cout << totalNodes_recursion << endl;

    return 0;
}