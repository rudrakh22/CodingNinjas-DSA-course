#include<iostream>
using namespace std;
void reverse(int *arr,int s,int e){
    while(s<e){
        int temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
        s++;e--;
    }
}
void rotateArray(int *arr,int n,int d){
reverse(arr,0,n-1);
reverse(arr,0,d);
reverse(arr,d+1,n-1);
}
int main(){
    int n;
cin>>n;
int arr[n];
for(int i=0;i<5;i++){
    cin>>arr[i];
}
int d;
cin>>d;
rotateArray(arr,n,d);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
// cout<<endl;
// int d;
// cin>>d;
// reverse(arr,0,d);
// for(int i=0;i<5;i++){
//     cout<<arr[i]<<" ";
// }
// cout<<endl;

// reverse(arr,d+1,4);
// for(int i=0;i<5;i++){
//     cout<<arr[i]<<" ";
// }
}