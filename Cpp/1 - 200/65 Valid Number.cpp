// 8ms, 100.0%; 8.3MB, 98.41%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool isNumber(const string &s)
    {
        if (s.empty()) return false;
        int x = s.find_first_not_of(' '), y = s.find_last_not_of(' ');
        if (x == string::npos) return false;
        string str = s.substr(x, y - x + 1);
        int idx = str.find('e');
        if (idx == string::npos) return isFraction(str);
        return isFraction(str.substr(0, idx)) && isInteger(str.substr(idx + 1));
    }

private:
    bool isInteger(string s)
    {
        if (s.empty() || s.find(' ') != string::npos) return false;
        int idx = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        if (s.size() == idx) return false;
        for (int size = s.size(); idx < size; ++idx)
            if (s[idx] < '0' || s[idx] > '9') return false;
        return true;
    }

    bool isFraction(string s)
    {
        if (s.empty() || s.find(' ') != string::npos || s.find_first_not_of(".+-") == string::npos) return false;
        int idx = s.find('.'), size = s.size();
        if (idx == string::npos) return isInteger(s);
        if (idx > 0) {
            int i = (s[0] == '+' || s[0] == '-') ? 0 : -1;
            while (++i < idx)
                if (s[i] < '0' || s[i] > '9') return false;
        }
        while (++idx < size)
            if (s[idx] < '0' || s[idx] > '9') return false;
        return true;
    }
};
