// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/count-me-2
// Count Me

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {

        map<string, int> stMap;
        int maxCount = 0;
        string firstMaxWord;

        // cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            stMap[word]++;
            int count = stMap[word];

            if (count > maxCount)
            {
                maxCount = count;
                firstMaxWord = word;
            }
        }

        cout << firstMaxWord << " " << maxCount << endl;
    }

    return 0;
}
