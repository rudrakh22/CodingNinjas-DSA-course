#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    void print(TrieNode* root,string word){
        if(root==NULL){
            return;
        }
        if(root->isTerminal){
            cout<<word<<endl;
        }
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                string t=word+root->children[i]->data;
                print(root->children[i],t);
            }
        }
    }
    void autoComplete(TrieNode* root,string pattern,string output){
        if(root==NULL){
            return;
        }
        if(pattern.size()==0){
            if(root->isTerminal){
                cout<<output<<endl;
            }
            for(int i=0;i<26;i++){
                if(root->children[i] != NULL){
                    string s=output+root->children[i]->data;
                    print(root->children[i],s);
                }
            }
            return;
        }
        int index=pattern[0]-'a';
        output+=pattern[0];
        autoComplete(root->children[index],pattern.substr(1),output);
        }
    void autoComplete(vector<string> input, string pattern) {
        for(int i=0;i<input.size();i++){
            insertWord(input[i]);
        }
        autoComplete(root,pattern,"");
    }
};
int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}