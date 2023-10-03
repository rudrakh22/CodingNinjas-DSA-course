#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;
int balancedBTs(int n)
{
    if (n <= 1)
        return 1;
    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);
    long long int temp1 = x * x;
    temp1 = temp1 % mod;
    long long int temp2 = 2 * x * y;
    temp2 = temp2 % mod;
    return (temp1 + temp2) % mod;
}
// memoisation
int balancedBTs(int n, int *ans)
{
    if (n <= 1)
    {
        return 1;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);
    long long int temp1 = x * x;
    temp1 = temp1 % mod;
    long long int temp2 = 2 * x * y;
    temp2 = temp2 % mod;
    ans[n] = (temp1 + temp2) % mod;
    return ans[n];
}
int balancedBTs_mem(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return balancedBTs(n, ans);
}
// dynamic programming

int balancedBTs_dp(int n)
{
    vector<long long int> ans(n + 1);

    if (n <= 1)
    {
        return 1;
    }
    ans[0] = 1;
    ans[1] = 1;
    int mod = pow(10, 9) + 7;
    for (int i = 2; i <= n; i++)
    {
        long long int temp1 = ans[i - 1] * ans[i - 1];
        temp1 = temp1 % mod;
        long long int temp2 = 2 * ans[i - 1] * ans[i - 2];
        temp2 = temp2 % mod;
        ans[i] = (temp1 + temp2) % mod;
    }
    return ans[n];
}
int main()
{
    int n;
    cin >> n;
    // cout << balancedBTs(n)<<endl;
    cout << balancedBTs_mem(n)<<endl;
    cout << balancedBTs_dp(n);
}