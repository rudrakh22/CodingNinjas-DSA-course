#include<iostream>
#include<climits>
using namespace std;
//brute force
int minCostPath(int **input,int m,int n,int i,int j){
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    int x=minCostPath(input,m,n,i+1,j);
    int y=minCostPath(input,m,n,i,j+1);
    int z=minCostPath(input,m,n,i+1,j+1);
    int ans=min(x,min(y,z))+input[i][j];
    return ans;
    }
int minCostPath(int **input, int m, int n){
return minCostPath(input,m,n,0,0);
}
//Memoization
int minCostPath_mem(int **input,int m,int n,int i,int j,int **output){
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(output[i][j] != -1){
        return output[i][j];
    }
    int x=minCostPath_mem(input,m,n,i+1,j,output);
    int y=minCostPath_mem(input,m,n,i+1,j+1,output);
    int z=minCostPath_mem(input,m,n,i,j+1,output);
    int ans=min(x,min(y,z))+input[i][j];
    output[i][j]=ans;
    return ans;
}
int minCostPath_mem(int ** input,int m,int n){
    int **output=new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
        output[i][j]=-1;
    }
    }
    return minCostPath_mem(input,m,n,0,0,output);
}
//dynamic programming
int minCostPath_dp(int **input,int m,int n){
    int ** output=new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
    }
    output[m-1][n-1]=input[m-1][n-1];
    for(int j=n-2;j>=0;j--){
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }
    for(int i=m-2;i>=0;i--){
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=min(output[i+1][j+1],min(output[i+1][j],output[i][j+1]))+input[i][j];
        }
    }
    return output[0][0];
    }
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}

// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1