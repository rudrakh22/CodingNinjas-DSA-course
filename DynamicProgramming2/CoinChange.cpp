#include<iostream>
#include<vector>
using namespace std;
int countWaysToMakeChange1(int denominations[], int numDenominations, int value){
    if(numDenominations==0){
        return value%denominations[0]==0;
    }
int a=countWaysToMakeChange1(denominations,numDenominations-1,value);
int b=0;
if(denominations[numDenominations]<=value){
    b=countWaysToMakeChange1(denominations,numDenominations,value-denominations[numDenominations]);
}
return a+b;
}
int helper(int ind,int t,int *a,vector<vector<int>> &dp){
    if(ind==0){
        return t%a[0]==0;
    }
    if(dp[ind][t]!=-1){
        return dp[ind][t];
    }
    int x=helper(ind-1,t,a,dp);
    int y=0;
    if(a[ind]<=t){
        y=helper(ind,t-a[ind],a,dp);
    }
    dp[ind][t]=x+y;
    return dp[ind][t];
}
int countWaysToMakeChange2(int denominations[],int numDenominations,int value){
    vector<vector<int>>dp(numDenominations,vector<int>(value+1,-1));
    return helper(numDenominations-1,value,denominations,dp);
}
//dynamic programmming
int helper(int ind,int t,int *a){
    vector<vector<int>>dp(ind,vector<int>(t+1,0));
    for(int i=0;i<=t;i++){
        dp[0][i]=i%a[0]==0;
    }
    for(int i=1;i<ind;i++){
        for(int j=0;j<=t;j++){
            int x=dp[i-1][j];
            int y=0;
            if(a[i]<=j){
                y=dp[i][j-a[i]];
            }
            dp[i][j]=x+y;
        }
    }
    return dp[ind-1][t];
    }
int countWaysToMakeChange3(int denominations[],int numDenominations,int value){
    return helper(numDenominations,value,denominations);
}
//optimal
int helper2(int ind,int t,int *a){
    vector<int>curr(t+1,0),prev(t+1,0);
    for(int j=0;j<=t;j++){
        prev[j]=j%a[0]==0;
    }
    for(int i=1;i<ind;i++){
        for(int j=0;j<=t;j++){
            int x=prev[j];
            int y=0;
            if(a[i]<=j){
                y=curr[j-a[i]];
            }
            curr[j]=x+y;
        }
        prev=curr;
    }
return prev[t];
}

int countWaysToMakeChange4(int denominations[],int numDenominations,int value){
    return helper2(numDenominations,value,denominations);
}
int main(){
    int numDenominations;
    cin >> numDenominations;
    int *denominations = new int[numDenominations];
    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }
    int value;
    cin >> value;
    // cout << countWaysToMakeChange1(denominations, numDenominations, value);
    cout << countWaysToMakeChange2(denominations, numDenominations, value);
    cout << countWaysToMakeChange3(denominations, numDenominations, value);
    cout << countWaysToMakeChange4(denominations, numDenominations, value);
    delete[] denominations;
}                    