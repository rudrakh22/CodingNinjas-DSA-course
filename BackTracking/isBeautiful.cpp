#include<iostream>
using namespace std;
bool check(int num){
        int n;
        int even=0;
        int odd=0;
    while(num>0){
        n=num%10;
        if(n==0){
            even++;
        }
        else if(n%2==0){
            even++;
        }
        else{
            odd++;
        }
        num=num/10;
    }
    return odd==even;
}
int isBeautiful(int low,int high,int k){
    int count=0;
    for(int i=low;i<=high;i++){
        if(check(i)){
            if(i%k==0){
                count++;
            }
        }
    }
    return count;
}
int main(){
int a,b,k;
cin>>a>>b>>k;
cout<<isBeautiful(a,b,k);
}