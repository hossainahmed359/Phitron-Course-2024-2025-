#include <bits/stdc++.h>
using namespace std;

int main()
{

    // STL for doubly linked list
    list<int> l = {5, 5, 3, 4, 5, 6, 7, 8, 5, 45, 77, 2, 2, 2};

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    cout << l.front() << " " << l.back();

    cout << endl;

    cout << *next(l.begin(), 2);

    cout << endl;

    cout << *l.begin();

    return 0;
}