#include <bits/stdc++.h>
using namespace std;

// ****************************
void printDPTable(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// ****************************
// Coin change problem with infinite coins

int coinChangeHelper(vector<int> &coins, int amount, int index, int count)
{
    if (index >= coins.size())
        return INT32_MAX;
    else if (amount < 0)
        return INT32_MAX;
    else if (amount == 0)
        return count;
    else
        return min(coinChangeHelper(coins, amount - coins[index], index, count + 1), coinChangeHelper(coins, amount, index + 1, count));
}

int coinChange(vector<int> &coins, int amount)
{
    int res = coinChangeHelper(coins, amount, 0, 0);
    if (res == INT32_MAX)
        return -1;
    else
        return res;
}
// Recurssive solution

int coinChangeDp(vector<int> &arr, int amount)
{
    int size = arr.size();
    int *dp[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        dp[i] = new int[amount + 1];
        for (int j = 0; j < amount + 1; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (arr[i - 1] < j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                if (dp[i][j - arr[i - 1]] < dp[i - 1][j])
                {
                    dp[i][j] = dp[i][j - arr[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    printDPTable(dp, size + 1, amount + 1);
    return dp[size][amount];
}

// *************************************
// Best time to buy and sell stock with cooldown
int maxProfit(vector<int> &prices)
{
}
// *************************************
// House robbers
int rob(vector<int> &nums)
{
    int dp[nums.size() + 2];
    for (int i = 0; i < nums.size() + 2; i++)
    {
        dp[i] = 0;
    }
    for (int i = 2; i < nums.size() + 2; i++)
    {
        dp[i] = max(dp[i - 1], nums[i - 2] + dp[i - 2]);
    }
    return dp[nums.size() + 1];
}

// *************************************
// Can partition ( equal subset sum problem)
bool canPartitionHelper(vector<int> &nums, int index, int sum_1, int sum_2)
{
    if (index >= nums.size())
    {
        return false;
    }
    else if (sum_1 > sum_2)
    {
        return false;
    }

    else if (sum_1 == sum_2)
    {
        return true;
    }
    else
    {

        for (int i = index; i < nums.size(); i++)
        {
            return canPartitionHelper(nums, i + 1, sum_1 + nums[i], sum_2 - nums[i]) + canPartitionHelper(nums, i + 1, sum_1, sum_2);
        }
    }
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
    }
    return canPartitionHelper(nums, 0, 0, sum);
}

// DP Approach

// *************************************

int main()
{
    vector<int> vect = {1, 2, 3, 5};
    cout << canPartition(vect) << endl;
}