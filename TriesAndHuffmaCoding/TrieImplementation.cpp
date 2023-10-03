#include<iostream>

using namespace std;
class TrieNode{
    public:
char data;
TrieNode** children;
bool isTerminal;
public:
TrieNode(char data){
    this->data=data;
    children=new TrieNode*[26];
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    isTerminal=false;
}
};
class Trie{
    TrieNode*root;
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insertWord(string word, TrieNode* root ) {
    if(word.size()==0){
        root->isTerminal=true;
        return;
    }
    int index=word[0]-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        child=new TrieNode(word[0]);
        root->children[index]=child;
    }
    insertWord(word.substr(1),child);
    }
    void insertWord(string word){
        insertWord(word,root);
    }
    bool search(string word,TrieNode* root){
        if(word.size()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return search(word.substr(1),child);
    }
    bool search(string word){
        return search(word,root);
    }
    void removeWord(TrieNode* root,string word){
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }
        TrieNode* child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return;
        }
        removeWord(child,word.substr(1));
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void removeWord(string word){
        removeWord(root,word);
    }
};
int main() {
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    cout<<t.search("and")<<endl;
    t.removeWord("and");
    cout<<t.search("and")<<endl;
    return 0;
}