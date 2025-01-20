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

// INSERT NODE || | O(h) h = height of binary tree
void insertNode(Node *&root, int insertVal)
{
    if (!root)
        root = new Node(insertVal);

    if (insertVal < root->val)
    {
        if (!root->left)
            root->left = new Node(insertVal);
        else
            insertNode(root->left, insertVal);
    }

    else if (insertVal > root->val)
    {
        if (!root->right)
            root->right = new Node(insertVal);

        else
            insertNode(root->right, insertVal);
    }
}

// CONVERT ARRAY TO BST || O(n)
Node *convert_to_bst(vector<int> arr, int n, int left, int right) {

    if(left > right) return NULL;

    int mid = (left + right) / 2;

    Node *root = new Node(arr[mid]);
    Node *leftNode = convert_to_bst(arr, n, left, mid - 1);
    Node *rightNode = convert_to_bst(arr, n, mid + 1, right);

    root->left = leftNode;
    root->right = rightNode;

    return root;
}



int main()
{

    vector<int> arr = {2, 5, 8, 11, 15, 18};
    int len = arr.size();
    Node *root = convert_to_bst(arr, len, 0, len - 1);
    level_order_print(root);
     // output -> 8, 2, 15, 5, 11, 18

    return 0;
}