#include <iostream>
using namespace std;
// brute force
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }
    if (weights[0] > maxWeight)
    {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }
    else
    {
        int a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
        int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
        return max(a, b);
    }
}
// memoization
int knapsack_mem(int *weights, int *values, int n, int maxWeight, int **output)
{
    if (maxWeight == 0 || n == 0)
    {
        return 0;
    }
    if (output[n][maxWeight] != -1)
    {
        return output[n][maxWeight];
    }
    int ans;
    if (maxWeight < weights[0])
    {
        ans = knapsack_mem(weights + 1, values + 1, n - 1, maxWeight, output);
    }
    else
    {
        int a = knapsack_mem(weights + 1, values + 1, n - 1, maxWeight - weights[0], output) + values[0];
        int b = knapsack_mem(weights + 1, values + 1, n - 1, maxWeight, output);
        ans = max(a, b);
    }
    output[n][maxWeight] = ans;
    return ans;
}
int knapsack_mem(int *weights, int *values, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            output[i][j] = -1;
        }
    }
    return knapsack_mem(weights, values, n, maxWeight, output);
}
// Dynamic Programming
int knapsack_dp(int *weights, int *values, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
    }
    for (int j = 0; j <= maxWeight; j++)
    {
        output[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (weights[i - 1] <= j)
            {
                output[i][j] = max(values[i - 1] + output[i - 1][j - weights[i - 1]], output[i - 1][j]);
            }
            else
            {
                output[i][j] = output[i - 1][j];
            }
        }
    }
    return output[n][maxWeight];
}
int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;
    cout << knapsack_mem(weights, values, n, maxWeight) << endl;
    cout << knapsack_dp(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}

// 4
// 1 2 4 5
// 5 4 8 6
// 5