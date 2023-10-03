#include <iostream>
using namespace std;
// vs code error
// int helper(int a,int b,int num){
//     if(a==pow(num,b)){
//         return 1;
//     }
//     if(a<pow(num,b)){
//         return 0;
//     }
//     int x=helper(a-pow(num,b),b,num+1);
//     int y=helper(a,b,num+1);
//     return x+y;
// }
// int getAllWays(int a,int b){
// return helper(a,b,1);
// }
int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int smallAns=power(a,b/2);
    return smallAns*smallAns*power(a,b%2);
}
int getAllWaysHelper(int a,int b,int currNum,int currSum){
    int result=0;
    int p=power(currNum,b);
    while(p+currSum < a){
        result+=getAllWaysHelper(a,b,currNum+1,currSum+p);
        currNum++;
        p=power(currNum,b);
    }
    if(currSum+p==a){
        result++;
    }
    return result;
}

int getAllWays(int a,int b){
    return getAllWaysHelper(a,b,1,0);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}