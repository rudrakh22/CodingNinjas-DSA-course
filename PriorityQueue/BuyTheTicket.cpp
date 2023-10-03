#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int buyTicket(int *arr, int n, int k) {
queue<int> p;
priority_queue<int>pq;
for(int i=0;i<n;i++){
    p.push(i);
    pq.push(arr[i]);
}
int time=0;
while(p.front() !=k || pq.top()!=arr[p.front()]){
    if(pq.top()==arr[p.front()]){
        pq.pop();
        p.pop();
        time++;
    }
    else{
        p.push(p.front());
        p.pop();
    }
}
    return time+1;
}
int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}

// 5
// 2 3 2 2 4
// 3