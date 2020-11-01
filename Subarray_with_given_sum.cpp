/*
GeeksforGeeks
Subarray with given sum Solution
With Sliding Window Tecknique:
Given an unsorted array A of size N of non-negative integers, 
find a continuous sub-array which adds to a given number S.
*/

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n, s;
    while (t--)
    {
        cin >> n >> s;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int winStart = 1;
        int winEnd = 1;
        int runningSum = 0;
        while (winStart <= n or winEnd <= n)
        {
            if (runningSum < s)
            {
                runningSum += a[winEnd];
                winEnd++;
                // cout << "   *Window is now bigger*   ";
            }
            else if (runningSum > s)
            {
                runningSum -= a[winStart];
                winStart++;
                // cout << "   *Window is now smaller*   ";
            }
            else
            {
                cout << winStart << ' ' << winEnd - 1 << '\n';
                break;
            }
            // cout << "Running sum:" << runningSum << " winStart:" << winStart << " winEnd: " << winEnd << " \n";
        }
        if (runningSum != s)
            cout << -1 << '\n';
    }
    return 0;
}
