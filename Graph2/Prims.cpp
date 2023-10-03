#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int findMinVertex(vector<int> &weights,vector<bool> &visited,int v){
    int minVertex=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (minVertex==-1 || weights[i]<weights[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(vector<vector<int>> &edges,int v){
    vector<int> parent(v);
    vector<int> weights(v,INT_MAX);
    vector<bool> visited(v,false);
    parent[0]=-1;
    weights[0]=0;
    for(int i=0;i<v-1;i++){
        int minVertex=findMinVertex(weights,visited,v);
        visited[minVertex]=true;
        for(int j=0;j<v;j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j]<weights[j]){
                    weights[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<v;i++){
        cout<<min(parent[i],i) <<" "<<max(parent[i],i)<<" "<<weights[i]<<endl;
    }
}
int main(){
int v,e;
cin>>v>>e;
vector<vector<int>> edges(v,vector<int>(v,0));
for(int i=0;i<e;i++){
    int s,d,weight;
    cin >>s>> d>> weight ;  
    edges[s][d]=weight;
    edges[d][s]=weight;
}
prims(edges,v);
}