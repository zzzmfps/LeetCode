// 22ms, 26.43%
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> tmp;
        for(auto x : s)
            if(tmp.find(x) == tmp.end()) tmp[x] = 1;
            else tmp[x] += 1;
        for(auto y : t)
            if(tmp.find(y) == tmp.end()) return false;
            else if(tmp[y] > 1) tmp[y] -= 1;
            else tmp.erase(y);
        return tmp.empty();
    }
};
