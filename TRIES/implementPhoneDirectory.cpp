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
    vector<vector<string>> getSuggest(string str){
        TrieNode *prev=root;
        vector<vector<string>> output;
        string prefix="";
        for(int i=0;i<str.length();i++){
            char lastCh=str[i];
            prefix.push_back(lastCh);
            TrieNode * curr=prev->children[lastCh-'a'];
            if(curr==NULL){
                break;
            }
            vector<string> temp;
            printSuggest(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }
    void printSuggest(TrieNode* curr,vector<string> &temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            TrieNode * next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggest(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t=new Trie();
        for(int i=0;i<contactList.size();i++){
            string str=contactList[i];
            t->insertWord(str);
        }
        return t->getSuggest(queryStr);
}