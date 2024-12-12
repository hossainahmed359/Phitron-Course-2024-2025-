// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges/printing-x
// Printing X

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int back_slash_pos = i;
        int forward_slash_pos = n + 1 - i;

        if (i <= n / 2)
        {

            for (int j = 1; j <= n + 1 - i; j++) /*  Decrement n - i */
            {
                if (j == back_slash_pos)
                {
                    cout << "\\";
                }
                else if (j == forward_slash_pos)
                {
                    cout << "/";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        else if (i == (n / 2) + 1)
        {
            for (int j = 1; j <= (n / 2) + 1; j++)
            {
                if (j < (n / 2) + 1)
                {
                    cout << " ";
                }
                else
                {
                    cout << "X" << endl;
                }
            }
        }
        else
        {

            for (int j = 1; j <= n + 1; j++) /*  Decrement n - i */
            {
                if (j == back_slash_pos)
                {
                    cout << "\\";
                }
                else if (j == forward_slash_pos)
                {
                    cout << "/";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
