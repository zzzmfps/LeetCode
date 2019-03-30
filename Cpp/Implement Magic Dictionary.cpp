// 4ms, 100.00%; 9.3MB, 75.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class MagicDictionary
{
private:
    unordered_map<int, vector<string>> umap;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    /** Build a dictionary through a list of words */
    void buildDict(const vector<string> &dict)
    {
        for (const auto &str : dict) umap[str.size()].push_back(str);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(const string &word)
    {
        int size = word.size();
        if (umap.find(size) == umap.end()) return false;
        for (const auto &str : umap[size])
            if (check(word, str)) return true;
        return false;
    }

private:
    bool check(const string &x, const string &y)
    {
        bool flag = false;
        for (int i = 0, size = x.size(); i < size; ++i) {
            if (x[i] == y[i]) continue;
            if (flag) return false;
            flag = true;
        }
        return flag;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
