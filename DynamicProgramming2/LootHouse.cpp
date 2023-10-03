#include<iostream>
using namespace std;
//brute force
int lootHouse(int *input,int n){
    if(n<0){
        return 0;
    }
    int a=input[n]+lootHouse(input,n-2);
    int b=lootHouse(input,n-1);
    return max(a,b);
}
//mmemoisation
int lootHouse_mem(int *input,int n,int* output){
    if(n<0){
        return 0;
    }
    if(output[n]!=-1){
        return output[n];
    }
    int a=input[n]+lootHouse_mem(input,n-2,output);
    int b=lootHouse_mem(input,n-1,output);
    output[n]=max(a,b);
    return output[n];
}
int lootHouse_mem(int *input,int n){
int* output=new int[n+1];
for(int i=0;i<=n;i++){
    output[i]=-1;
}
lootHouse_mem(input,n,output);
}
//dynamic programming
int lootHouse_dp(int *input,int n){
    int *dp=new int[n];
    dp[0]=input[0];
    if(n>1){
    dp[1]=max(input[0],input[1]);}
    for(int i=2;i<n;i++){
    dp[i]=max(dp[i-2]+input[i],dp[i-1]);
    }
    int result=dp[n-1];
    delete [] dp;
    return result;
}
int main(){
    int n;
    cin>>n;
    int*input=new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<lootHouse(input,n)<<endl;
    cout<<lootHouse_mem(input,n)<<endl;
    cout<<lootHouse_dp(input,n)<<endl;
}

// 6
// 5 5 10 100 10 5