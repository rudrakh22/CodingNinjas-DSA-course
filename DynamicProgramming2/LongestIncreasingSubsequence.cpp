#include<iostream>
#include<vector>
using namespace std;
int lis(int* input,int n){
vector<int> output(n);
int ans=1;
output[0]=1;
for(int i=1;i<n;i++){
    int max=1;
    for(int j=i-1;j>=0;j--){
        if(input[j]<input[i]){
            int op=output[j]+1;
            if(op>max){
                max=op;
            }
        }
    }
    output[i]=max;
    if(max>ans){
        ans=max;
    }
}
return ans;
}
int main(){
    int n;
    cin>>n;
    int *input=new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int ans=lis(input,n);
    cout<<ans<<endl;
}