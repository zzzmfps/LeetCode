// 0ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int scoreOfParentheses(const string &str)
    {
        int res = 0, layer = 0;
        for (int i = 0, size = str.size() - 1; i < size; ++i) {
            layer += (str[i] == '(' ? 1 : -1);
            if (str[i] == '(' && str[i + 1] == ')') res += 1 << (layer - 1);
        }
        return res;
    }
};
