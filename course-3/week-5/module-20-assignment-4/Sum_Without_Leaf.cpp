// https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/sum-without-leaf
// Sum Without Leaf

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

int sum_without_leaf(Node *head)
{

    if (!head)
        return 0;

    if (!head->left && !head->right)
        return 0;

    int curr = head->val;

    if (head->left)
    {
        curr += sum_without_leaf(head->left);
    }

    if (head->right)
    {
        curr += sum_without_leaf(head->right);
    }

    return curr;
}

int main()
{
    Node *head = level_order_input();

    int sum = sum_without_leaf(head);

    cout << sum << endl;

    return 0;
}
