#include <iostream>
#include <vector>
using namespace std;
bool checker(vector<vector<char>> &board,int n,int m,int i ,int j,string s,bool** visited){
    if(s.length()==0){
        return true;
    }
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    int row_matrix[]={i-1,i,i+1};
    int col_matrix[]={j-1,j,j+1};
    for(int p=0;p<3;p++){
        for (int q = 0;q<3;q++) {
            if(row_matrix[p]==i && col_matrix[q]==j){
                continue;
            }
            int row=row_matrix[p];
            int col=col_matrix[q];
            if(row<0 || col <0 || row>=n || col>=m){
                continue;
            }
            if(board[row][col]==s[0] && !visited[row][col]){
                visited[row][col]=true;
                bool checked=checker(board,n,m,row,col,s.substr(1),visited);
                if(checked){
                    return checked;
                }
                else{
                    visited[row][col]=false;
                }
            }
        }
    }
    return false;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
string s="CODINGNINJA";
bool** visited=new bool*[n];
for(int i=0;i<n;i++){
    visited[i]=new bool[m];
    for(int j=0;j<m;j++){
        visited[i][j]=false;
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(board[i][j]=='C'){
        if(checker(board,n,m,i,j,"ODINGNINJAS",visited)){
            return true;
            }
        }
    }
}
return false;
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

    cout << (hasPath(board, n, m) ? 1 : 0);
}