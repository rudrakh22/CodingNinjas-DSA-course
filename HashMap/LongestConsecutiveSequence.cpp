#include <iostream>
#include <vector>
using namespace std;
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
unordered_map<int,bool> visited;
unordered_map<int,int> elements;
for(int i=0;i<n;i++){
    elements[arr[i]]=i;
    if(visited.count(arr[i])==0){
        visited[arr[i]]=true;
    }
}
vector<int> longestSequence;
int globalMaxSeq=1;
int globalMinStartIndex=0;
for(int i=0;i<n;i++){
    int num=arr[i];
    int currentMinStartIndex=i;
    int count=0;
    int tempNum=num;
    while(visited.count(tempNum)==1 && visited[tempNum]==true){
        visited[tempNum]=false;
        count++;
        tempNum++;
    }
    tempNum=num-1;
    while(visited.count(tempNum)==1 && visited[tempNum]==true){
        visited[tempNum]=false;
        count++;
        currentMinStartIndex=elements[tempNum];
        tempNum--;
    }
    if(count>globalMaxSeq){
        globalMaxSeq=count;
        globalMinStartIndex=currentMinStartIndex;
    }
    else if(count==globalMaxSeq){
        if(currentMinStartIndex<globalMinStartIndex){
            globalMinStartIndex=currentMinStartIndex;
        }
    }
}
int globalStartNum=arr[globalMinStartIndex];
longestSequence.push_back(globalStartNum);
if(globalMaxSeq>1){
    longestSequence.push_back(globalStartNum+globalMaxSeq-1);

}
return longestSequence;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
