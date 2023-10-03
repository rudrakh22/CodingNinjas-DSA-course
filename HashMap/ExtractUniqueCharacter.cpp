#include <iostream>
#include <string>
using namespace std;
#include <unordered_set>

// string uniqueChar(string str) {
// unordered_map<char,int>p;
// string s;
// for(int i=0;i<str.length();i++){
//     if(p.count(str[i])==0){
//         s.push_back(str[i]);
//         p[str[i]]++;
//     }
// }
// return s;
// }
string uniqueChar(string str)
{
    unordered_set<char> p;
    string s;
    for (char i : str)
    {
        if (p.find(str[i]) == p.end())
        {
            s.push_back(i);
            p.insert(i);
        }
    }
    // .find() The function returns an iterator or a constant iterator which refers to the position where the key is present in the map.If the key is not 
    // present in the map container, it returns an iterator or a constant iterator which refers to map.end().
}
int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}