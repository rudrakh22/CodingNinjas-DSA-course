#include <iostream>
using namespace std;
#include<vector>
int findMaxSquareWithAllZeros(int **arr, int row, int col) {
vector<vector<int>>dp(row,vector<int>(col,0));
int ans=0;
for(int j=0;j<col;j++){
    dp[0][j]=(arr[0][j] ==0) ?0 :1;
    ans=max(ans,dp[0][j]);
}
for(int i=1;i<row;i++){
    dp[i][0]=(arr[i][0] ==0) ?0 :1;
    ans=max(ans,dp[i][0]);
}
for(int i=1;i<row;i++){
    for(int j=1;j<col;j++){
        if(arr[i][j] ==1){
            dp[i][j]=0;
        }
        else{
            dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
        }
        ans=max(ans,dp[i][j]);
    }
}
return ans;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}

