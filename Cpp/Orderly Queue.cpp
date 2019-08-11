// 4ms, 80.00%; 8.9MB, 100.00%
class Solution
{
public:
    string orderlyQueue(string S, int K)
    {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        int idx = distance(S.begin(), min_element(S.begin(), S.end()));
        char _min = S[idx];
        string res = string(S.size(), 'z');
        while (true) {
            res = min(res, S.substr(idx) + S.substr(0, idx));
            idx = S.find(_min, idx + 1);
            if (idx == string::npos) break;
        }
        return res;
    }
};
