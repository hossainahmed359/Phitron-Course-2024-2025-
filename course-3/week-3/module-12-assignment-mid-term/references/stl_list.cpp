#include <bits/stdc++.h>
using namespace std;

int main()
{

    // STL for doubly linked list
    list<int> l(10, 3);
    // std::cout << *l.begin() << std::endl;
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    list<int> lTwo(10, 5);

    for (int val : lTwo)
    {
        cout << val << " ";
    }

    cout << endl;

    list<int> lThree(lTwo);

    for (int val : lThree)
    {
        cout << val << " ";
    }

    return 0;
}