#include <bits/stdc++.h>
using namespace std;

// Node with constructor
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{

    Node a(10), b(20), c(30);

    a.next = &b;
    b.next = &c;
    // c.next = NULL;

    // cout << a.val  << endl;
    // cout << (*a.next).val  << endl;
    // cout << (*(*a.next).next).val  << endl;

    cout << a.val << endl;
    cout << a.next->val << endl;
    cout << a.next->next->val << endl;

    return 0;
}