#include <iostream>
#include<vector>
#include<climits>
using namespace std;
class PriorityQueue{
    vector<int> data;
    public:
    void insert(int element){
        data.push_back(element);
        int childIndex=data.size()-1;
        while(childIndex>0){
        int parentIndex=(childIndex-1)/2;
            if(data[childIndex]>data[parentIndex]){
                int temp=data[childIndex];
                data[childIndex]=data[parentIndex];
                data[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    bool isEmpty(){
        return data.size()==0;
    }
    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return data[0];
    }
    int getSize(){
        return data.size();
    }
    int removeMax(){
        if(data.size()==0){
            return INT_MIN;
        }
        int ans=data[0];
        data[0]=data[data.size()-1];
        data.pop_back();
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        while(leftChildIndex<data.size()){
            int maxIndex=parentIndex;
            if(data[maxIndex]<data[leftChildIndex]){
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<data.size() && data[maxIndex]<data[rightChildIndex]){
                maxIndex=rightChildIndex;
            }
            if(parentIndex==maxIndex){
                break;
            }
            int temp=data[maxIndex];
            data[maxIndex] = data[parentIndex];
            data[parentIndex]=temp;
            parentIndex=maxIndex;
            leftChildIndex=2*parentIndex+1;
            rightChildIndex=2*parentIndex+2;
        }
    return ans;
    }
    
};
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}












// #include <vector>
// #include<climits>
// class PriorityQueue {
//     // Complete this class
//     vector <int> pq;
    
//     public:
//     int getSize(){
//         return pq.size();
//     }
//     bool isEmpty(){
//         return getSize()==0;
//     }
//     int getMax()
//     {
//         if(pq.size()==0) return INT_MIN;
        
//         return pq[0];
//     }
//     void insert(int element)
//     {
//         pq.push_back(element);
//         int ci=pq.size()-1;
//         int pi=(ci-1)/2;
        
//         while(pi>=0 && pq[pi]<pq[ci])
//         {
//            // swap
//             int temp=pq[ci];
//             pq[ci]=pq[pi];
//             pq[pi]=temp;
            
//             ci=pi;
//             pi=(ci-1)/2;
//         }
            
//     }
//     int removeMax()
//     {
//         if(isEmpty()) return INT_MIN;
        
//         int ans = pq[0];
        
//         pq[0]=pq[pq.size()-1];
        
//         pq.pop_back();
        
//         int i=0;
//         while (i<pq.size())
//         {
//             if(2*i+1 >= pq.size()) break; //absence of left child
//             else
//             {
//                 if(2*i+2 >= pq.size()) //no right chiid
//                 {
//                     if(pq[i]<pq[2*i+1])
//                     {
//                         int temp =pq[i];
//                         pq[i]=pq[2*i+1];
//                         pq[i]=temp;
//                         i=2*i+1;
//                     }
//                     else break;
//                 }
//                 else
//                 {
//                     if(pq[2*i+1]>pq[2*i+2]) //left child is max
//                     {
//                         int temp =pq[i];
//                         pq[i]=pq[2*i+1];
//                         pq[2*i+1]=temp;
//                         i=2*i+1;
//                     }
//                     else  //right xhild is max
//                     {
//                        int temp =pq[i];
//                         pq[i]=pq[2*i+2];
//                         pq[2*i+2]=temp;
//                         i=2*i+2; 
//                     }
//                 }
//             }
//         }
        
        
        
//         return ans;
//     }
// };