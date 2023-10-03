#include<bits/stdc++.h>
using namespace std;
vector<string> crossWord(10);
vector<string> words;
bool flag;
void puzzle(int ind){
    if(!flag){
        return;
    }
    if(ind==words.size()){
        if(flag){
            for(auto word:crossWord){
                cout<<word<<endl;
            }
            flag=false;
        }
        return;
    }
    int i,j,p,q,k;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            p=i;q=j;
            for(k=0;k<words[ind].size() && p+k<10;k++){
                if(crossWord[p+k][q] != '-' && crossWord[p+k][q] != words[ind][k]){
                    break;
                }
            }
            if(k==words[ind].size()){
                vector<string> temp=crossWord;
                for(k=0;k<words[ind].size();k++){
                    crossWord[p+k][q]=words[ind][k];
                }
                puzzle(ind+1);
                crossWord=temp;
            }
            for(k=0;k<words[ind].size() && q+k<10;k++){
                if(crossWord[p][q+k] != '-' && crossWord[p][q+k]!=words[ind][k]){
                    break;
                }
            }
            if(k==words[ind].size()){
                vector<string> temp=crossWord;
                for(k=0;k<words[ind].size();k++){
                    crossWord[p][q+k]=words[ind][k];
                }
                puzzle(ind+1);
                crossWord=temp;
            }
        }
    }
}

int main(){
    flag=true;
    int i,j;
    for(int i=0;i<10;i++){
        cin>>crossWord[i];
    }
    string s,w;
    cin>>w;
    for(auto x :w){
        if(x==';'){
            words.push_back(s);
            s="";
        }
        else{
            s+=x;
        }
    }
        words.push_back(s);
        puzzle(0);
}