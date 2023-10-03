#include<iostream>
#include<climits>
using namespace std;
int editDistance(string s,string t){
    if(s.size()==0 || t.size()==0){
        return max(s.size(),t.size());
    }
    if(s[0]==t[0]){
        return editDistance(s.substr(1),t.substr(1));
    }
    else{
    int x=editDistance(s.substr(1),t);
    int y=editDistance(s,t.substr(1));
    int z=editDistance(s.substr(1),t.substr(1));
    int ans=1+min(x,min(y,z));
    return  ans;
    }
}
//memoisation
int editDistance(string s,string t,int **output){
    if(s.size()==0 || t.size()==0){
        return max(s.size(),t.size());
    }
    int m=s.size(),n=t.size();
    if(output[m][n]!= -1){
        return output[m][n];
    }
    int ans;
    if(s[0]==t[0]){
        ans= editDistance(s.substr(1),t.substr(1),output);
    }
    else{
        int x=editDistance(s.substr(1),t,output);
        int y=editDistance(s,t.substr(1),output);
        int z=editDistance(s.substr(1),t.substr(1),output);
        ans=1+min(x,min(y,z));
    }
    output[m][n]=ans;
    return ans;
}
int editDistance_mem(string s,string t){
    int m=s.size(),n=t.size();
    int**output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    return editDistance(s,t,output);
}
//dynamic programming
int editDistance_dp(string s,string t){
    int m=s.size(),n=t.size();
    int**output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
    }
    for(int j=0;j<=n;j++){
        output[0][j]=j;
    }
    for(int i=1;i<=m;i++){
        output[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(s[m-i]==t[n-j]){
                output[i][j]=output[i-1][j-1];
            }
            else{
                int x=output[i-1][j];
                int y=output[i][j-1];
                int z=output[i-1][j-1];
                output[i][j]=1+min(x,min(y,z));
            }
        }
    }
    return output[m][n];
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t)<<endl;
    cout<<editDistance_mem(s,t)<<endl;
    cout<<editDistance_dp(s,t)<<endl;
}