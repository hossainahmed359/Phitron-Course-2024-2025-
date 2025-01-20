#include <bits/stdc++.h>
using namespace std;

// MAX HEAP

// 23, 15, 21, 13, 9, 19, 8, 2, 4, 7

/*

            23
         /      \
       15        21
      /  \      /  \
    13    9   19    8
   / \   /
  2   4 7

 */

// INSERT IN MAX HEAP : O(h) -> log(n)
int main()
{

    vector<int> arr = {23, 15, 21, 13, 9, 19, 8, 2, 4, 7};

    // insert 18
    arr.push_back(18);

    int cur_index = arr.size() - 1;
    while (cur_index != 0)
    {
        int parent_index = (cur_index - 1) / 2;

        if (arr[parent_index] < arr[cur_index])
            swap(arr[parent_index], arr[cur_index]);
        else
            break;

        cur_index = parent_index;
    }

    return 0;
}