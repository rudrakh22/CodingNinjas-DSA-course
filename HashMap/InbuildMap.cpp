#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    unordered_map<string, int> ourMap;
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;
    cout << ourMap["abc"] << endl;
    // cout<<"ourMap.at("ghi")<<endl;//it shows exception as "Key Not Found"
    cout << ourMap["ghi"] << endl; // it will create ghi and mark default value as 0
    cout << "Size:" << ourMap.size() << endl;
    // check presence
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    ourMap.erase("ghi");
    cout << "Size:" << ourMap.size();
    // if(ourMap.find("abc")){

    // }


}