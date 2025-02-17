#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';                // Place queen
                leftrow[row] = 1;                     // Mark the row as occupied
                lowerDiagonal[row + col] = 1;         // Mark lower diagonal as occupied
                upperDiagonal[n - 1 + col - row] = 1; // Mark upper diagonal as occupied

                solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n); // Recur to place next queen

                // Backtrack
                board[row][col] = '.';                // Remove queen
                leftrow[row] = 0;                     // Unmark the row
                lowerDiagonal[row + col] = 0;         // Unmark lower diagonal
                upperDiagonal[n - 1 + col - row] = 0; // Unmark upper diagonal
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;              // To store all the valid solutions
        vector<string> board(n, string(n, '.')); // Initialize the board with '.' (empty squares)
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n); // Start solving from the first column
        return ans;                                                     // Return all found solutions
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n; // Input the size of the board

    vector<vector<string>> results = solution.solveNQueens(n); // Get all solutions

    cout << "--------All possible solutions--------" << endl;
    for (const auto &board : results)
    {
        for (const auto &row : board)
        {
            cout << row << endl; // Print each row of the board
        }
        cout << endl; // Separate different solutions
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     void solve(int col, vector<string> &board, vector<int> &leftRow,
//                vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<vector<string>> &ans, int n)
//     {
//         if (col == n)
//         {
//             ans.push_back(board);
//             return;
//         }

//         for (int row = 0; row < n; row++)
//         {
//             if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
//             {
//                 board[row][col] = 'Q';
//                 leftRow[row] = 1;
//                 lowerDiagonal[row + col] = 1;
//                 upperDiagonal[n - 1 + col - row] = 1;

//                 solve(col + 1, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);

//                 board[row][col] = '.';
//                 leftRow[row] = 0;
//                 lowerDiagonal[row + col] = 0;
//                 upperDiagonal[n - 1 + col - row] = 0;
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n, '.'));
//         vector<int> leftRow(n, 0);
//         vector<int> upperDiagonal(2 * n - 1, 0);
//         vector<int> lowerDiagonal(2 * n - 1, 0);

//         solve(0, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
//         return ans;
//     }
// };
// int main()
// {
//     Solution solution;
//     int n;
//     vector<vector<string>> results;

//     cout << "Enter n: ";
//     cin >> n;
//     cout << endl;

//     results = solution.solveNQueens(n);

//     for (const auto &board : results)
//     {
//         for (const auto &row : board)
//         {
//             cout << row << endl;
//         }
//         cout << "\n------------\n";
//     }
//     return 0;
// } 