#include <iostream>
using namespace std;
bool isMaxHeap(int arr[], int n) {
    for(int i=1;i<n;i++){
        int parent =(i-1)/2;
        if(arr[parent]<arr[i]){
            return false;
        }
    }
    return true;
}



int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}