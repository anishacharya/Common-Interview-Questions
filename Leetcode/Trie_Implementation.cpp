class TrieNode 
{
    // Initialize your data structure here.
public:
    map<char, TrieNode* > Children;
    bool EOS;
    
    TrieNode() 
    {
        map<char, TrieNode* > Children;
        bool EOS = false;
    }
};

class Trie 
{
public:
    Trie() 
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        TrieNode* current = root;

        for(int i=0; i < word.length(); i++)
        {
           char ch = word[i];
           auto it = current->Children.find(ch);
           
           if(it == current->Children.end())
           {
               TrieNode* node = new TrieNode();
               current->Children[ch] = node;
               current = node;
           }
           
           else { current = it->second; }
        }
        current->EOS = true;       
    }
    
    // Returns if the word is in the trie.
    bool search(string word) 
    {
        TrieNode* current = root; 
        
        for(int i=0; i < word.length(); i++)
        {
            char ch = word[i];
            if(current->Children.empty())
                return false;
            auto it = current->Children.find(ch);
            if(it == current->Children.end())
                return false;
            current = it->second;   
        }
        return current->EOS;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        cout<<"Failed Here" <<endl;
        
        TrieNode* current = root;
        for(int i=0; i < prefix.length(); i++)
        {
            char ch = prefix[i];
            auto it = current->Children.find(ch);
            if(it == current->Children.end())
                return false;
            current = current->Children[ch];    
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
vector<string> Trie::all_prefixes() {
    vector<string> results;
    if (flag)
        results.push_back(value);

    if (children.size()) {
        map<char, Trie>::iterator iter;
        vector<string>::iterator node;
        for(iter = children.begin(); iter != children.end(); iter++) {
            vector<string> nodes = iter->second.all_prefixes();
            results.insert(results.end(), nodes.begin(), nodes.end());
        }
    }
    return results;
}

vector<string> Trie::autocomplete(const string &prefix) {
    Trie * node = this;
    vector<string> results;
    for (int i = 0; i < prefix.length(); i++) {
        const char c = prefix[i];
        if (node->children.find(c) == node->children.end())
            return results;
        else 
            node = &node->children[c];
    }
    return node->all_prefixes();
}
