// https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/leaf-nodes-1
// Leaf Nodes

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

void push_leaf_nodes(Node *head, vector<int> &vec)
{
    queue<Node *> que;
    que.push(head);

    while (!que.empty())
    {
        Node *parent = que.front();
        que.pop();

        if (!parent->left && !parent->right)
        {
            vec.push_back(parent->val);
        }

        if (parent->left)
            que.push(parent->left);
        if (parent->right)
            que.push(parent->right);
    }
}

int main()
{
    Node *head = level_order_input();
    vector<int> vec;

    push_leaf_nodes(head, vec);

    sort(vec.begin(), vec.end(), greater<>());

    for (auto it : vec)
    {
        cout << it << " ";
    }

    return 0;
}
