#include <bits/stdc++.h>
using namespace std;

// Utitlity Functions
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printVect(vector<int> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
}
void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

// ************************
// *************************************************************
// Reverse the array

// void reverseArray(vector<int> &arr, int m)
// {
//     // Write your code here.
//     int low = m + 1;
//     int high = arr.size() - 1;
//     while (low < high)
//     {
//         swap(arr[low], arr[high]);
//         low++;
//         high--;
//     }
// }

// *************************************************************
// Kth largest number and the smallest number in a array
/*


int partition(vector<int> &vect, int i, int j)
{

    // this is variation of partition algorithm.
    int low = i;
    int high = j;
    int pivot = i;
    while (low <= high)
    {
        if (vect[low] > vect[pivot] && vect[high] < vect[pivot])
        {
            swap(vect[low], vect[high]);
            low++;
            high--;
        }
        else
        {
            if (vect[low] <= vect[pivot])
            {
                low++;
            }
            else if (vect[high] > vect[pivot])
            {
                high--;
            }
        }
    }
    swap(vect[pivot], vect[high]);
    return high;
}
int kthHelper(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int index = partition(arr, low, high);
        if (index == k)
        {
            return arr[index];
        }
        else if (index < k)
        {
            low = index + 1;
        }
        else
        {
            high = index - 1;
        }
    }
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    int smallest = k - 1;
    int largest = n - k;
    vector<int> result;
    result.push_back(kthHelper(arr, n, smallest));
    result.push_back(kthHelper(arr, n, largest));
    return result;
}
*/
// Partially accepted
// ******************************************************************
//  Sort 012

void sort012(int *arr, int n)
{
    //   Write your code here
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (mid <= high && mid >= low)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    printArray(arr, n);
}
// completed

// ********************************************************
// Sum of max and min

int sumOfMaxMin(vector<int> &arr, int n)
{
    // Write your code here.
    int low = 0;
    int high = n - 1;
    int min = arr[low];
    int max = arr[high];
    while (low < n && high >= 0)
    {
        if (min > arr[low])
        {
            min = arr[low];
        }
        if (max < arr[high])
        {
            max = arr[high];
        }
        low++;
        high--;
    }

    return max + min;
}

// *******************************************************************
// Rotate the array left

void roatate(int *arr, int n, int steps)
{
    for (int j = 0; j < steps; j++)
    {

        int high = n - 2;
        int temp = arr[0];
        while (high >= 0)
        {
            arr[high] = arr[high + 1];
        }
        arr[0] = temp;
    }
}

// ***********************************************************************
// Maximum subarray sum

long long maxSubarraySum(int arr[], int n)
{
    int localMax = INT32_MIN;
    long long globalMax = LLONG_MIN;
    int i = 0;
    while (i < n)
    {
        localMax = max(localMax, arr[i] + localMax);
        if (localMax < globalMax)
        {
            globalMax = localMax;
        }
    }
    return globalMax;
}
// ********************************************************************
// Move all the negetive number to one side of the array

vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    // Write your code here.
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        if (nums[low] >= 0 && nums[high] < 0)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
        else
        {
            if (nums[low] < 0)
            {
                low++;
            }
            if (nums[high] >= 0)
            {
                high--;
            }
        }
    }
    return nums;
}
// *************************************************************
// Find union and intersection of tow arraysq
void findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m)
{
    // Write Your Code here.
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int start = 0;
    int end = 0;
    int currentElement;
    int commonCount = 0;
    vector<int> result;
    while (start < n && end < m)
    {
        if (arr1[start] < arr2[end])
            start++;
        else if (arr1[start] > arr2[end])
            end++;
        else
        {
            commonCount++;
            currentElement = arr1[start];
            start++;
            end++;
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
// *************************************************************
// Check subset problem.
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

// *********************************************************************
// pair sum problem
int pairSum(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int pairCount = 0;
    while (low < high)
    {
        if (arr[low] + arr[high] == target)
        {
            pairCount++;
            low++;
            high--;
        }
        else if (arr[low] + arr[high] < target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    if (pairCount > 0)
        return pairCount;
    else
        return -1;
}
// ******************************************************************
vector<int> commonInArray(vector<int> &arr1, vector<int> &arr2)
{
    int start = 0;
    int end = 0;
    int currentElement = arr1[start];
    int commonCount = 0;
    vector<int> result;
    while (start < arr1.size() && end < arr2.size())
    {
        if (arr1[start] < arr2[end])
            start++;
        else if (arr1[start] > arr2[end])
            end++;
        else
        {
            if (currentElement != arr1[start])
            {
                result.push_back(arr1[start]);
                currentElement = arr1[start];
            }
            start++;
            end++;
        }
    }
    return result;
}
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> res = commonInArray(a, b);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    vector<int> res2 = commonInArray(res, c);
    for (int i = 0; i < res2.size(); i++)
    {
        cout << res2[i] << " ";
    }
    cout << endl;
    return res2;
}

// **********************************************************************
// Subset sum equal to K
// Approach : Since subset generation take exponential time so in order to reduce the complexity
// dynamic programing approach is used because there are overlapping subproblems.

void showDPTable(bool *dp[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    //
    bool *dp[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new bool[k + 1];
        for (int j = 0; j < k + 1; j++)
        {
            dp[i][j] = false;
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    for (int j = 1; j < k + 1; j++)
    {
        dp[0][j] = false;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][k];
}
// completed time complexity O(n*k) space complexity O(n*k)
// **********************************************************************************
// factorial of a large number

// string calculateFactorial(int n)
// {
//     // Write your code here.
// }

// int fillCement(int arr[], int n)
// {

//     int left = 0, right = n - 1, left_max = INT_MIN, right_max = INT_MIN, cement_filled = 0;

//     while (left < right)
//     {
//         if (arr[left] < arr[right])
//         {
//             if (arr[left] > left_max)
//                 left_max = arr[left];
//             else
//                 cement_filled += (left_max - arr[left]);

//             left++;
//         }
//         else
//         {
//             if (arr[right] > right_max)
//                 right_max = arr[right];
//             else
//                 cement_filled += (right_max - arr[right]);
//             right--;
//         }
//     }
//     return cement_filled;
// *******************************************************************

int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int stock = prices[0];
    int index = 0;
    int end = prices.size();
    int maxProfit = INT32_MIN;

    while (index < end)
    {
        maxProfit = max(maxProfit, prices[index] - stock);
        if (prices[index] < stock)
        {
            stock = prices[index];
        }
        index++;
    }

    return maxProfit;
}
// Passed
// *******************************************************************
// Buy and sell stocks

int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    // find the pivot point
}

// *******************************************************************
// Chocholate Problem
int findMinDiff(int n, int m, vector<int> chocolates)
{
    // Write your code here.
    priority_queue<int> maxheap;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        maxheap.push(chocolates[i]);
    }
    int i = 0;
    int index = 0;
    int minimum = 0;
    int maximum = 0;
    int result = INT32_MAX;
    while (index <= n - m)
    {
        while (i < m)
        {
            q.push(maxheap.top());
            maxheap.pop();
            i++;
        }
        result = min(result, q.front() - q.back());
        q.pop();
        if (!maxheap.empty())
        {
            q.push(maxheap.top());
            maxheap.pop();
        }
        index++;
    }
    return result;
}

// *******************************************************************
// Merge Interval
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.

    sort(intervals.begin(), intervals.end());
    int index = 1;
    vector<vector<int>> result;
    int start = intervals[0][0];
    int end = intervals[0][1];
    while (index < intervals.size())
    {
        //  overlapping condition
        if (intervals[index][0] <= end)
        {
            start = min(start, intervals[index][0]);
            end = max(end, intervals[index][1]);
            index++;
        }
        else
        {
            result.push_back({start, end});
            start = intervals[index][0];
            end = intervals[index][1];
            index++;
        }
    }
    result.push_back({start, end});
    return result;
}

// *******************************************************************
// Next Permutation
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int end = n - 1;
    int index = n - 2;
    while (index >= 0)
    {
        if (permutation[index] > permutation[index + 1])
        {
            index--;
        }
        else
            break;
    }
    if (index >= 0)
    {

        while (end > index)
        {
            if (permutation[end] > permutation[index])
            {
                swap(permutation[end], permutation[index]);
                index = index + 1;
                break;
            }
            end--;
        }
        end = n - 1;
        while (index < end)
        {
            swap(permutation[index], permutation[end]);
            index++;
            end--;
        }
    }
    else
    {
        swap(permutation[index + 1], permutation[end]);
    }

    return permutation;
}
// *******************************************************************
int minimumJumps(vector<int> &arr, int n)
{
    // write your code here
    int jumpCount = 0;
    int start = 0;
    int end = n - 1;
    int index = 0;
    while (start < n)
    {
        if (arr[start] + start >= end)
        {
            jumpCount = jumpCount + 1;
            return jumpCount;
        }
        else if (arr[start] == 0)
        {
            return -1;
        }
        else if (n == 1)
        {
            return 0;
        }
        else
        {
            int maxJump = INT32_MIN;
            int maxJumpIndex = 0;
            for (int i = 1; i <= arr[start]; i++)
            {
                if (arr[start + i] + (start + i) > maxJump)
                {
                    maxJumpIndex = start + i;
                    maxJump = arr[start + i] + (start + i);
                }
            }
            jumpCount++;
            start = maxJumpIndex;
        }
    }
    return jumpCount;
}
// *******************************************************************

int main()
{
    vector<int> vect = {1, 2, 2, 3};
    vector<int> vect2 = {2, 2, 3, 3};
    vector<int> vect3 = {2, 2, 3};
    vector<int> res = findCommonElements(vect, vect2, vect3);
}
