#include <bits/stdc++.h>
using namespace std;

/*
     root
     /  \
    a    b
    \    / \
     c  d   e
       /
      f
*/
/*
      10
     /  \
    20   30
    \    / \
    40  50  60
       /
      70

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

// LEVEL ORDER INPUT | BINARY TREE INPUT -> 10 20 30 -1 40 50 60 -1 -1 70 -1 -1 -1
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

// COUNT LEAF NODES
int get_max_height(Node *parent)
{
    if (!parent)
        return 0;

    if (parent->left == NULL && parent->right == NULL)
        return 0;

    int left = get_max_height(parent->left);
    int right = get_max_height(parent->right);

    return max(left, right) + 1;
}

int main()
{

    Node *root = level_order_input();

    int height = get_max_height(root);
    cout << height << endl;

    return 0;
}