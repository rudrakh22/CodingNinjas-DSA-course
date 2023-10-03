#include<iostream>
#include<vector>
using namespace std;
bool check(int row,int col,vector<string> &board,int n){
    int x=row;
    int y=col;
    while(y>=0){
        if(board[x][y]=='Q'){
            return false;
        }
        y--;
    }
    x=row;
    y=col;
    while(y>=0 && x>=0){
        if(board[x][y]=='Q'){
            return false;
        }
        x--;y--;
    }
    x=row;
    y=col;
    while(y>=0 && x<n){
        if(board[x][y]=='Q'){
            return false;
        }
        x++;y--;
    }
    return true;
}
void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
    if(col==n){
        ans.push_back(board);
    return;
    }
    for(int row=0;row<n;row++){
        if(check(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            //backtrack
            board[row][col]='.';
        }
    }
}
vector<vector<string>> nQueen(int n){
    vector<string> board(n,string(n,'.'));
    vector<vector<string>>ans;
    solve(0,board,ans,n);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> ans=nQueen(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}