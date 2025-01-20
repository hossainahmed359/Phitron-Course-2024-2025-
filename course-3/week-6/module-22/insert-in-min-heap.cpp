#include <bits/stdc++.h>
using namespace std;

// MIN HEAP

// 2, 4, 8, 7, 9, 19, 21, 13, 15

/* 

            2
         /     \
       4         8
      / \       / \
    7     9   19   21
   / \
  13  15

 */


// INSERT IN MIN HEAP : O(h) -> log(n)
int main()
{

    vector<int> arr = {2, 4, 8, 7, 9, 19, 21, 13, 15};

    // insert 18
    arr.push_back(18);

    int cur_index = arr.size() - 1;
    while (cur_index != 0)
    {
        int parent_index = (cur_index - 1) / 2;

        if (arr[parent_index] > arr[cur_index])
            swap(arr[parent_index], arr[cur_index]);
        else
            break;

        cur_index = parent_index;
    }

    return 0;
}