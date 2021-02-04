// 7ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  private:
    stack<int> nums;
    stack<char> ops;

  public:
    int calculate(const string &s)
    {
        int res = 0, sign = 1, num = 0;
        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
                num = num * 10 + c - '0';
            else
            {
                res += sign * num;
                num = 0;
                if (c == '+')
                    sign = 1;
                else if (c == '-')
                    sign = -1;
                else if (c == '(')
                {
                    nums.push(res);
                    ops.push(sign);
                    res = 0, sign = 1;
                }
                else if (!ops.empty())
                {
                    res = nums.top() + ops.top() * res;
                    nums.pop();
                    ops.pop();
                }
            }
        }
        return res + sign * num;
    }
};
