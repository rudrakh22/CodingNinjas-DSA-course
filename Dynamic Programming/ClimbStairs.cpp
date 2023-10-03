#include <iostream>
using namespace std;
int climbStairs(int n){
    if(n<=2){
        return n;
    }
    return climbStairs(n-1)+climbStairs(n-2);
}
//   memoisation
int solve(int n, int *ans)
{
    if (n <= 2)
    {
        return n;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    ans[n] = solve(n - 1, ans) + solve(n - 2, ans);
    return ans[n];
}
int climbStairs2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return solve(n, ans);
}
//   Dynamic Programming
int climbStairs3(int n)
{
    int *ans = new int[n + 1];
    if (n <= 2)
    {
        return n;
    }
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}
int main(){
    int n;
    cin>>n;
    cout<<climbStairs2(n)<<endl;
}