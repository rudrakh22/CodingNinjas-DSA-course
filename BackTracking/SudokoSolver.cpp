#include<bits/stdc++.h>
using namespace std;
bool check(int board[][9],int i,int j,int val){
for(int k=0;k<9;k++){
    if(board[i][k]==val){
        return false;
    }
    if(board[k][j]==val){
        return false;
    }}
    int rowIndex=i-i%3;
    int colIndex=j-j%3;
    for(int c=rowIndex;c<rowIndex+3;c++){
        for(int d=colIndex;d<colIndex+3;d++){
            if(board[c][d]==val){
                return false;
            }
        }
    }
    return true;
}
bool helper(int board[][9],int i,int j){
    if(i==9){
        return true;
    }
    if(j==9){
        return helper(board,i+1,0);
    }
    if(board[i][j] != 0){
        return helper(board,i,j+1);
    }
    for(int k=1;k<=9;k++){
        if(check(board,i,j,k)){
            board[i][j]=k;
            if(helper(board,i,j+1)){
                return true;
            }
        }
            board[i][j]=0;
    }
        return false;
}
bool sudokuSolver(int board[][9]){
    return helper(board,0,0);
}
int main(){
int board[9][9];
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cin>>board[i][j];
    }
}
if(sudokuSolver(board)){
    cout<<"true"<<endl;
}
else{
    cout<<"false";
}
}