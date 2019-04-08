// 4ms, 100.00%; 8.7MB, 96.49%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool isLongPressedName(const string &name, const string &typed)
    {
        int idx = 0;
        for (auto n : name) {
            int tmp = typed.find(n, idx);
            if (tmp == string::npos) return false;
            idx = tmp + 1;
        }
        return true;
    }
};
