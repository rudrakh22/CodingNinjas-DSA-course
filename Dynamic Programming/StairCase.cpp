#include<iostream>
using namespace std;
//coding ninja
int StairCase(int n){
long long mod=1e9+7;
if(n<=1){
  return 1;
}
long long a=1,b=1,c=2;
for(int i=0;i<=n-3;i++){
  long long d=(a+b+c)%mod;
  a=b;
  b=c;
  c=d;
}
return c;
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    cout<<StairCase(n)<<endl;
    }
} 