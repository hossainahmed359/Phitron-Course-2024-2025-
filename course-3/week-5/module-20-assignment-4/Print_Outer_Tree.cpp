// https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/print-outer-tree
// Print Outer Tree

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

//              10
//            /    \
//          20      30
//        /   \       \
//      40     70      50
//     /  \          /    \
//    90  110      80     60
//                    \
//                    100

// 990 40 20 10 30 50 60

//      10
//    /    \
//  20      30
//    \    /   \
//    40  70    50
//   / \        /
// 60   90    80
//            /  \
//          100  110

// 60 40 20 10 30 50 80 110

void print_left_outer(Node *head)
{
    if (!head)
        return;

    if (head->left)
        print_left_outer(head->left);
    else if (head->right)
        print_left_outer(head->right);

    cout << head->val << " ";
}

void print_right_outer(Node *head)
{
    if (!head)
        return;

    cout << head->val << " ";

    if (head->right)
        print_right_outer(head->right);
    else if (head->left)
        print_right_outer(head->left);
}

void print_outer_tree(Node *head)
{
    if (head->left)
        print_left_outer(head);

    if (!head->left)
        cout << head->val << " ";

    if (head->right)
        print_right_outer(head->right);
}

int main()
{
    Node *head = level_order_input();

    print_outer_tree(head);

    return 0;
}
