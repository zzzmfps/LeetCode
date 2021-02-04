// 35ms, 45.80%
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, multiset<string>> mp;
        for(auto s : strs)
        {
            string t = strSort(s);
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for(auto m : mp)
        { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }

private:
    string strSort(const string &s)
    {
        int count[26] = {0}, n = s.length();
        for(int i = 0; i < n; ++i)
            ++count[s[i] - 'a'];
        string t(n, 'a');
        for(int i = 0, p = 0; p < n; ++i)
            for(int j = 0; j < count[i]; ++j)
                t[p++] += i;
        return t;
    }
};
