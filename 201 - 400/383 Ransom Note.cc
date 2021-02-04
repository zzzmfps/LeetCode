// 43ms, 18.40%
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map_maga;
        for (auto m : magazine)
            if (map_maga.find(m) != map_maga.end())
                map_maga[m] += 1;
            else
                map_maga.insert(make_pair(m, 1));
        for (auto r : ransomNote)
            if (map_maga.find(r) != map_maga.end())
                if (map_maga[r] == 1)
                    map_maga.erase(r);
                else
                    map_maga[r] -= 1;
            else
                return false;
        return true;
    }
};
