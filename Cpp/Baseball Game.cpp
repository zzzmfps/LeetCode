// 0ms, 100.00%; 9.2MB, 100.00%
class Solution
{
public:
    int calPoints(const vector<string> &ops)
    {
        vector<int> scores;
        scores.reserve(ops.size());
        for (auto &v : ops) {
            int end = scores.size() - 1;
            switch (v[0]) {
                case 'D': scores.push_back(scores[end] * 2); break;
                case 'C': scores.pop_back(); break;
                case '+': scores.push_back(scores[end - 1] + scores[end]); break;
                default: scores.push_back(stoi(v)); break;
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
