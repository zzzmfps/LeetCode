// 40ms, 99.75%; 9.9MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<int> diStringMatch(const string &S)
    {
        int size = S.size();
        vector<int> res;
        res.resize(size + 1);
        for (int i = 0; i <= size; ++i) res[i] = i;
        int i = S.find('D');
        while (i != string::npos) {
            int j = S.find('I', i + 1);
            if (j == string::npos) j = size;
            reverse(res.begin() + i, res.begin() + j + 1);
            if (j == size) break;
            i = S.find('D', j + 1);
        }
        return res;
    }
};
