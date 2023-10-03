#include<iostream>
#include<vector>
using namespace std;
//runtime error
// int f(char* s1,char *s2,int l1,int l2,vector<vector<int>> &dp){
//     if(l1<=0){
//         return 1001;
//     }
//     if(l2<=0){
//         return 1;
//     }
//     if(dp[l1][l2]!= -1){
//         return dp[l1][l2];
//     }
//     int ans=0;
//     int a=f(s1+1,s2,l1-1,l2,dp);
//     int i=0;
// for(;i<l2;i++){
//     if(s1[0]==s2[i]){
//         break;
//     }
// }
//     if(i==l2){
//         return 1;
//     }
//     int b=1+f(s1+1,s2+i+1,l1-1,l2-i-1,dp);
//     ans=min(a,b);
//     dp[l1][l2]=ans;
//     return ans;
// }
// int shortestUncommonSubsequence(string s,string t){
//     int n=s.length();
//     int m=t.length();
//     char*s1=new char[n];
//     char*s2=new char[m];

//     for(int i=0;i<n;i++){
//         s1[i]=s[i];
//     }
//     for(int i=0;i<m;i++){
//         s2[i]=t[i];
//     }
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
// return f(s1,s2,n,m,dp);
// }
int solve(string s,string t){
        int n=s.length();
    int m=t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    vector<vector<int>> next(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        int prev=-1;
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                prev=j;
            }
            next[i+1][j+1]=prev;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=1e9;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(next[i][j] == -1){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=min(dp[i-1][j],1+dp[i-1][next[i][j]]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<solve(s,t);
}