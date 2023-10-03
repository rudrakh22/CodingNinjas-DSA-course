#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> BFS(int **edges,int n,int start,bool* visited){
    vector<int> ans;
    queue<int> pendingNodes;
    pendingNodes.push(start);
    visited[start]=true;
    while(!pendingNodes.empty()){
        int front=pendingNodes.front();
        pendingNodes.pop();
        ans.push_back(front);
        for(int i=0;i<n;i++){
            if(edges[front][i] && !visited[i] && start !=i){
                pendingNodes.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
vector<vector<int>> AllConnectedComponent(int **edges,int n){
    bool *visited=new bool[n];
    vector<vector<int>> component;
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> ans=BFS(edges,n,i,visited);
        component.push_back(ans);
        }
    }
    delete [] visited;
    return component;
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
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
    vector<vector<int>>component=AllConnectedComponent(edges,n);
    for(int i=0;i<component.size();i++){
        sort(component[i].begin(),component[i].end());
        for(int j=0;j<component[i].size();j++){
        cout<<component[i][j]<<" ";
        }
        cout<<endl;
    }
    }