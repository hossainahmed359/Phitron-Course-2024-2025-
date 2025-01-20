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

// DELETE IN MAX HEAP O(h) -> log(n)
int main()
{

    vector<int> arr = {23, 15, 21, 13, 9, 19, 8, 2, 4, 7};

    // delete max value
    int len = arr.size();
    arr[0] = arr[len - 1];
    arr.pop_back();

    int curr_index = 0;
    while (true)
    {
        int left_index = curr_index * 2 + 1;
        int right_index = curr_index * 2 + 2;

        int left_val = INT_MIN, right_val = INT_MIN;
        if (left_index < arr.size())
            left_val = arr[left_index];
        if (right_index < arr.size())
            right_val = arr[right_index];


        if (left_val > right_val && left_val > arr[curr_index])
        {
            swap(arr[left_index], arr[curr_index]);
            curr_index = left_index;
        }
        else if (right_val > left_val && right_val > arr[curr_index])
        {
            swap(arr[right_index], arr[curr_index]);
            curr_index = right_index;
        }
        else
        {
            break;
        }
    }

    return 0;
}