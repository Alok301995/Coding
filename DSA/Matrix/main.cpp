#include <bits/stdc++.h>
using namespace std;

// ******************************
// Binary search
int binarySearch(vector<int> &arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            // Key is in the upper half
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// ******************************
// Search in 2D matrix
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    // Write your code here.
    int low = 0;
    int high = matrix[0].size() - 1;
    int size = matrix[0].size();
    while (low < size && high < size)
    {
        if (matrix[low][high] == x)
        {
            return make_pair(low, high);
        }
        else if (x < matrix[low][high])
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return make_pair(-1, -1);
}
// ******************************
int main()
{
    vector<vector<int>> matrix = {{1, 2, 5},
                                  {3, 4, 9},
                                  {6, 7, 10}};
    int key = -1;
    pair<int, int> p = search(matrix, key);
    cout << p.first << " " << p.second << endl;
}