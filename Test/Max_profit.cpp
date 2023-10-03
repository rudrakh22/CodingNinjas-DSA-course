#include <iostream>
using namespace std;
#include <algorithm>
int maximumProfit(int budget[], int n)
{
    sort(budget,budget+n);
    int max_profit=budget[0]*n;
    for(int i=1;i<n;i++){
        if(budget[i]*(n-i)>max_profit){
            max_profit=budget[i]*(n-i);
        }
    }
    return max_profit;
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];

    cout << maximumProfit(input, n) << endl;

}
// 4
// 30 20 53 14