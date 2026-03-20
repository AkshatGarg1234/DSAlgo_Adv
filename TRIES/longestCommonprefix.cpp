class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount=0;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        childCount=0;
    }
};

class Trie {
    public:
    TrieNode * root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
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
            root->childCount++;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childCount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else break;
            if(root->isTerminal==true) break;
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie * t=new Trie();
        for(int i=0;i<strs.size();i++){
            t->insertWord(strs[i]);
        }
        for(string s : strs) if(s.empty()) return "";
        string first=strs[0];
        string ans="";
        t->lcp(first,ans);
        return ans;
    }
};