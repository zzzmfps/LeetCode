// 37ms, 71.52%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size(), p_size = p.size();
        if(s_size < p_size) return vector<int>();
        
        vector<int> sv(26, 0), pv(26, 0), res;
        for(int i = 0; i < p_size; ++i) {
            ++sv[s[i] - 'a'];
            ++pv[p[i] - 'a'];
        }
        if(sv == pv) res.push_back(0);

        for(int i = p_size; i < s_size; ++i) {
            ++sv[s[i] - 'a'];
            --sv[s[i - p_size] - 'a']; 
            if(sv == pv) res.push_back(i - p_size + 1);
        }
        return res;
    }
};
