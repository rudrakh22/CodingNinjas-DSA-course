#include<iostream>
#include<queue>
using namespace std;
void bfs(int **edges,int n,int sv,bool *visited){
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv]=true;
    while(!pendingNodes.empty()){
        int curr=pendingNodes.front();
        pendingNodes.pop();
        cout<<curr<<" ";
        for(int i=0;i<n;i++){
            if(i==curr){
                continue;
            }
            if(edges[curr][i]==1 && !visited[i]){
                pendingNodes.push(i);
                visited[i]=true;
            }
        }
    }
}
void dfs(int **edges,int n,int sv,bool* visited){
    cout<<sv<<" ";
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1 && !visited[i]){
            dfs(edges,n,i,visited);
        }
    }
}
void BFS(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(edges,n,i,visited);
        }
    }
    delete[] visited;
}
void DFS(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(edges,n,i,visited);
        }
    }
    delete[] visited;
}
int main(){
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    cout<<"DFS"<<endl;
    DFS(edges,n);
    cout<<"BFS"<<endl;
    cout<<endl;
    BFS(edges,n);
    }