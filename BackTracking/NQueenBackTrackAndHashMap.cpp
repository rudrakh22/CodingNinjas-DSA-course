#include<iostream>
#include<vector>
using namespace std;
void helper(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &lowerDiag,vector<int>upperDiag,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiag[row+col]==0 && upperDiag[n-1+col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiag[row+col]=1;upperDiag[n-1+col-row]=1;
            helper(col+1,board,ans,leftRow,lowerDiag,upperDiag,n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiag[row+col]=0;upperDiag[n-1+col-row]=0;
        }
    }
}
vector<vector<string>> nQueens(int n){
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;
    vector<int>leftRow(n,0);
    vector<int>lowerDiag(2*n-1,0);
    vector<int>upperDiag(2*n-1,0);
    helper(0,board,ans,leftRow,lowerDiag,upperDiag,n);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> ans=nQueens(n);
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
