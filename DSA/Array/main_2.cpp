#include <bits/stdc++.h>
using namespace std;

// Macros

//
// Utility function
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// *****************************************
// Check subset
bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Write your code here.
    unordered_map<int, bool> map;
    for (int i = 0; i < n; i++)
    {
        map[arr1[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        if (map[arr2[i]] == 0)
        {
            return false;
        }
    }
    return true;
}

// *****************************************
// Three way partition
void threeWayPartition(vector<int> &arr, int n, int a, int b)
{
    // Write your code here
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (mid < high)
    {
        if (arr[mid] < a)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] >= a && arr[mid] <= b)
        {
            mid++;
        }
        else if (arr[mid] > b)
        {
            swap(arr[mid], arr[high]);
            high--;
            mid++;
        }
    }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
}
// *****************************************
// Median of two sorted array
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    int low = 0;
    int high = (a.size() > b.size()) ? a.size() - 1 : b.size() - 1;
    while (low <= high)
    {
        int mid_1 = low + (high - low) / 2;
        int mid_2 = (a.size() + b.size()) / 2 - (mid_1);
    }
}
// **********************************************************
// Maximum subarray sum
long long maxSubarraySum(int arr[], int n)
{
    int index = 0;
    int localSum = 0;
    long long globalSum = LLONG_MIN;
    while (index < n)
    {
        if (localSum + arr[index] < 0)
        {
            localSum = 0;
            index++;
        }
        else
        {
            localSum = max(arr[index], localSum + arr[index]);
            if (localSum > globalSum)
            {
                globalSum = localSum;
            }
            index++;
        }
    }
    return globalSum;
}
// *******************************************************
// Traping rain water problem
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long waterTrapped = 0;
    long localMax = 0;
    int maxHeightIndex = 0;
    int index = 1;
    long buidingArea = 0;
    while (index < n)
    {
        if (arr[index] < arr[maxHeightIndex])
        {
            if (arr[index] == 0)
            {
                index++;
            }
            else
            {
                long area = (min(arr[index], arr[maxHeightIndex]) * (index - maxHeightIndex - 1)) - buidingArea;
                localMax = max(localMax, area);
                buidingArea += arr[index];
                index++;
            }
        }
        else
        {
            long area = (min(arr[index], arr[maxHeightIndex]) * (index - maxHeightIndex - 1)) - buidingArea;
            localMax = max(localMax, area);
            waterTrapped += localMax;
            maxHeightIndex = index;
            buidingArea = 0;
            localMax = 0;
            index++;
        }
    }
    waterTrapped = waterTrapped + localMax;
    return waterTrapped;
}
// *******************************************************
int main()
{
    long arr[] = {4, 2, 0, 3, 2, 5};
    int n = 6;
    cout << getTrappedWater(arr, n) << endl;
}