#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
vector<int>kSmallest(int arr[],int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int>output;
    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}
//Time Complexity : nlog(k)
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}