#include<iostream>
using namespace std;
//brute force
int fibo1(int n){
    if(n<=1){
        return n;
    }
    int a=fibo1(n-1);
    int b=fibo1(n-2);
    return a+b;
}
// Memoization
int fibo_helper(int n,int * ans){
    if(n<=1){
        return n;
    }
    if(ans[n] != -1){
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);
    ans[n]=a+b;
    return ans[n];
}
int fibo2(int n){
    int * ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}
// dynamic Programming
int fibo3(int n){
    int * ans=new int[n+1];
    ans[0]=0;ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}
int main(){
int n;
cin>>n;
int a=fibo1(n);
cout<<a;

}