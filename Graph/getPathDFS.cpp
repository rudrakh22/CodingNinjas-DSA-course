#include<iostream>
#include<vector>
using namespace std;
vector<int>* getPath(bool**edges,int n,int start,int end,bool* visited){
    if(start==end){
        vector<int>*output=new vector<int>();
        output->push_back(end);
        return output;
    }
    visited[start]=true;
    for(int i=0;i<n;i++){
        if(edges[start][i] && !visited[i]){
            vector<int>*smallAns=getPath(edges,n,i,end,visited);
            if(smallAns != NULL){
                smallAns->push_back(start);
                return smallAns;
            }
        }
    }
    return NULL;
}
vector<int>* getDFSPath(bool**edges,int n,int start,int end){
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    vector<int>* output=getPath(edges,n,start,end,visited);
    delete[] visited;
    return output;
}
int main(){
int n,e;
cin>>n>>e;
bool**edges=new bool*[n];
for(int i=0;i<n;i++){
    edges[i]=new bool[n];
    for(int j=0;j<n;j++){
        edges[i][j]=false;
    }
}
for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    edges[a][b]=true;
    edges[b][a]=true;
}
int start,end;
cin>>start>>end;
vector<int>* output=getDFSPath(edges,n,start,end);
if(output != NULL){
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<" ";
    }
    delete output;
}
for(int i=0;i<n;i++){
    delete[] edges[i];
}
delete[] edges;
}