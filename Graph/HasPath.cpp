#include<iostream>
using namespace std;
bool hasPath(int**edges,int n,int a,int b,bool*visited){
    if(a==b){
        return true;
    }
    visited[a]=true;
    for(int i=0;i<n;i++){
        if(edges[a][i] && !visited[i]){
            if(hasPath(edges,n,i,b,visited)){
                return true;
            }
        }
    }
    return false;
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
        int x,y;
        cin>>x>>y;
        edges[x][y]=1;
        edges[y][x]=1;
    }
    bool* visited=new bool [n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int a,b;
    cin>>a>>b;
    cout<<(hasPath(edges,n,a,b,visited)) ? "true" : "false";
    delete [] visited;
    for(int i=0;i<n;i++){
        delete[]edges[i];
    }
    delete[] edges;
}