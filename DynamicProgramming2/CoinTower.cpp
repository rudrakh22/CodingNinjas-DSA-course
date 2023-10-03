#include <iostream>
#include <string>
#include<vector>
using namespace std;
string findWinner(int n, int x, int y) {
    int*dp=new int[n+1];
    dp[1]=true;
    for(int i=2;i<=n;i++){
        if(i-1 >=0 && !dp[i-1]){
            dp[i]=true;
        }
        else if(i-x>=0 && !dp[i-x]){
            dp[i]=true;
        }
        else if(i-y>=0 && !dp[i-y]){
            dp[i]=true;
        }
        else{
            dp[i]=false;
        }
    }
    if(dp[n]){
        return "A";
    }
    else{
        return "B";
    }
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}