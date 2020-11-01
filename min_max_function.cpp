/*
    Implemented from Introduction to Algorthims by T.H. Cormen
    chapter 9.1 page 214-215 :
    Simultaneous minimum and maximum
*/
#include <iostream>
//#include<vector>
//#include<string>
using namespace std;
struct MinMax
{
    int minn = INT32_MAX, maxx = INT32_MIN;
};
//                          *** This one solves in O(2*(n-1)) time ***
// int minn(int A[], int size)
// {
//     //0-base indexed min
//     int minn = A[0];
//     for (int i = 1; i < size; i++)
//     {
//         if (minn > A[i])
//         {
//             minn = A[i];
//         }
//     }
//     return minn;
// }
// int maxx(int A[], int size)
// {
//     //0-base indexed max
//     int maxx = A[0];
//     for (int i = 1; i < size; i++)
//     {
//         if (maxx < A[i])
//         {
//             maxx = A[i];
//         }
//     }
//     return maxx;
// }
// MinMax minMax(int A[], int size)
// {
//     MinMax m;
//     m.maxx=maxx(A, size);
//     m.minn=minn(A, size);
//     return m;
// }

//                          *** Program to find max and in O(3*(n//2))or O(3*floor(n/2)) time ***
MinMax minMax(int A[], int size)
{
    MinMax m;
    //First Part
    int start;
    if (size % 2 == 0)
    {
        if (A[0] < A[1])
        {
            m.maxx = A[1];
            m.minn = A[0];
        }
        else if (A[0] > A[1])
        {
            m.maxx = A[1];
            m.minn = A[0];
        }
        start = 2;
    }
    else
    {
        m.minn = m.maxx = A[0];
        start = 1;
    }
    // cout<<"***min is: "<<m.minn<<"***\n";
    for (int i=start; i < size; i += 2)
    {
        // cout<<"***for loop started and i is: "<<i<<"***\n";
        if (A[i] > A[i + 1])//if first element of pair is curent Max
        {
            if (A[i] > m.maxx)
            {
                m.maxx = A[i];
            }
            if (A[i + 1] < m.minn)
            {
                m.minn = A[i + 1];
            }
        }
        if (A[i] < A[i + 1])//if second element of pair is curent Max
        {
            if (A[i+1] > m.maxx)
            {
                m.maxx = A[i+1];
            }
            if (A[i] < m.minn)
            {
                m.minn = A[i];
            }
        }
    }

    return m;
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    MinMax m = minMax(A, n);
    cout << m.minn << ' ' << m.maxx;

    return 0;
}