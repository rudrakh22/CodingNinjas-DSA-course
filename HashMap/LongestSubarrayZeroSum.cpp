#include <iostream>
using namespace std;
#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n){
unordered_map<int,int>m;
int sum=0,length=0;
for(int i=0;i<n;i++){
    sum+=arr[i];
    if(arr[i]==0 && length==0){
        length=1;
    }
    if(sum==0){
        length=i+1;
    }
    if(m.count(sum)>0){
        length=max(length,i-m[sum]);
    }
    else{
        m[sum]=i;
    }
}
return length;
}
int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}