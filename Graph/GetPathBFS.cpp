#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>* getPath(int **edges,int n,int start,int end,bool *visited){
    queue<int> pendingNodes;
    vector<int> parent(n,-1);
    bool hasPath=false;
    pendingNodes.push(start);
    visited[start]=true;
    while(!pendingNodes.empty() && !hasPath){
        int front=pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<n;i++){
            if(edges[front][i] && !visited[i]){
                parent[i]=front;
                pendingNodes.push(i);
                visited[i]=true;
            if(i==end){
                hasPath=true;
                break;
            }
            }
        }
    }
    if(!hasPath){
        return NULL;
    }
    vector<int>*output=new vector<int>();
    int current=end;
    output->push_back(end);
    while(current != start){
        current=parent[current];
        output->push_back(current);
    }
    return output;
}
int main(){
int n,e;
cin>>n>>e;
int**edges=new int*[n];
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
bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
int start,end;
cin>>start>>end;
vector<int>*output=getPath(edges,n,start,end,visited);
if(output !=NULL){
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<" ";
    }
    delete output;
}
for(int i=0;i<n;i++){
    delete [] edges[i];
}
delete [] edges;
delete [] visited;
}