#include<bits/stdc++.h>
using namespace std;
int f(int *a,int i,int j){
    if(i==j){
        return 0;
    }
    int mini=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=a[i-1]*a[k]*a[j]+f(a,i,k)+f(a,k+1,j);
        if(steps<mini){
            mini=steps;
        }
    }
    return mini;
}
int matrixChainMultiplication(int *a,int n){
    return f(a,1,n-1);
}
//memoisation
int f(int *a,int i,int j,vector<vector<int>> &dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=a[i-1]*a[k]*a[j]+f(a,i,k,dp)+f(a,k+1,j,dp);
        if(steps<mini){
            mini=steps;
        }
    }
    return dp[i][j]=mini;
}
int matrixChainMultiplication1(int *a,int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(a,1,n-1,dp);
}
//dynamic programming
int matrixChainMultiplication2(int *a,int n){
    int dp[n][n];
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=INT_MAX;
            for(int k=i;k<j;k++){
                int steps=a[i-1]*a[k]*a[j]+dp[i][k]+dp[k+1][j];
                if(steps<mini){
                    mini=steps;
                }
            }
            dp[i][j]=mini;
        }
    }
return dp[1][n-1];
}
int main(){
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<matrixChainMultiplication(a,n)<<endl;
    cout<<matrixChainMultiplication1(a,n)<<endl;
    cout<<matrixChainMultiplication2(a,n)<<endl;
}