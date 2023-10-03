#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int lcs(string s,string t){
    if(s.size()==0 || t.size()==0){
        return  0;
    }
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }
    else{
        int a=lcs(s.substr(1),t);
        int b=lcs(s,t.substr(1));
        int c=lcs(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }
}
int lcs_mem(string s,string t,int**output){
    if(s.size()==0 || t.size()==0) return 0;
    int m=s.size(),n=t.size();
    int ans;
    if(output[m][n]!=-1){
        return output[m][n];
    }
    if(s[0]==t[0]){
        ans =1+lcs_mem(s.substr(1),t.substr(1),output);
    }
    else{
        int a=lcs_mem(s.substr(1),t,output);
        int b=lcs_mem(s,t.substr(1),output);
        int c=lcs_mem(s.substr(1),t.substr(1),output);
        ans= max(a,max(b,c));
    }
    output[m][n]=ans;
    return ans;
}
int lcs_mem(string s,string t){\
    int m=s.size(),n=t.size();
    int**output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]= new int [n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    return lcs_mem(s,t,output);
}
//dynamic programming
int lcs_dp(string s,string t){
    int m=s.size(),n=t.size();
    int**output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
    }
    for(int j=0;j<=n;j++){
        output[0][j]=0;
    }
    for(int i=1;i<=m;i++){
        output[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                output[i][j]=1+output[i-1][j-1];
            }
            else{
                output[i][j]=max(output[i-1][j-1],max(output[i-1][j],output[i][j-1]));
            }
        }
    }
    return output[m][n];
}
int lcs_op(string s,string t){
    int m=s.size(),n=t.size();
    vector<int> dp(n+1,0),prev(n+1,0);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                dp[j]=1+prev[j-1];
            }
            else{
                dp[j]=max(prev[j],dp[j-1]);
            }
            prev=dp;
        }
    }
    return dp[m];
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;
    cout<<lcs_mem(s,t)<<endl;
    cout<<lcs_dp(s,t)<<endl;
    cout<<lcs_op(s,t);
}