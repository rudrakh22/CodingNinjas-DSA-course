#include<iostream>
using namespace std;
void DFS(int **edges,int n,int start,bool*visited){
    visited[start]=true;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[start][i]){
            DFS(edges,n,i,visited);
        }
    }
}
int Island(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(edges,n,i,visited);
            count++;
        }
    }
    return count;
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
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
    cout<<Island(edges,n);
}