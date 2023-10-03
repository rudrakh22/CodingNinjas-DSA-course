#include<iostream>
#include<climits>
using namespace std;
//brute force
int minCount(int n){
    if(n<=3) return n;
    int val=n;
    for(int i=1;i*i<=n;i++){
        val=min(val,1+minCount(n-i*i));
    }
    return val;
}
//memoisation
int minCount(int n,int*ans){
    if(n<=3){
        return n;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int val=n;
    for(int i=1;i*i<=n;i++){
        val=min(val,1+minCount(n-i*i));
    }
    ans[n]=val;
    return val;
}
int minCount_mem(int n){
    int * ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return minCount(n,ans);
}
//dynamic programming
int minCount_dp(int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=i;
        for(int j=1;j*j<=i;j++){
            ans[i]=min(ans[i],ans[i-j*j]);
        }
        ans[i]+=1;
    }
    return ans[n];
}
int main(){
int n;
cin>>n;
cout<<minCount(n)<<endl;
cout<<minCount_mem(n)<<endl;
cout<<minCount_dp(n)<<endl;
}