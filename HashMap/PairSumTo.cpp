#include <iostream>
using namespace std;
#include<unordered_map>
int pairSum(int *input, int n) {
unordered_map<int,int>freq;
int pairCount=0;
for(int i=0;i<n;i++){
    int complement=-input[i];
    if(freq.find(complement) != freq.end()){
        pairCount+=freq[complement];
    }
    freq[input[i]]++;
}
return pairCount;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}