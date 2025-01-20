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

void level_order_print(Node *root)
{

    if (!root)
    {
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

// LEVEL ORDER INPUT | BINARY SEARCH TREE INPUT -> 18 7 21 -1 12 20 26 9 15 -1 -1 -1 -1 -1 -1 -1 -1
Node *level_order_input()
{

    Node *head = NULL;
    int val;
    cin >> val;

    if (val == -1)
        return head;

    head = new Node(val);

    queue<Node *> que;
    que.push(head);

    while (!que.empty())
    {
        Node *parent = que.front();
        que.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            Node *leftNode = new Node(l);
            parent->left = leftNode;
            que.push(leftNode);
        }
        if (r != -1)
        {
            Node *rightNode = new Node(r);
            parent->right = rightNode;
            que.push(rightNode);
        }
    }

    return head;
}

// SEARCH || Perfect Binary Tree O(long(n)) || Worst || O(n) || O(h) h = height of binary tree
bool searchNode(Node *root, int targetVal)
{
    if (!root)
        return false;

    if (root->val == targetVal)
        return true;

    if (targetVal < root->val)
        return searchNode(root->left, targetVal);
    else if (targetVal > root->val)
        return searchNode(root->right, targetVal);
}

/*
        18
       /  \
      7    21
       \   /  \
       12 20  26
       / \
      9  15


 */

int main()
{

    Node *root = level_order_input();

    int val;
    cin >> val;

    level_order_print(root);

    cout << endl;

    if (searchNode(root, val))
    {
        cout << "Found : " << val << endl;
    }
    else
    {
        cout << "Not Found : " << val << endl;
    }

    return 0;
}