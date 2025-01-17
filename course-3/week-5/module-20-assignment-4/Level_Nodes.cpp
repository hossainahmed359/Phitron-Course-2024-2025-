// https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/level-nodes-2
// Level Nodes

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

void level_order_output(Node *head, int targetLevel)
{
    vector<int> vec;

    queue<pair<Node *, int>> que;
    que.push({head, 0});

    while (!que.empty())
    {
        Node *parent = que.front().first;
        int level = que.front().second;
        que.pop();

        if (level == targetLevel)
            vec.push_back(parent->val);

        if (parent->left)
            que.push({parent->left, level + 1});

        if (parent->right)
            que.push({parent->right, level + 1});
    }

    // Print
    if(vec.size() == 0) {
        cout << "Invalid" << endl;
        return;
    }

    for (auto it : vec)
    {
        cout << it << " ";
    }
    
}

int main()
{
    Node *head = level_order_input();

    cin.ignore();
    int val;
    cin >> val;

    level_order_output(head, val);

    return 0;
}
