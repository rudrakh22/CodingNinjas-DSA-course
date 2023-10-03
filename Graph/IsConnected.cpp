#include<iostream>
#include<queue>
using namespace std;
bool isConnected(int **edges,int n,int start){
    bool *visited=new bool[n];
    for (int i = 0; i < n ;i++) {
        visited[i]=false;
    }
    queue<int> pendingNodes;
    pendingNodes.push(start);
    visited[start]=true;
    while(!pendingNodes.empty()){
        int front=pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<n;i++){
        if(edges[front][i] && !visited[i] && front !=i){
            pendingNodes.push(i);
            visited[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int *[n];
    for(int i=0;i<n;i++){
        edges[i]=new int [n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    if(isConnected(edges,n,0)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}