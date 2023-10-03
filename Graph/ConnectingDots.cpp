#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>> &board,vector<vector<bool>> &visited,int x,int y,int fromX,int fromY,char color,bool &found,int n,int m){
    if(x<0 || y<0 || x>=n || y>=m){
        return ;
    }
    if(board[x][y] != color){
        return;
    }
    if(visited[x][y]){
        found=true;
        return ;
    }
    visited[x][y]=true;
    int row[]={1,-1,0,0};
    int col[]={0,0,1,-1};
    for(int i=0;i<4;i++){
        int nextX=x+row[i];
        int nextY=y+col[i];
        if(nextX==fromX && nextY==fromY){
            continue;
        }
        dfs(board,visited,nextX,nextY,x,y,color,found,n,m);
    }
}
bool hasCycle(vector<vector<char>> &board,int n,int m){
    bool found=false;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                dfs(board,visited,i,j,-1,-1,board[i][j],found,n,m);
            }
        }
    }
    return found;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}