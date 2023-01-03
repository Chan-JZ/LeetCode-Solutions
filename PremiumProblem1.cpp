Hashset
We sort the string by their sizes, and process them smaller to larger. Our hashset initially contains an empty string. When processing a string, we first check if the prefix is already in the hash set (e.g. "appl" for "apple"). If so, we add the current string to the hash set.

C++ (84 ms)

string longestWord(vector<string>& words) {
    sort(begin(words), end(words), [](auto &a, auto &b){ return a.size() < b.size(); });
    unordered_set<string> s{""};
    string res;
    for (auto &w : words)
        if (s.count(w.substr(0, w.size() - 1))) {
            s.insert(w);
            if (res.size() < w.size() || w < res)
                res = w;
        }
    return res;
}

Trie
This is similar to the hashset approach above, but the logic to store and check prefixes is now incorporated into the Trie implementation.

struct Trie {
    Trie* ch[26] = {};
    bool insert(string &s, int i = 0) {
        if (i + 1 == s.size()) {
            ch[s[i] - 'a'] = new Trie();
            return true;
        }
        return ch[s[i] - 'a'] == nullptr ? false : ch[s[i] - 'a']->insert(s, i + 1);
    }
};
string longestWord(vector<string>& words) {
    Trie trie;
    sort(begin(words), end(words), [](auto &a, auto &b){ return a.size() < b.size(); });
    string res;
    for (auto &w : words)
        if (trie.insert(w))
            if (res.size() < w.size() || w < res)
                res = w;
    return res;    
}

Template Trie problem, we first save all the words into trie
then we search every word, if all words' prefix can be found in trie, we save the longer or same length lexicographically smallest one

class Solution {
    Trie root = new Trie();
    String res = "";
    public String longestWord(String[] words) {
        for (String word : words) addWord(word);
        for (String word : words) searchPrefix(word);
        return res;
    }
    
    private void searchPrefix(String word) {
        Trie cur = root;
        for (char c : word.toCharArray()) {
            cur = cur.children[c];
            if (!cur.isWord) return;
        }
        if (res.length() < word.length() ||
            res.length() == word.length() && res.compareTo(word) > 0) res = word;
    }
    
    private void addWord(String word) {
        Trie cur = root;
        for(char c : word.toCharArray()) {
            if (cur.children[c] == null) cur.children[c] = new Trie();
            cur = cur.children[c];
        }
        cur.isWord = true;
    }
}
class Trie {
    Trie[] children = new Trie[128];
    boolean isWord;
}