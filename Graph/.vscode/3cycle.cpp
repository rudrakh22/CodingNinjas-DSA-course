#include<iostream>
using namespace std;
int getCycle(bool ** edges,int n){
    int cycle=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(edges[i][j] && edges[j][k] && edges[k][i]){
                    cycle++;
                }
            }
        }
    }
    return cycle;
}
int main(){
    int n,e;
    cin>>n>>e;
    bool** edges=new bool*[n];
    for(int i=0;i<n;i++){
        edges[i]=new bool[n]();
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=true;
        edges[b][a]=true;
    }
    cout<<getCycle(edges,n);
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
}