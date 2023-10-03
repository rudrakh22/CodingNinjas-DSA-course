#include <bits/stdc++.h>
using namespace std;
//Dynamic Programming
int countMinStepsToOne2(int n){
    int *ans=new int[n+1];
    ans[1]=0;
    for(int i=2;i<=n;i++){
        int x=ans[i-1];
        int y=INT_MAX,z=INT_MAX;
        if(i%2==0){
            y=ans[i/2];
        }
        if(i%3==0){
            z=ans[i/3];
        }
        ans[i]=min(x,min(y,z))+1;
    }
    int result=ans[n];
    delete [] ans;
    return result;
}
// memoisation
int helper(int n, int *ans)
{
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (n <= 1)
    {
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    x = helper(n - 1, ans);
    if (n % 2 == 0)
    {
        y = helper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = helper(n / 3, ans);
    }
    ans[n] = min(x, min(y, z))+1;
    return ans[n];
}
int countMinStepsToOne1(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        ans[i] = -1;
    }
    return helper(n, ans);
}
// brute force
int countMinStepsToOne(int n)
{
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (n <= 1)
    {
        return 0;
    }

    x = countMinStepsToOne(n - 1);
    if (n % 2 == 0)
    {
        int y = countMinStepsToOne(n / 2);
    }
    if (n % 3 == 0)
    {
        z = countMinStepsToOne(n / 3);
    }
    int ans = min(x, min(y, z)) + 1;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);

    cout << countMinStepsToOne1(n);
    cout << countMinStepsToOne2(n);
}