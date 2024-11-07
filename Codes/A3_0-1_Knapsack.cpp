/*
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapsack(int capacity, vector<int> &price, vector<int> &wt)
    {
        int items = price.size(); // Number of items
        vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));

        // Fill the dp table
        for (int i = 0; i <= items; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                if (i == 0 || j == 0)
                {
                    // There's nothing to add to Knapsack
                    dp[i][j] = 0;
                }
                else if (wt[i - 1] <= j)
                {
                    // Choose previously maximum or value of current item + value of remaining weight
                    dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
                else
                {
                    // Add previously added item to knapsack
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[items][capacity]; // Return the maximum profit
    }
};

int main()
{
    Solution solution;
    int capacity = 10;
    vector<int> price = {3, 7, 2, 9};
    vector<int> wt = {2, 2, 4, 5};

    int maxProfit = solution.knapsack(capacity, price, wt);
    cout << "Maximum Profit Earned: " << maxProfit << "\n";
    return 0;
}
*/














#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapsack(int capacity, vector<int> &price, vector<int> &wt, vector<int> &includedItems)
    {
        int items = price.size(); // Number of items
        vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));

        // Fill the dp table
        for (int i = 0; i <= items; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0; // No items or zero capacity means zero profit
                }
                else if (wt[i - 1] <= j)
                {
                    // Choose previously maximum or value of current item + value of remaining weight
                    dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
                else
                {
                    // Add previously added item to knapsack
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Initialize includedItems with 0s, indicating all items are initially not included
        includedItems = vector<int>(items, 0);

        // Backtrack to find the items included in the knapsack
        int j = capacity;
        for (int i = items; i > 0 && j > 0; i--)
        {
            if (dp[i][j] != dp[i - 1][j])
            {
                includedItems[i - 1] = 1; // Mark item i-1 as included
                j -= wt[i - 1];           // Reduce capacity by the weight of the included item
            }
        }
        return dp[items][capacity]; // Return the maximum profit
    }
};

int main()
{
    Solution solution;
    int capacity = 10;
  vector<int> price = {3, 7, 2, 9};
    vector<int> wt = {2, 2, 4, 5};

    vector<int> includedItems;
    int maxProfit = solution.knapsack(capacity, price, wt, includedItems);

    cout << "Maximum Profit Earned: " << maxProfit << "\n";

    cout << "Items included (0 = not included, 1 = included): ";

    for (auto included : includedItems)
    {
        cout << included << " ";
    }
    cout << "\n";

    return 0;
}










// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int knapsack(int capacity, vector<int> price, vector<int> wt, vector<int> &includedItems)
//     {
//         int items = price.size();

//         vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));
//         for (int i = 0; i <= items; i++)
//         {
//             for (int j = 0; j <= capacity; j++)
//             {
//                 if (i == 0 || j == 0)
//                 {
//                     dp[i][j] = 0;
//                 }
//                 else if (wt[i - 1] <= j)
//                 {
//                     dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i - 1][j - wt[i - 1]]);
//                 }
//                 else
//                 {
//                     dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }

//         includedItems = vector<int>(items, 0);
//         int j = capacity;
//         for (int i = items; i > 0 && j > 0; i--)
//         {
//             if (dp[i][j] != dp[i - 1][j])
//             {
//                 includedItems[i - 1] = 1;
//                 j = j - wt[i - 1];
//             }
//         }
//         return dp[items][capacity];
//     }
// };

// int main()
// {
//     Solution solution;

//     int capacity = 10;
//     vector<int> price = {3, 7, 2, 9};
//     vector<int> wt = {2, 2, 4, 5};
//     vector<int> includedItems;

//     int maxProfit = solution.knapsack(capacity, price, wt, includedItems);
//     cout << "\n\tMax Profit = " << maxProfit;

//     cout << "\n\n\tIncluded Items: ";
//     for (auto item : includedItems)
//     {
//         cout << item << " ";
//     }
//     return 0;
// }