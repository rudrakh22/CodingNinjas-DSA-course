#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> v;//static
// vector<int> *vp=new vector<int>();//dynamic
for(int i=0;i<100;i++){
   cout<<"Capacity= "<<v.capacity()<<endl;
   cout<<"Size= "<<v.size()<<endl;
   v.push_back(i+1);
   cout<<v.size()<<endl;
}
v.push_back(10);
v.push_back(20);
v.push_back(30);
v[1]=100;
// v[3]=1002;
// v[4]=1234;// sometime give error because we cannot edit items beyond the size of vector
//so to avoid these use  pushback function because it create extra memory when size is full
//throw semantic error
v.push_back(23);
v.push_back(234);

// cout<<v[0]<<endl;
// cout<<v[1]<<endl;
// cout<<v[2]<<endl;
// cout<<v[3]<<endl;
// cout<<v[4]<<endl;
// cout<<v[5]<<endl;
// cout<<v[6]<<endl;
// cout<<v.size()<<endl;
// cout<<v.at(2)<<endl;
// cout<<v.at(6)<<endl;//out of range
v.pop_back();
// for(int i=0;i<v.size();i++){
//     cout<<v[i]<<endl;
// }


}
// [] -> for get and update