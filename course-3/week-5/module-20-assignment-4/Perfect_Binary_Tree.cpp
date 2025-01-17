// https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/perfect-binary-tree
// Perfect Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int val;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val)
    {
        this->val = val;
    }
};

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

bool is_perfect_tree(Node *head)
{

    if (!head)
        return false;

    bool flag = true;

    queue<Node *> que;
    que.push(head);

    while (!que.empty())
    {
        Node *parent = que.front();
        que.pop();

        if ((!parent->left && parent->right) || (parent->left && !parent->right))
        {
            flag = false;
            break;
        }

        if (parent->left)
            que.push(parent->left);
        if (parent->right)
            que.push(parent->right);
    }

    return flag;
}

int main()
{
    Node *head = level_order_input();

    is_perfect_tree(head);

    if (is_perfect_tree(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
