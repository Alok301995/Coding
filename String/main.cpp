#include <bits/stdc++.h>
using namespace std;

// String matching algorithm
// KMP algorithm
// Rabin karp

// Given a string and a pattern find the occurence of the pattern if pattern doesn't exist return -1;
// Naive approach
int findPattern(string s, string pat)
{
    int s_start = 0;
    int pat_start = 0;
    while (s_start < s.size())
    {
        if (s[s_start] != pat[pat_start])
        {
            s_start++;
        }
        else
        {
            pat_start = 0;
            while (pat_start < pat.size())
            {
                if (s[pat_start + s_start] != pat[pat_start])
                {
                    break;
                }
                pat_start++;
            }
            if (pat_start >= pat.size())
            {
                return 1;
            }
            else
            {
                s_start++;
            }
        }
    }
    return -1;
}

//  time complexity = O(n*k)

// Longest prefix which is also a suffix

int lps(string pattern)
{
    int size = pattern.size();
    int lps[size];
    lps[0] = 0;
    int i = 0;
    int j = 1;
    while (j < size)
    {
        if (pattern[i] == pattern[j])
        {
            i = i + 1;
            lps[j] = i;
            j++;
        }
        else if (pattern[i] != pattern[j])
        {
            if (i == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
                i = lps[i - 1];
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
    return lps[size - 1];
}

// Longest happy prefix : leetcode

// find the longest prefix which is also a suffix;

string longestPrefix(string s)
{
    int size = s.size();
    int i = 0;
    int j = 1;
    int lps[size];
    lps[0] = 0;
    while (j < size)
    {
        if (s[i] == s[j])
        {
            i = i + 1;
            lps[j] = i;
            j++;
        }
        else if (s[i] != s[j])
        {
            if (i != 0)
            {
                i = lps[i - 1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }
    int index = lps[size - 1];
    if (index == 0)
        return "";
    else
        return s.substr(0, index);
}

// KMP algorithm

// Driver code
int main()
{
    string s = "abcdefgh";
    string pat = "dx";
    // cout<<findPattern(s , pat) << endl;

    string pattern = "abcdeabfabc";
    cout << lps(pattern) << endl;
    // cout << longestPrefix(pattern) << endl;
}