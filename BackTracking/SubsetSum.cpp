#include<iostream>
using namespace std;
int subsetCount(int a[],int n,int k,int i){
if(i==n){
    if(k==0){
        return 1;
    }
    else{
        return 0;
    }
}
int count=0;
if(k-a[i]>=0){
count+=subsetCount(a,n,k-a[i],i+1);
}
count+=subsetCount(a,n,k,i+1);
return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<subsetCount(a,n,k,0)<<endl;
    }
}