#include <bits/stdc++.h>
using namespace std;

// Stack Template

// **********************************
// Incresing stack implementation
stack<int> increasingStack(vector<int> &arr)
{
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= s.top())
        {
            s.push(arr[i]);
        }
        else
        {
            while (s.top() > arr[i])
            {
                s.pop();
            }
            s.push(arr[i]);
        }
    }
    return s;
}

// **********************************
// Decreasing stack implementation
stack<int> decreasingStack(vector<int> &arr)
{
}

// **********************************

int main()
{
    vector<int> vect = {1, 3, 2, 5, 4, 6};
    stack<int> s = increasingStack(vect);
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}