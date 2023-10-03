#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
vector<int> col;
vector<bool> leftDiag;
vector<bool> rightDiag;
vector<vector<int>> ans;
void solve(int row,int n){
for(int i=0;i<n;i++){
    if(leftDiag[row+i] || rightDiag[i-row+n-1] || col[i] != -1){
        continue;}
        col[i]=row;
        leftDiag[row+i]=true;
        rightDiag[i-row+n-1]=true;
        if(row+1==n){
            vector<int> temp;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    temp.push_back(col[k]==j);
                }
            }
            ans.push_back(temp);
        }
        else{
            solve(row+1,n);
        }
        col[i]=-1;
        leftDiag[row+i]=false;
        rightDiag[i-row+n-1]=false;
    }
}

vector<vector<int>> nQueens(int n){
col=vector<int>(n,-1);
leftDiag=vector<bool>(2*n+1,false);
rightDiag=vector<bool>(2*n+1,false);
solve(0,n);
return ans;
}
class Runner
{
    int n;

public:
    
    void takeInput()
    {
        cin >> n;
    }
    void execute()
    {
        auto ans = nQueens(n);
    }
    void executeAndPrintOutput()
    {
        auto ans = nQueens(n);
        if(ans.size())
        {
            sort(ans.begin(),ans.end());
            for(auto v:ans)
            {
                for(auto i:v)cout << i << " ";
                cout << endl;
            }
        }
        else cout << "\'No Configuration\'";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}



