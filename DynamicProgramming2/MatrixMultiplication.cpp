#include <iostream>
#include<climits>
#include<vector>
using namespace std;
int mcm(int *arr,int s,int e){
    if(e-s==1)return 0;
    int ans=INT_MAX;
    for(int i=s+1;i<e;i++){
        ans=min(ans,(mcm(arr,s,i)+mcm(arr,i,e)+arr[s]*arr[i]*arr[e]));
    }
    return ans;
}
int matrixChainMultiplication1(int *arr, int n) {
return mcm(arr,0,n);
}
//memoisation
int mcm(int *arr,int s,int e,vector<vector<int>> &dp){
    if(e-s==1)return 0;
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    int ans=INT_MAX;
    for(int i=s+1;i<e;i++){
        ans=min(ans,(mcm(arr,s,i,dp)+mcm(arr,i,e,dp)+arr[s]*arr[i]*arr[e]));
    }
    dp[s][e]=ans;
    return ans;
}
int matrixChainMultiplication2(int *arr, int n) {
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
return mcm(arr,0,n,dp);
}
//dynamic programming
int matrixChainMultiplication3(int*arr,int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    for(int i=1;i<n;i++){
        dp[i][i]=0;
    }
    for(int L=2;L<n;L++){
        for(int i=1;i<n-L+1;i++){
            int j=i+L-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q= min(dp[i][j],dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]));
                if(q<dp[i][j]){
                    dp[i][j]=q;
                }
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i <=n; i++) {
        cin >> arr[i];
    }
    cout << matrixChainMultiplication1(arr, n);
    cout << matrixChainMultiplication2(arr, n);
    cout << matrixChainMultiplication3(arr, n+1);

    delete[] arr;
}


